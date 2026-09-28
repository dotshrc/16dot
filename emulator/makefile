CC:=cc
CFLAGS:= -DDEBUG -Wall -Werror -Wpedantic -std=c99
LDFLAGS:= -fsanitize=address,undefined

SRC=emu.c cpu.c
OBJ=$(SRC:.c=.o)
BIN=emu

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) $(LDFLAGS) -o $@ $(OBJ)

.c.o:
	$(CC) $(CFLAGS) -c $<

.PHONY: clean
clean:
	rm -vf $(BIN) $(OBJ)

