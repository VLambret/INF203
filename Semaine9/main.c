#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "variables.h"

#define TAILLE_COM 100

FILE *fichier;
char commande[TAILLE_COM];

void lire_commande()
{
	int i=0;
	do {
		fscanf(fichier, "%c", &(commande[i]));
		i++;
	} while (!feof(fichier) && (commande[i-1] != '\n'));
	/* on remplace '\n' par '\0' */
	commande[i-1] = '\0';
}

void executer_commande()
{
	if (commande[0] != '\0') {
		printf("on execute : %s\n", commande);
		system(commande);
	}
}

int main(int argc, char*argv[])
{
	if (argc != 2) {
		fprintf(stderr, "ERROR : nombre d'arguments invalide\n");
		exit(1);
	}

	fichier = fopen(argv[1], "r");

	if (fichier == NULL) {
		fprintf(stderr, "ERROR : erreur d'ouverture du fichier\n");
		exit(1);
	}

	while (!feof(fichier)) {
		lire_commande();
		executer_commande();
	}
	fclose(fichier);
	exit(0);
}
