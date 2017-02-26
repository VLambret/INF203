/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include <stdlib.h>

void function_cat (char *filename) {
	char character;
	FILE *file = fopen (filename, "r");

	if (file == NULL) {
		printf ("Impossible d'ouvrir en lecture : %s\n", filename);
		exit (1);
	}

	fscanf (file, "%c", &character);
	while ( !feof (file) ) {
		printf ("%c", character);
		fscanf (file, "%c", &character);
	}

	fclose (file);
}

int main (int argc, char *argv[]) {
	int i = 1;

	if (2 > argc) {
		printf ("USAGE my_cat FILE ...\n");
		return 1;
	}

	while (i < argc) {
		function_cat (argv[i]);
		i++;
	}

	return 0;
}
