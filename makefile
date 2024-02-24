CC=gcc
CFLAGS=-lm

all: build clean

build: main.o arg_parser.o
	$(CC) -o x2sbf main.o arg_parser.o $(CFLAGS)

main.o:
	$(CC) -c main.c

arg_parser.o:
	$(CC) -c arg_parser.c

clean:
	rm -f *.o
