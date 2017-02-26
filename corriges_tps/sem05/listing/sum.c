/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
	int i = 0, somme = 0;

	if (argc == 1) {
		printf ("USAGE: sum NUMBER ...\n");
		return 1;
	}

	for (i=1; i<argc; i++) {
		printf ("%s ", argv[i]);
		if (i < argc - 1) {
			printf ("+ ");
		}

		somme += atoi (argv[i]);
	}

	printf ("= %d\n", somme);
	return 0;
}
