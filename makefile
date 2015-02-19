CC = gcc

all: main

main: main.o arvoreBinaria.o arvoreAVL.o menu.o
	$(CC) $(CFLAGS) -lm -o TP1 main.o arvoreBinaria.o arvoreAVL.o menu.o

arvoreBinaria.o: arvoreBinaria.c biblioteca.h
	$(CC) $(CFLAGS) -lm -c biblioteca.h arvoreBinaria.c

arvoreAVL.o: arvoreAVL.c biblioteca.h
	$(CC) $(CFLAGS) -lm -c biblioteca.h arvoreAVL.c

menu.o: menu.c biblioteca.h
	$(CC) $(CFLAGS) -lm -c biblioteca.h menu.c

clean:
	rm -rf TP1 arvoreAVL.o arvoreBinaria.o main.o menu.o
