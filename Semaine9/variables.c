#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "variables.h"

int nombre_variables;
char noms_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_NOM];
char valeurs_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_VALEUR];

char *CHAINE_VIDE = "";


void initialiser_variables()
{
	nombre_variables = 0;
}

int trouver_indice(char *nom)
{
	int i;
	int found;

	for (i = 0; i < nombre_variables; i++) {
		found = strcmp(nom, noms_variables[i]);
		if (found == 0) {
			return i;
		}
	}

	return -1;
}

int trouver_variable(char *nom)
{
	int indice;

	indice = trouver_indice(nom);

	if (indice != -1) {
		return 1;
	}
	return 0;
}

char *valeur_variable(char *nom)
{
	int indice;

	indice = trouver_indice(nom);

	if (indice != -1) {
		return valeurs_variables[indice];
	}
	return CHAINE_VIDE;
}

void affecter_variable(char *nom, char *valeur)
{
	int indice;

	indice = trouver_indice(nom);

	if (indice == -1) {
		indice = nombre_variables;
		if (nombre_variables >= NOMBRE_MAX_VARIABLES) {
			fprintf(stderr, "ERROR: nombre de variable max atteint\n");
			exit(1);
		}
		strcpy(noms_variables[indice], nom);
	}

	strcpy(valeurs_variables[indice], valeur);
	nombre_variables++;
}

void print_variables_debug() {
	int i;
	if (nombre_variables == 0) {
		fprintf(stderr, "Aucune variable enregistrée\n");
		return;
	}

	for (i = 0; i < nombre_variables; i++) {
		fprintf(stderr, "       Variable[%d] : NOM={%s}, VAL={%s}\n", i, noms_variables[i], valeurs_variables[i]);
	}
}
