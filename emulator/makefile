include config.mk

ifdef DEBUG_SAN
LDFLAGS += -fsanitize=address,undefined
CFLAGS += -DDEBUG -Wall -Werror -Wpedantic -O0
else
CFLAGS += -O2

endif

ifdef DEBUG_G
CFLAGS += -g -DDEBUG
endif
ifeq ($(and $(DEBUG_G),$(DEBUG_SAN)),)
endif

SRC = emu.c cpu.c instr.c
OBJ = $(SRC:.c=.o)
BIN = emu
DOTHEX = ex.hex
DOTBIN = ex

all: $(BIN)
hex: $(DOTBIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) -std=c99 $(CFLAGS) -I.. -c $<

$(DOTBIN): $(DOTHEX)
	$(XXD) -r -p $(XXDFLAGS) $< $@

.PHONY: clean
clean:
	rm -vf $(BIN) $(OBJ) $(DOTBIN)

