#include "log.h"
#include "type.h"
#include "cpu.h"
#include "isa.h"
#include "instr.h"
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
	if (cpu_load(cpu, pathtoexec) == 1) {
		log_err("failed to load executable");
		return 1;
	}

	return 0;
}

i8 cpu_shutdown(struct cpu *cpu)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	free(cpu->reg);
	free(cpu->mem);

	return 0;
}

i8 cpu_step(struct cpu *cpu) {
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	
	u16 pc = cpu->reg[REG_PC];
	u16 inst = ((u16)cpu->mem[pc] << 8) | cpu->mem[pc + 1];
	cpu->reg[REG_PC] += 2;
	u8 opcode = (inst >> 12) & 0xF;

	printf("pc -> %d\n", cpu->reg[REG_PC]);
	switch (opcode) {
		case OP_NOP:
			break;

		case OP_ADD:
			instr_add(cpu, inst); 
			break;	

		case OP_SUB:
			instr_sub(cpu, inst); 
			break;

		case OP_MUL:
			instr_mul(cpu, inst);
			break;

		case OP_DIV:
			instr_div(cpu, inst);
			break;

		case OP_SLT:
			instr_slt(cpu, inst);
			break;	

		case OP_2OP:
			instr_2op(cpu, inst);
			break;

		case OP_1OP:
			instr_1op(cpu, inst);
			break;

		case OP_LDL:
			instr_ldl(cpu, inst);
			break;

		case OP_LDU:
			instr_ldu(cpu, inst);
			break;	

		case OP_CTR:
			instr_ctr(cpu, inst);
			break;

		case OP_JMP:
			instr_jmp(cpu, inst);
			break;

		default:
			log_err_args("unknown instruction (at pc %d) "
				"\"0x%04X\"", cpu->reg[REG_PC], opcode);
			return 1;
			
	}
	return 0;
}
