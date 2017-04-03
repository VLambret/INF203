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

#define NAME 0
#define EGAL 1
#define VALEUR 2

/* Renvoie 1 si la ligne comporte une affectation. 0 Sinon.
 * Dans le cas ou la ligne contient une affectation cette fonction doit
 * aussi l'ajouter à la table des variables. */
int trouver_affectation_variable(char *ligne) {
	int i = 0;
	int affectation = 1;
	int state = NAME;

	while(ligne[i] != '\0') {
		if (state == NAME) {

		} else if (state == EGAL) {
			
		} else if (state == VALEUR) {

		}
	}

	return affectation;
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

void test_variables()
{
	int found;
	initialiser_variables();
	affecter_variable("CC", "gcc -Wall -Werror");
	found = trouver_variable("CC");
	if (found == 1)
		printf("OK\n");
	else
		printf("ERREUR\n");
}

int main(int argc, char*argv[])
{
	if (argc != 2) {
		fprintf(stderr, "ERROR : nombre d'arguments invalide\n");
		exit(1);
	}

	test_variables();
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
