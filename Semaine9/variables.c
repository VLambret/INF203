#include "variables.h"

int nombre_variables;
char noms_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_NOM];
char valeurs_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_VALEUR];

char *CHAINE_VIDE = "";


void initialiser_variables()
{
	return;
}

int trouver_variable(char *nom)
{
	return -1;
}

char *valeur_variable(char *nom)
{
	return CHAINE_VIDE;
}

void affecter_variable(char *nom, char *valeur)
{
	return;
}
