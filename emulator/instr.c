#include "instr.h"
#include "type.h"
#include "isa.h"
#include "log.h"
#include "cpu.h"

typedef i8(*op2_handler)(struct cpu *, u8, u8);
typedef i8(*op1_handler)(struct cpu *, u8);
typedef i8(*ctr_handler)(struct cpu *);

i8 instr_nop(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(nop)\n");
	return 0;
}

i8 instr_add(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(add)\n");
	return 0;
}

i8 instr_sub(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(sub)\n");
	return 0;
}

i8 instr_mul(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(mul)\n");
	return 0;
}

i8 instr_div(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(div)\n");
	return 0;
}

i8 instr_slt(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(slt)\n");
	return 0;
}

i8 instr_or(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_xor(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_not(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_and(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_loa(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_sto(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_jpz(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_jnz(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_lsr(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_lsl(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_asr(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_asl(struct cpu *cpu, u8 nib1, u8 nib2);
i8 instr_2op(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(2op)\n");
	return 0;
}

i8 instr_jto(struct cpu *cpu, u8 nib1);
i8 instr_psh(struct cpu *cpu, u8 nib1);
i8 instr_pop(struct cpu *cpu, u8 nib1);
i8 instr_cll(struct cpu *cpu, u8 nib1);
i8 instr_1op(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(1op)\n");
	return 0;
}

i8 instr_ldl(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(ldl)\n");
	return 0;
}

i8 instr_ldu(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(ldu)\n");
	return 0;
}

i8 instr_hlt(struct cpu *cpu);
i8 instr_sys(struct cpu *cpu);
i8 instr_xrt(struct cpu *cpu);
i8 instr_trp(struct cpu *cpu);
i8 instr_nnt(struct cpu *cpu);
i8 instr_int(struct cpu *cpu);
i8 instr_drg(struct cpu *cpu);
i8 instr_brk(struct cpu *cpu);
i8 instr_ctr(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	cpu->running = 0; 	// for now, it pauses execution because
				// i'm too lazy to write it all for halt
	
	log_info("TODO(ctr)\n");
	return 0;
}

i8 instr_jmp(struct cpu *cpu, u8 nib1, u8 nib2, u8 nib3)
{
	
	log_info("TODO(jmp)\n");
	return 0;
}

i8 instr_or(struct cpu *cpu, u8 nib1, u8 nib2)
{
	return 0;
}
i8 instr_xor(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_not(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_and(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_loa(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_sto(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_jpz(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_jnz(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_lsr(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_lsl(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_asr(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }
i8 instr_asl(struct cpu *cpu, u8 nib1, u8 nib2) { return 0; }

i8 instr_jto(struct cpu *cpu, u8 nib1) { return 0; }
i8 instr_psh(struct cpu *cpu, u8 nib1) { return 0; }
i8 instr_pop(struct cpu *cpu, u8 nib1) { return 0; }
i8 instr_cll(struct cpu *cpu, u8 nib1) { return 0; }

i8 instr_hlt(struct cpu *cpu) { return 0; }
i8 instr_sys(struct cpu *cpu) { return 0; }
i8 instr_xrt(struct cpu *cpu) { return 0; }
i8 instr_trp(struct cpu *cpu) { return 0; }
i8 instr_nnt(struct cpu *cpu) { return 0; }
i8 instr_int(struct cpu *cpu) { return 0; }
i8 instr_drg(struct cpu *cpu) { return 0; }
i8 instr_brk(struct cpu *cpu) { return 0; }

i8 instr_load(instr_handler *tab)
{
	if (!tab) {
		
		log_err("invalid pointer argument");
		return 1;
	}
	tab[OP_NOP] = instr_nop;
	tab[OP_ADD] = instr_add;
	tab[OP_SUB] = instr_sub;
	tab[OP_MUL] = instr_mul;
	tab[OP_DIV] = instr_div;
	tab[OP_SLT] = instr_slt;
	tab[OP_2OP] = instr_2op;
	tab[OP_1OP] = instr_1op;
	tab[OP_LDL] = instr_ldl;
	tab[OP_LDU] = instr_ldu;
	tab[OP_CTR] = instr_ctr;
	tab[OP_JMP] = instr_jmp;

	return 0;
}

i8 op2_load(op2_handler *tab)
{
	if (!tab) {
		
		log_err("invalid pointer argument");
		return 1;
	}
	tab[SUBOP_OR] = instr_or;
	tab[SUBOP_XOR] = instr_xor;
	tab[SUBOP_NOT] = instr_not;
	tab[SUBOP_AND] = instr_and;
	tab[SUBOP_LOA] = instr_loa;
	tab[SUBOP_STO] = instr_sto;
	tab[SUBOP_JPZ] = instr_jpz;
	tab[SUBOP_JNZ] = instr_jnz;
	tab[SUBOP_LSR] = instr_lsr;
	tab[SUBOP_LSL] = instr_lsl;
	tab[SUBOP_ASR] = instr_asr;
	tab[SUBOP_ASL] = instr_asl;
	return 0;
}

i8 op1_load(op1_handler *tab)
{
	if (!tab) {
		
		log_err("invalid pointer argument");
		return 1;
	}
	tab[SUBOP_JTO] = instr_jto;
	tab[SUBOP_PSH] = instr_psh;
	tab[SUBOP_POP] = instr_pop;
	tab[SUBOP_CLL] = instr_cll;
	return 0;
}

i8 ctr_load(ctr_handler *tab)
{
	if (!tab) {
		
		log_err("invalid pointer argument");
		return 1;
	}
	tab[SUBOP_HLT] = instr_hlt;
	tab[SUBOP_SYS] = instr_sys;
	tab[SUBOP_XRT] = instr_xrt;
	tab[SUBOP_TRP] = instr_trp;
	tab[SUBOP_NNT] = instr_nnt;
	tab[SUBOP_INT] = instr_int;
	tab[SUBOP_DRG] = instr_drg;
	tab[SUBOP_BRK] = instr_brk;
	return 0;
}
