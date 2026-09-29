#include "instr.h"
#include "type.h"
#include "log.h"
#include "cpu.h"
#define getnib(instr, i) (((instr) >> ((3 - (i)) * 4)) & 0xF)

i8 instr_add(struct cpu *cpu, u16 instr)
{
	u8 arg2 = getnib(instr, 3);
	u8 arg1 = getnib(instr, 2);
	u8 dest = getnib(instr, 1);
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("add(reg%d, reg%d, reg%d)",
			dest, arg1, arg2);
	log_stamp();
	log_info("TODO(add)\n");
	return 0;
}

i8 instr_sub(struct cpu *cpu, u16 instr)
{
	u8 arg2 = getnib(instr, 3);
	u8 arg1 = getnib(instr, 2);
	u8 dest = getnib(instr, 1);
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("sub(reg%d, reg%d, reg%d)",
			dest, arg1, arg2);
	log_stamp();
	log_info("TODO(sub)\n");
	return 0;
}

i8 instr_mul(struct cpu *cpu, u16 instr)
{
	u8 arg2 = getnib(instr, 3);
	u8 arg1 = getnib(instr, 2);
	u8 dest = getnib(instr, 1);
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("mul(reg%d, reg%d, reg%d)",
			dest, arg1, arg2);
	log_stamp();
	log_info("TODO(mul)\n");
	return 0;
}

i8 instr_div(struct cpu *cpu, u16 instr)
{
	u8 arg2 = getnib(instr, 3);
	u8 arg1 = getnib(instr, 2);
	u8 dest = getnib(instr, 1);
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("div(reg%d, reg%d, reg%d)",
			dest, arg1, arg2);
	log_stamp();
	log_info("TODO(div)\n");
	return 0;
}

i8 instr_slt(struct cpu *cpu, u16 instr)
{
	u8 arg2 = getnib(instr, 3);
	u8 arg1 = getnib(instr, 2);
	u8 dest = getnib(instr, 1);
	(void)dest;
	(void)arg1;
	(void)arg2;
	log_info_args("slt(reg%d, reg%d, reg%d)",
			dest, arg1, arg2);
	log_stamp();
	log_info("TODO(slt)\n");
	return 0;
}

i8 instr_or(struct cpu *cpu, u16 instr);
i8 instr_xor(struct cpu *cpu, u16 instr);
i8 instr_not(struct cpu *cpu, u16 instr);
i8 instr_and(struct cpu *cpu, u16 instr);
i8 instr_loa(struct cpu *cpu, u16 instr);
i8 instr_sto(struct cpu *cpu, u16 instr);
i8 instr_jpz(struct cpu *cpu, u16 instr);
i8 instr_jnz(struct cpu *cpu, u16 instr);
i8 instr_lsr(struct cpu *cpu, u16 instr);
i8 instr_lsl(struct cpu *cpu, u16 instr);
i8 instr_asr(struct cpu *cpu, u16 instr);
i8 instr_asl(struct cpu *cpu, u16 instr);
i8 instr_2op(struct cpu *cpu, u16 instr)
{
	log_stamp();
	log_info("TODO(2op)\n");
	return 0;
}

i8 instr_jto(struct cpu *cpu, u16 instr);
i8 instr_psh(struct cpu *cpu, u16 instr);
i8 instr_pop(struct cpu *cpu, u16 instr);
i8 instr_cll(struct cpu *cpu, u16 instr);
i8 instr_1op(struct cpu *cpu, u16 instr)
{
	log_stamp();
	log_info("TODO(1op)\n");
	return 0;
}

i8 instr_ldl(struct cpu *cpu, u16 instr)
{
	log_stamp();
	log_info("TODO(ldl)\n");
	return 0;
}

i8 instr_ldu(struct cpu *cpu, u16 instr)
{
	log_stamp();
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
i8 instr_ctr(struct cpu *cpu, u16 instr)
{
	cpu->running = 0; 	// for now, it pauses execution because
				// i'm too lazy to write it all for halt
	log_stamp();
	log_info("TODO(ctr)\n");
	return 0;
}

i8 instr_jmp(struct cpu *cpu, u16 instr)
{
	log_stamp();
	log_info("TODO(jmp)\n");
	return 0;
}

