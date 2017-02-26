/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include <stdlib.h>

/* Caractères imprimables : de 33 ('!') à 126 ('~') soit 94 caractères */
#define NB_CARACTERES_IMPRIMABLES 94

int main (int argc, char *argv[]) {
	int i = 0;
	char character;
	char *filename = NULL;
	FILE *file     = NULL;

	/* Le tableau occurences est initialisé avec des 0
	 *
	 * Chaque case fait référence au caractère correspondant
	 * à son indice dans la table ASCII à partir du caractère 33.
	 *
	 * Ex : occurence[0] ==> ASCII(33) '!'
	 *      occurence[1] ==> ASCII(34) '"'
	 *      occurence[2] ==> ASCII(35) '#'
	 *      ...
	 */
	int occurences[NB_CARACTERES_IMPRIMABLES] = {0};

	if (argc != 2) {
		printf("USAGE: wc FILE\n");
		return 1;
	}

	filename = argv[1];
	file     = fopen (filename, "r");

	if (file == NULL) {
		printf ("Impossible d'ouvrir en lecture : %s\n", filename);
		return 1;
	}

	fscanf (file, "%c", &character);
	while ( !feof (file) ) {
		if (32 < character && 127 > character) {
			occurences[character - 33]++;
		}

		fscanf (file, "%c", &character);
	}

	for (i=0; i<NB_CARACTERES_IMPRIMABLES; i++) {
		printf ("Nombre d'occurences du caractère '%c' : %d\n", i+33, occurences[i]);
	}

	return 0;
}
