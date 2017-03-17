CFLAGS = -Wall -Werror

all : ensemble_chaine ensemble_chaine_file

clean :
	rm -f *.o ensemble_chaine ensemble_chaine_file

ensemble_chaine : ensemble.o ensemble_chaine.o test.o
	gcc $(CFLAGS) ensemble.o ensemble_chaine.o test.o -o ensemble_chaine

ensemble_chaine_file : ensemble.o ensemble_chaine_file.o test.o
	gcc $(CFLAGS) ensemble.o ensemble_chaine_file.o test.o -o ensemble_chaine_file

ensemble.o : ensemble.c ensemble.h
	gcc $(CFLAGS) -c ensemble.c

ensemble_chaine.o : ensemble_chaine.c ensemble.h test.h
	gcc $(CFLAGS) -c ensemble_chaine.c

ensemble_chaine_file.o : ensemble_chaine_file.c ensemble.h test.h
	gcc $(CFLAGS) -c ensemble_chaine_file.c

test.o : test.c test.h
	gcc $(CFLAGS) -c test.c
