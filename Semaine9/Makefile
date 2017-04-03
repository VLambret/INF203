.PHONY : all clean test

all : interpreter

clean :
	rm -f *.o interpreter

test : interpreter
	./interpreter example.sh

interpreter : main.c variables.c variables.h
	gcc -o $@ -g -Wall -Werror *.c
