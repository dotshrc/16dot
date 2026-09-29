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

// TODO
i8 op_add(struct cpu *cpu, u16 instr)
{
	u8 dest = (instr >> 8)  & 0xF;
        u8 arg1 = (instr >> 4)  & 0xF;
        u8 arg2 =  instr        & 0xF;
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("add(reg%d, reg%d, reg%d)\n",
			dest, arg1, arg2);
	return 0;
}

// TODO
i8 op_sub(struct cpu *cpu, u16 instr)
{
	u8 dest = (instr >> 8)  & 0xF;
        u8 arg1 = (instr >> 4)  & 0xF;
        u8 arg2 =  instr        & 0xF;
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("sub(reg%d, reg%d, reg%d)\n",
			dest, arg1, arg2);
	return 0;
}

i8 op_and(struct cpu *cpu, u16 instr)
{
	u8 dest = (instr >> 8)  & 0xF;
        u8 arg1 = (instr >> 4)  & 0xF;
        u8 arg2 =  instr        & 0xF;
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("and(reg%d, reg%d, reg%d)\n",
			dest, arg1, arg2);
	return 0;
}

i8 op_slt(struct cpu *cpu, u16 instr)
{
	u8 dest = (instr >> 8)  & 0xF;
        u8 arg1 = (instr >> 4)  & 0xF;
        u8 arg2 =  instr        & 0xF;
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("slt(reg%d, reg%d, reg%d)\n",
			dest, arg1, arg2);
	return 0;
}

i8 op_2arg(struct cpu *cpu, u16 instr)
{
	u8 subop = instr & 0xF;
	u8 arg = (instr >> 4) & 0xF;
	u8 dest = (instr >> 8) & 0xF;

	(void)subop;
	(void)arg;
	switch(subop) {
		// TODO
		case SUBOP_OR:
			log_info_args("or(reg%d, reg%d)\n",
				dest, arg);
			break;
		// TODO
		case SUBOP_XOR:
			log_info_args("xor(reg%d, reg%d)\n",
				dest, arg);
			break;
		// TODO
		case SUBOP_NOT:
			log_info_args("not(reg%d, reg%d)\n",
				dest, arg);
			break;
		// TODO
		case SUBOP_SHL:
			log_info_args("shl(reg%d, reg%d)\n",
				dest, arg);
			break;
		// TODO
		case SUBOP_SHR:
			log_info_args("shr(reg%d, reg%d)\n",
				dest, arg);
			break;
	}
	return 0;
}

i8 op_ctrl(struct cpu *cpu, u16 instr)
{
	u8 subop = instr & 0xF;
	(void)subop;
	switch(subop) {
		case SUBOP_HLT:
			cpu->running = 0;
			log_info("hlt()\n");
			break;

		// TODO
		case SUBOP_TRP:
			log_info("trp()(todo)\n");
			break;

		// TODO
		case SUBOP_XRT:
			log_info("xrt()(todo)\n");
			break;
	}
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
		case OP_ADD:
			op_add(cpu, inst);
			break;
		case OP_SUB:
			op_sub(cpu, inst);
			break;
	
		case OP_AND:
			op_and(cpu, inst);
			break;
		
		case OP_SLT:
			op_slt(cpu, inst);
			break;

		case OP_CTRL:
			op_ctrl(cpu, inst);
			cpu->running = 0;
			break;
		default:
			log_err_args("unknown instruction (at pc %d) "
				"\"0x%04X\"", cpu->reg[REG_PC], opcode);
			return 1;
			
	}
	return 0;
}
