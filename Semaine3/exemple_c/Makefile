CFLAGS= -s -Wall -Werror
CFLAGS2 = -s -Wall -Werror

all : main

main : main.o math.o
	gcc $^ -o $@

main.o : math.h

clean :
	rm -f main *.o

%.o : %.c
	gcc -c $(CFLAGS) -o $@ $<

show : main.o math.o
	echo "math.o :"
	@readelf --all math.o |grep add |grep GLOBAL
	echo "main.o :"
	@readelf --all main.o |grep add |grep GLOBAL

C = toto

show2:
	echo $(CFLAGS)
	echo $(CFLAGS2)
	echo $CFLAGS
	echo $(CFLAGS3)

