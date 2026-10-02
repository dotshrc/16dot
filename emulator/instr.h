#ifndef INSTR_H
#define INSTR_H
#include "type.h"

struct cpu;

typedef i8(*instr_handler)(struct cpu *, u8, u8, u8);
typedef i8(*op2_handler)(struct cpu *, u8, u8);
typedef i8(*op1_handler)(struct cpu *, u8);
typedef i8(*ctr_handler)(struct cpu *);

struct instr_table {
	instr_handler *top_tab;
	op2_handler *op2_tab;
	op1_handler *op1_tab;
	ctr_handler *ctr_tab;
};

i8 instr_table_load(struct instr_table *tab);
i8 instr_table_unload(struct instr_table *tab);
i8 instr_add(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_sub(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_mul(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_div(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_slt(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_2op(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_1op(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_ldl(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_ldu(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_ctr(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);
i8 instr_jmp(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3);

#endif
