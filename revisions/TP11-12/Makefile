CC=gcc
CFLAGS=-Wall -Werror -g

EXECUTABLES=interpreteur

all: $(EXECUTABLES)

interpreteur: gestion_path.o systeme.o interpreteur.o commandes.o variables.o
	$(CC) -o interpreteur gestion_path.o systeme.o interpreteur.o commandes.o variables.o

gestion_path.o: gestion_path.c gestion_path.h common.h variables.h
	$(CC) $(CFLAGS) -c gestion_path.c

systeme.o: systeme.c systeme.h common.h gestion_path.h
	$(CC) $(CFLAGS) -c systeme.c

interpreteur.o: interpreteur.c systeme.h common.h variables.h \
 gestion_path.h commandes.h
	$(CC) $(CFLAGS) -c interpreteur.c

variables.o: variables.c variables.h common.h systeme.h
	$(CC) $(CFLAGS) -c variables.c

commandes.o: commandes.c commandes.h common.h systeme.h interpreteur.h
	$(CC) $(CFLAGS) -c commandes.c

clean:
	rm *.o interpreteur
