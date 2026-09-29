CC:=cc
CFLAGS:= -DDEBUG -Wall -Werror -Wpedantic -std=c99 -I..
LDFLAGS:= -fsanitize=address,undefined
XXD:=xxd
XXDFLAGS:= -r -p

SRC=emu.c cpu.c instr.c
OBJ=$(SRC:.c=.o)
BIN=emu
DOTHEX=ex.hex
DOTBIN=ex

all: $(BIN)
hex: $(DOTBIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $<

$(DOTBIN): $(DOTHEX)
	$(XXD) -r -p $< $@

.PHONY: clean
clean:
	rm -vf $(BIN) $(OBJ)

