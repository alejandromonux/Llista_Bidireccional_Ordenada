CC=gcc
CFLAGS=-I.
DEPS = llista.h
OBJ = llista.o llista.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

llistabiord: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
