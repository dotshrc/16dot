#include "log.h"
#include "type.h"
#include "cpu.h"

i32 main(i32 argc, char **argv) {
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
	struct cpu cpu = {0};
	if (cpu_init(&cpu, argv[1]) == 1) {
		log_err("failed to initialize cpu");
		cpu_shutdown(&cpu);
		return 1;
	}
	while (cpu.running) {
		if (cpu_step(&cpu) == 1) {
			log_err("cpu step failed");
			cpu_shutdown(&cpu);
			return 1;
		}
	}
	cpu_shutdown(&cpu);
	return 0;
}
