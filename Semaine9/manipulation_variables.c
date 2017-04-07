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
