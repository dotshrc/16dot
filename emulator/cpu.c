#include "log.h"
#include "type.h"
#include "cpu.h"
#include "isa.h"
#include "instr.h"
#include <string.h>
#include <stdlib.h>

#define getnib(instr, i) (((instr) >> ((3 - (i)) * 4)) & 0xF)

i8 cpu_load(struct cpu *cpu, const char *path)
{
	if (!cpu) {
		log_err("invalid pointer argument");
		return 1;
	}
	if (!path) {
		log_err("invalid pointer argument");	
		return 1;
	}

	FILE *f = fopen(path, "rb");
	if (!f) {
		log_err("couldn't open file");
		perror("fopen");
		return 1;
	}

	size_t words = fread(cpu->mem, sizeof(u16), 1 << 16, f);
	if (!words) {
		log_err("couldn't load file");
		perror("fopen");
		return 1;
	}
	fclose(f);
	return 0;
}

i8 cpu_init(struct cpu *cpu, const char *pathtoexec)
{
	if (!cpu) { log_err("invalid pointer argument"); return 1; }
	cpu->reg = calloc(1, REG_MAXSIZE);
	cpu->mem = calloc(1, MEM_MAXSIZE);
	struct instr_table *instr_tab = 
		calloc(1, sizeof(struct instr_table));
	instr_table_load(instr_tab);
	cpu->instr_tab = instr_tab;
	cpu->running = 1;
	if (cpu_load(cpu, pathtoexec) == 1) {
		log_err("failed to load executable");
		return 1;
	}

	return 0;
}

i8 cpu_shutdown(struct cpu *cpu)
{
	if (!cpu) { 
		log_err("invalid pointer argument");
		return 1;
	}
	free(cpu->reg);
	free(cpu->mem);
	instr_table_unload(cpu->instr_tab);
	free(cpu->instr_tab);

	return 0;
}

i8 cpu_step(struct cpu *cpu) {
	if (!cpu) { 
		log_err("invalid pointer argument"); 
		return 1;
	}
	
	u16 pc = cpu->reg[REG_PC];
	u16 ir = ((u16)cpu->mem[pc] << 8) | cpu->mem[pc + 1];
	cpu->reg[REG_PC] += 2;
	u8 opcode = getnib(ir, 0);
	u8 nib1 = getnib(ir, 1);
	u8 nib2 = getnib(ir, 2);
	u8 nib3 = getnib(ir, 3);
	cpu->ir = ir;

	printf("pc -> %d\n", cpu->reg[REG_PC]);
	if (opcode > 15) { 
		log_err_args("invalid irruction "
			"\"0x%04X\"", opcode);
		return 1;
	}
	if (cpu->instr_tab->top_tab[opcode](cpu, 
		nib1, nib2, nib3) == 1) {
		log_err_args("failed to execute irruction "
			"\"0x%04X\"", opcode);
	}	
	return 0;
}
