#include <stdio.h>

#include "log.h"
#include "type.h"
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define REG_ZR 0
#define REG_SY 1
#define REG_A0 2
#define REG_A1 3
#define REG_A2 4
#define REG_T0 5
#define REG_T1 6
#define REG_T2 7
#define REG_S0 8
#define REG_S1 9
#define REG_S2 10
#define REG_S3 11
#define REG_GP 12
#define REG_LR 13
#define REG_SP 14
#define REG_PC 15

#define OP_ADD 		0x1
#define OP_SUB 		0x2
#define OP_AND 		0x3
#define OP_SLT 		0x4

#define OP_2ARG 	0x5
#define SUBOP_OR	0x1
#define SUBOP_XOR	0x2
#define SUBOP_NOT	0x3
#define SUBOP_CMP	0x4
#define SUBOP_SHL	0x5
#define SUBOP_SHR	0x6

#define OP_BRNCH	0x6
#define SUBOP_JP	0x1
#define SUBOP_JZ	0x2
#define SUBOP_JNZ	0x3
#define SUBOP_JN	0x4
#define SUBOP_JNN	0x5
#define SUBOP_JC	0x6
#define SUBOP_JNC	0x7

#define OP_1ARG		0x7
#define SUBOP_AJ	0x1
#define SUBOP_CLL	0x2
#define SUBOP_PSH	0x3
#define SUBOP_POP	0x4

#define OP_LDL		0x8
#define OP_LDU		0x9

#define OP_LD		0xA
#define OP_ST		0xB

#define OP_CTRL		0xF
#define SUBOP_HLT	0x0
#define SUBOP_TRP	0x1
#define SUBOP_XRT	0x2

#define OP_NOP		0x0

#define REG_MAXSIZE (16 * sizeof(u16))
#define MEM_MAXSIZE ((1 << 16) * sizeof(u16))

struct cpu {
	u16 *reg;
	u16 *mem;
	u16 svpc;
	u16 pc;
	u8 priv;
	u8 running;
	u8 zero, negative, carry;
};

// takes preinitialized memory for cpu struct
i8 cpu_init(struct cpu *cpu); 
i8 cpu_step(struct cpu *cpu);
i8 cpu_shutdown(struct cpu *cpu); 
i8 cpu_load(struct cpu *cpu, const char *path);


i32 main(i32 argc, char **argv) {
	// cpu_load file
	if (argc < 2) {
		log_err("missing executable argument");
		printf("usage: %s <file>\n", argv[0]);
		return 1;
	}
	if (argc > 2) {
		log_err("too many arguments");
		printf("usage: %s <file>\n", argv[0]);
		return 1;
	}	
	// initialize cpu
	struct cpu cpu = {0};
	if (cpu_init(&cpu) == 1) {
		log_err("failed to initialize cpu");
		return 1;
	}
	cpu_load(&cpu, argv[1]);
	
	// loop
	while (cpu.running) {
		cpu_step(&cpu);
	}


	cpu_shutdown(&cpu);
	
	return 0;
}

i8 cpu_init(struct cpu *cpu)
{
	if (!cpu)	{ log_err("invalid pointer argument"); return 1; }
	cpu->reg = calloc(1, REG_MAXSIZE);
	cpu->mem = calloc(1, MEM_MAXSIZE);
	cpu->running = 1;
	
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
