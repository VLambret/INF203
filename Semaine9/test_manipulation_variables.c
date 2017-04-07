#include <string.h>
#include "manipulation_variables.h"
#include "variables.h"
#include "test.h"
/*
int trouver_affectation_variable(char *ligne);

void appliquer_expansion_variables(char *ligne_originale,
                                   char *ligne_expansee);
*/

void test_trouver_helper(char * ligne,
                         int retourAttendu,
                         char * nomVariable,
                         char * valeurAttendue,
                         char * testName) {
	int retour;
	char *valeurObtenue;

	/* On initialise à l'ensemble vide afin de pouvoir facilement vérifier si la variable est ajoutée */
	initialiser_variables();

	retour = trouver_affectation_variable(ligne);
	test_expect (retour == retourAttendu, testName);

	retour = trouver_variable(nomVariable);
	test_expect (retour == retourAttendu, testName);

	valeurObtenue = valeur_variable(nomVariable);
	retour = strcmp(valeurObtenue, valeurAttendue);
	test_expect (retour == 0, testName);
}

void test_manipulation_variables_complete()
{
	test_trouver_helper("", 0, "", "", "chaine vide");
}
