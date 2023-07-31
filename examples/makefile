CC=gcc
TBX_DIR=../src
CFLAGS=-I$(TBX_DIR)
DEPS=$(TBDX_DIR)/%.h
OBJ=example.o clargs.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

example: example.c $(TBX_DIR)/clargs.c
	$(CC) -o $@ $^ $(CFLAGS)
