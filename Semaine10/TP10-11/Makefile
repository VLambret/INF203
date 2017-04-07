CC=gcc
CFLAGS=-Wall -Werror -g

EXECUTABLES=interpreteur main_test_vars

all: $(EXECUTABLES)

interpreteur: gestion_path.o systeme.o interpreteur.o variables.o
	$(CC) -o interpreteur gestion_path.o systeme.o interpreteur.o variables.o

main_test_vars: main_test_vars.o variables.o
	$(CC) -o main_test_vars main_test_vars.o variables.o

gestion_path.o: gestion_path.c gestion_path.h common.h
	$(CC) $(CFLAGS) -c gestion_path.c

systeme.o: systeme.c systeme.h common.h gestion_path.h
	$(CC) $(CFLAGS) -c systeme.c

interpreteur.o: interpreteur.c systeme.h common.h variables.h \
 gestion_path.h
	$(CC) $(CFLAGS) -c interpreteur.c

main_test_vars.o: main_test_vars.c variables.h \
 gestion_path.h
	$(CC) $(CFLAGS) -c main_test_vars.c 

variables.o: variables.c variables.h common.h systeme.h
	$(CC) $(CFLAGS) -c variables.c

clean:
	rm -f *.o interpreteur main_test_vars
