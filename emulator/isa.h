#ifndef ISA_H
#define ISA_H

enum reg {
	REG_ZR = 0,
	REG_SY,
	REG_A0,
	REG_A1,
	REG_A2,
	REG_T0,
	REG_T1,
	REG_T2,
	REG_S0,
	REG_S1,
	REG_S2,
	REG_S3,
	REG_GP,
	REG_LR,
	REG_SP,
	REG_PC
};

enum opcode {
	OP_ADD	 = 0x1,
        OP_SUB	 = 0x2,
        OP_AND	 = 0x3,
        OP_SLT	 = 0x4,

        OP_2ARG	 = 0x5,
        SUBOP_OR = 0x1,
        SUBOP_XOR = 0x2,
        SUBOP_NOT = 0x3,
        SUBOP_CMP = 0x4,
        SUBOP_SHL = 0x5,
        SUBOP_SHR = 0x6,

        OP_BRNCH = 0x6,
        SUBOP_JP = 0x1,
        SUBOP_JZ = 0x2,
        SUBOP_JNZ = 0x3,
        SUBOP_JN = 0x4,
        SUBOP_JNN = 0x5,
        SUBOP_JC = 0x6,
        SUBOP_JNC = 0x7,

        OP_1ARG	= 0x7,
        SUBOP_AJ = 0x1,
        SUBOP_CLL = 0x2,
        SUBOP_PSH = 0x3,
        SUBOP_POP = 0x4,
                           
        OP_LDL	= 0x8,
	OP_LDU	= 0x9,

	OP_LD	= 0xA,
	OP_ST	= 0xB,
	   
	OP_CTRL	= 0xF,
	SUBOP_HLT = 0x0,
	SUBOP_TRP = 0x1,
	SUBOP_XRT = 0x2,
	   
	OP_NOP	  = 0x0
};
 
#define REG_MAXSIZE (16 * sizeof(u16))
#define MEM_MAXSIZE ((1 << 16) * sizeof(u16))

#endif
