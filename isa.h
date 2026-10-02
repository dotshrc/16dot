#ifndef ISA_H
#define ISA_H

enum reg {
	REG_ZERO 	= 0x0,
	REG_SYS 	= 0x1,
	REG_GP 		= 0x2,
	REG_SP 		= 0x3, 
	REG_PC 		= 0x4,
	REG_XPC 	= 0x5,
	REG_LR 		= 0x6,		
	REG_A0 		= 0x7,		
	REG_A1 		= 0x8,		
	REG_A2 		= 0x9,		
	REG_T0 		= 0xA,		
	REG_T1 		= 0xB,		
	REG_T2 		= 0xC,		
	REG_S0 		= 0xD,		
	REG_S1 		= 0xE,		
	REG_S2 		= 0xF,	
};

enum opcode {
	OP_NOP 		= 0x0,
	OP_ADD 		= 0x1,
	OP_SUB 		= 0x2,
	OP_MUL 		= 0x3,
	OP_DIV 		= 0x4,
	OP_SLT 		= 0x5,

	OP_2OP 		= 0x6,
	SUBOP_OR	= 0x1,
	SUBOP_XOR	= 0x2,
	SUBOP_NOT	= 0x3,
	SUBOP_AND	= 0x4,
	SUBOP_LOA	= 0x5,
	SUBOP_STO	= 0x6,
	SUBOP_JPZ	= 0x7,
	SUBOP_JNZ	= 0x8,
	SUBOP_LSR	= 0x9,
	SUBOP_LSL	= 0xA,
	SUBOP_ASR	= 0xB,
	SUBOP_ASL	= 0xC,
	
	OP_1OP		= 0x7,
	SUBOP_JTO	= 0x1,
	SUBOP_PSH	= 0x2,
	SUBOP_POP	= 0x3,
	SUBOP_CLL	= 0x4,

	OP_LDL		= 0x8,
	OP_LDU		= 0x9,

	OP_CTR		= 0xA,
	SUBOP_HLT	= 0x0,
	SUBOP_SYS	= 0x1,
	SUBOP_XRT	= 0x2,
	SUBOP_TRP	= 0x3,
	SUBOP_NNT	= 0x4,
	SUBOP_INT	= 0x5,
	SUBOP_DBI	= 0x6,
	SUBOP_BRK	= 0x7,

	OP_JMP		= 0xB,
};
 
#define REG_MAXSIZE (16 * sizeof(u16))
#define MEM_MAXSIZE ((1 << 16) * sizeof(u16))

#endif
