billes : billes.o generer_entier.o joueurs.o joueurs_out.o joueurs_in.o
	gcc billes.o generer_entier.o joueurs.o joueurs_out.o joueurs_in.o -o billes

billes.o : billes.c generer_entier.h joueurs.h joueurs_out.h
	gcc -c billes.c

joueurs.o : joueurs.c joueurs.h
	gcc -c joueurs.c

joueurs_out.o : joueurs_out.c joueurs_out.h
	gcc -c joueurs_out.c

joueurs_in.o : joueurs_in.c joueurs_in.h
	gcc -c joueurs_in.c

generer_entier.o : generer_entier.c
	gcc -c generer_entier.c

clean :
	rm -f billes *.o
