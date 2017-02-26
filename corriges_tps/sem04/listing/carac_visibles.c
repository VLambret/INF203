/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *arcv[]) {
	int i=0;

	for (i=33; i<=126; i++) {
		printf("Code décimal du caractère '%c' : %d\n", i, i);
	}

	return 0;
}
