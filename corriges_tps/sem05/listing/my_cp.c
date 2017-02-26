/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>

int main (int argc, char *argv[]) {
	char *source_filename = NULL, *destination_filename = NULL;
	FILE *source          = NULL, *destination          = NULL;
	char character;

	if (2 > argc || 3 < argc) {
		printf ("USAGE my_cp SRC [DEST]\n");
		return 1;
	}

	source_filename = argv[1];
	source          = fopen (source_filename, "r");

	if (source == NULL) {
		printf ("Impossible d'ouvrir en lecture : %s\n", source_filename);
		return 1;
	}

	if (argc == 3) {
		destination_filename = argv[2];
		destination          = fopen (destination_filename, "w");

		if (destination == NULL) {
			printf ("Impossible d'ouvrir en écriture : %s\n", destination_filename);
			return 1;
		}

	} else {
		destination = stdout;
	}

	fscanf (source, "%c", &character);
	while ( !feof (source) ) {
		fprintf (destination, "%c", character);
		fscanf (source, "%c", &character);
	}

	fclose (source);
	fclose (destination);
	return 0;
}
