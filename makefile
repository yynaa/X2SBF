CC=gcc
CFLAGS=-lm -l aubio

objects = $(patsubst %.c,%.o,$(wildcard *.c))
objects-input = $(patsubst input/%.c,%.o,$(wildcard input/*.c))

all: build clean

build: build-input
	$(CC) -c $(wildcard *.c)
	$(CC) -o x2sbf $(objects) $(objects-input) $(CFLAGS)

build-input:
	$(CC) -c $(wildcard input/*.c)

clean:
	rm -f *.o

rm: clean
	rm -f x2sbf