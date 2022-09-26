CC=gcc
CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -pg --save-temps -fPIC
LDFLAGS=

SRC=src
OBJ=obj
HDR=hdr
SRCS=$(wildcard $(SRC)/*.c)
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))
HDRS=$(wildcard $(SRC)/*.h)

BINDER=bin
BIN=$(BINDER)/main
SUBMITNAME=project_5-1.zip

all: $(BIN)

release: CFLAGS=-Wall -Wextra -Wpedantic -Werror -O2 -DNDEBUG -pg --save-temps -fPIC
release: clean
release: $(BIN)

$(BIN): $(OBJ) $(OBJS) $(BINDER)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ):
	mkdir -p $@

$(BINDER):
	mkdir -p $@

leakcheck:
	valgrind -s --leak-check=full --show-leak-kinds=all --show-reachable=yes --track-origins=yes ./bin/main

getint.1:
	help2man -o ./Documentation/$@ -n 'get next integer from input into *pn' ./bin/main

getint.1.2:
	help2man -i ./Documentation/print.h2m -o ./Documentation/print.1 ./bin/main

clean:
	$(RM) -r $(BINDER)/* $(OBJ)/*
	$(RM) -r $(OBJ)
	$(RM) -r $(BINDER)
	$(RM) *.i
	$(RM) *.zip
	$(RM) *.s
	$(RM) *.bc
	$(RM) *.txt
	$(RM) *.out

submit:
	$(RM) $(SUBMITNAME)
	zip $(SUBMITNAME) $(BIN)

