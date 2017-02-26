/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>

int main (int argc, char *argv[]) {
	FILE *file = NULL;
	char *filename = NULL;
	char character;

	if (argc != 2) {
		printf ("USAGE my_cat FILE\n");
		return 1;
	}

	filename = argv[1];
	file = fopen (filename, "r");

	if (file == NULL) {
		printf ("%s n'a pas pu être ouvert en lecture\n", filename);
		return 1;
	}

	fscanf (file, "%c", &character);
	while ( !feof (file) ) {
		printf ("%c", character);
		fscanf (file, "%c", &character);
	}

	fclose (file);
	return 0;
}
