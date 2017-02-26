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

void function_cat_without_argument (void) {
	char character;

	/* Tant que l'entrée standard est vide, le programme attend */
	fscanf (stdin, "%c", &character);

	/* feof ne considère que l'on a atteint la fin de l'entrée standard
	 * que lorsque l'utilisateur a tapé Ctrl + D au début d'une ligne */
	while ( !feof (stdin) ) {

		/* Du point de vue du programme, on imprime immédiatement un
		 * caractère lu. Toutefois, à l'exécution, les caractères ne
		 * s'affichent que lorsqu'on appuie sur entrée. Cela est dû au
		 * fait que le terminal n'écrit dans stdin que lorsqu'on
		 * appuie effectivement sur entrée. */
		printf ("%c", character);
		fscanf (stdin, "%c", &character);
	}
}

int main (int argc, char *argv[]) {
	int i = 1;

	if (2 > argc) {
		function_cat_without_argument ();
		return 0;
	}

	while (i < argc) {
		function_cat (argv[i]);
		i++;
	}

	return 0;
}
