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

/* Renvoie 1 si la ligne comporte une affectation. 0 Sinon.
 * Dans le cas ou la ligne contient une affectation cette fonction doit
 * aussi l'ajouter à la table des variables. */
int trouver_affectation_variable(char *ligne) {
	return 0;
}

/*
  appliquer_expansion_variables
  Fonction qui prend une ligne lue en parametre et la recopie dans le tableau
  resultat en remplacant toutes les utilisations de variable (de la forme
  '$nom' ou nom est une chaine de caracteres alphanumeriques ou * ou #) par la
  valeur de la variable correspondante.
*/
void appliquer_expansion_variables(char *ligne_originale,
                                   char *ligne_expansee)
{
	strcpy(ligne_expansee, ligne_originale);
	return;
}

int main(int argc, char*argv[])
{
	fichier = fopen(argv[1], "r");
	while (!feof(fichier)) {
		lire_commande();
		executer_commande();
	}
	fclose(fichier);
	exit(0);
}
