CFLAGS = -Wall -Werror

ensemble_chaine : ensemble.o ensemble_chaine.o test.o
	gcc $(CFLAGS) ensemble.o ensemble_chaine.o test.o -o ensemble_chaine

ensemble.o : ensemble.c ensemble.h
	gcc -Wall -Werror -c ensemble.c

ensemble_chaine.o : ensemble_chaine.c ensemble.h test.h
	gcc -Wall -Werror -c ensemble_chaine.c

test.o : test.c test.h
	gcc -Wall -Werror -c test.c
