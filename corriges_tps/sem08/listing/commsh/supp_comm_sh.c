/**
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include "automate.h"

int main (int argc, char *argv[]) {
	FILE * source = NULL;
	if (argc != 2) {
		printf ("USAGE: ./supp_comm_sh file.c\n");
		return 1;
	}

	char * filename = argv[1];
	source = fopen (filename, "r");
	if (source == NULL) {
		printf ("Impossible de lire %s\n", filename);
		return 1;
	}

	/* Appel de l'automate */
	traiter_fichier (source, stdout);

	fclose (source);
	return 0;
}
