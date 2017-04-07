#include <ctype.h>
#include "manipulation_variables.h"
#include "variables.h"

#define NAME 0
#define EGAL 1
#define VALEUR 2

/* Renvoie 1 si la ligne comporte une affectation. 0 Sinon.
 * Dans le cas ou la ligne contient une affectation cette fonction doit
 * aussi l'ajouter à la table des variables. */
int trouver_affectation_variable(char *ligne) {
	int i = 0;
	char *nomVariable = "TOTO";
	char *valeurVariable = "TATA";

	// [ ]*
	while(ligne[i] == ' ') {
		i++;
	}

	if (ligne[i] == '=')
		return 0;

	nomVariable = &ligne[i];
	// [a-zA-Z0-9_]+
	while (ligne[i] != '\0' && ligne[i] != '=') {
		if ((ligne[i] != '_' ) && 0 == isalnum(ligne[i])) {
			return 0;
		}
		i++;
	}

	// =
	while (ligne[i] != '\0') {
		if (ligne[i] == '=') {
			if (ligne[i - 1] != ' ' && ligne[i+1] != ' ') {
				valeurVariable = valeurVariable;
				nomVariable = nomVariable;
				//affecter_variable(nomVariable, valeurVariable);
				ligne[i] = '\0';
				return 1;
			}
		}
		i++;
	}
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
//	strcpy(ligne_expansee, ligne_originale);
	return;
}
