CC = g++
CFLAGS = -Wall -g -std=c++11

all: bf

bf.o : bf.c stack.h
	${CC} ${CFLAGS} -c bf.c    

stack.o: stack.c stack.h
	${CC} ${CFLAGS} -c stack.c

bf: stack.o bf.o
	${CC} -g bf.o stack.o -o bf

clean:
	rm -rf bf *.o

.PHONY: clean
