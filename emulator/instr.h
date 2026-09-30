#ifndef INSTR_H
#define INSTR_H
#include "type.h"

struct cpu;
typedef i8(*instr_handler)(struct cpu *, u8, u8, u8);
i8 instr_load(instr_handler *tab);
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
