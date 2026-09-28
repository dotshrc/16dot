#ifndef CPU_H
#define CPU_H

struct cpu {
	u16 *reg;
	u16 *mem;
	u16 svpc;
	u16 pc;
	u8 priv;
	u8 running;
	u8 zero, negative, carry;
};

i8 cpu_init(struct cpu *cpu, const char *pathtoexec); 
i8 cpu_step(struct cpu *cpu);
i8 cpu_shutdown(struct cpu *cpu); 

#endif
