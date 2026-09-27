#include <stdio.h>
#include "type.h"
#include <stdint.h>

struct state {
	u16 opcode[16];
	u16 mem[1 << 16];
	u16 pc;
	u8 running;
};

i32 main(i32 argc, char **argv) {
	printf("hello cruel world\n");
	return 0;
}
