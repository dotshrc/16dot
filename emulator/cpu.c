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
	instr_handler *instr_table = 
		calloc(1, 16*sizeof(instr_handler));
	instr_load(instr_table);
	cpu->instr_tab = instr_table;
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
	free(cpu->instr_tab);

	return 0;
}

i8 cpu_step(struct cpu *cpu) {
	if (!cpu) { 
		log_err("invalid pointer argument"); 
		return 1;
	}
	
	u16 pc = cpu->reg[REG_PC];
	u16 inst = ((u16)cpu->mem[pc] << 8) | cpu->mem[pc + 1];
	cpu->reg[REG_PC] += 2;
	u8 opcode = getnib(inst, 0);
	u8 nib1 = getnib(inst, 1);
	u8 nib2 = getnib(inst, 2);
	u8 nib3 = getnib(inst, 3);

	printf("pc -> %d\n", cpu->reg[REG_PC]);
	if (opcode > 15) { 
		log_err_args("invalid instruction "
			"\"0x%04X\"", opcode);
		return 1;
	}
	if (cpu->instr_tab[opcode](cpu, 
		nib1, nib2, nib3) == 1) {
		log_err_args("failed to execute instruction "
			"\"0x%04X\"", opcode);
	}
	//switch (opcode) {
	//	case OP_NOP:
	//		break;

	//	case OP_ADD:
	//		instr_add(cpu, inst); 
	//		break;	

	//	case OP_SUB:
	//		instr_sub(cpu, inst); 
	//		break;

	//	case OP_MUL:
	//		instr_mul(cpu, inst);
	//		break;

	//	case OP_DIV:
	//		instr_div(cpu, inst);
	//		break;

	//	case OP_SLT:
	//		instr_slt(cpu, inst);
	//		break;	

	//	case OP_2OP:
	//		instr_2op(cpu, inst);
	//		break;

	//	case OP_1OP:
	//		instr_1op(cpu, inst);
	//		break;

	//	case OP_LDL:
	//		instr_ldl(cpu, inst);
	//		break;

	//	case OP_LDU:
	//		instr_ldu(cpu, inst);
	//		break;	

	//	case OP_CTR:
	//		instr_ctr(cpu, inst);
	//		break;

	//	case OP_JMP:
	//		instr_jmp(cpu, inst);
	//		break;

	//	default:
	//		log_err_args("unknown instruction (at pc %d) "
	//			"\"0x%04X\"", cpu->reg[REG_PC], opcode);
	//		return 1;
	//		
	//}
	return 0;
}
