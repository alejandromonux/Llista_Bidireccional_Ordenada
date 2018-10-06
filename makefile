CC=gcc
CFLAGS=-I -ggdb.
DEPS = llista.h
OBJ = main.c llista.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

llistabiord: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
