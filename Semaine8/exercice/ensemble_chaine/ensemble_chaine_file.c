#include <stdio.h>
#include <stdlib.h>
#include "ensemble.h"
#include "test.h"

int main(int argc, char *argv[])
{
	int rt;
	struct ensemble e1;

	/* 1. On veut récupérer le nom du fichier dans le premier paramètre passé à l'exécutable */
	/* 2. On va utiliser ensuite la fonction initialisant l'ensemble d'entier à partir du contenu du fichier */

	if (argc != 2) {
		fprintf(stderr, "Nombre d'arguments invalides.\n");
		fprintf(stderr, "usage : %s filename\n", argv[0]);
		return EXIT_FAILURE;
	}

	rt = init_from_file(&e1, argv[1]);
	if (rt != 1) {
		fprintf(stderr, "Erreur d'initialisation de l'ensemble à partir du fichier %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	print_ensemble(&e1);

	return EXIT_SUCCESS;
}
