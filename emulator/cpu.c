#include "log.h"
#include "type.h"
#include "cpu.h"
#include "isa.h"
#include <string.h>
#include <stdlib.h>

i8 cpu_load(struct cpu *cpu, const char *path)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	if (!path) 	{ log_err("invalid pointer argument"); return 1; }

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

	return 0;
}

i8 cpu_init(struct cpu *cpu, const char *pathtoexec)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	cpu->reg = calloc(1, REG_MAXSIZE);
	cpu->mem = calloc(1, MEM_MAXSIZE);
	cpu->running = 1;
	cpu_load(cpu, pathtoexec);
	
	return 0;	
}

i8 cpu_shutdown(struct cpu *cpu)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	free(cpu->reg);
	free(cpu->mem);

	return 0;
}

i8 cpu_step(struct cpu *cpu)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	u16 inst = cpu->mem[cpu->reg[REG_PC]++];
	u8 opcode = (inst >> 12) & 0xF;
	/*
	u8 op   = (instr >> 12) & 0xF;
	u8 arg1 = (instr >> 8)  & 0xF;
	u8 arg2 = (instr >> 4)  & 0xF;
	u8 arg3 =  instr        & 0xF;
	i8 imm8 = (i8)(instr & 0xFF);
	*/	
	switch (opcode) {
		case OP_ADD:
			op_add(); // TODO
			break;
		case OP_CTRL:
			op_ctrl(); // TODO
			cpu->running = 0;
			break;
		default:
			log_err_args("unknown instruction (at pc %d) "
					"\"0x%04X\"", cpu->pc, opcode);
			
	}
	return 0;
}
