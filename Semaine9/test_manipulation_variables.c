#include <string.h>
#include "manipulation_variables.h"
#include "variables.h"
#include "test.h"
/*
int trouver_affectation_variable(char *ligne);

void appliquer_expansion_variables(char *ligne_originale,
                                   char *ligne_expansee);
*/

#define CONCAT_BUFFER_SIZE 128
char concat_buffer[CONCAT_BUFFER_SIZE];

char *concat(char *testName, char *specialCase) {
	strncpy(concat_buffer, testName, CONCAT_BUFFER_SIZE);
	strcat(concat_buffer, specialCase);

	return concat_buffer;
}

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
	test_expect (retour == retourAttendu, concat(testName, " trouver_affectation_variable"));

	retour = trouver_variable(nomVariable);
	test_expect (retour == retourAttendu, concat(testName, " trouver_variable"));

	valeurObtenue = valeur_variable(nomVariable);
	retour = strcmp(valeurObtenue, valeurAttendue);
	test_expect (retour == 0, concat(testName, " valeur_variable"));
}

void test_manipulation_variables_complete()
{
	test_trouver_helper("", 0, "", "", "chaine vide");
	test_trouver_helper("CC=gcc", 1, "CC", "gcc", "affectation normale");
	test_trouver_helper("CC =gcc", 0, "CC", "", "espace avant egal");
	test_trouver_helper("CC= gcc", 0, "CC", "", "espace apres egal");
	test_trouver_helper("CC = gcc", 0, "CC", "", "espace autour du egal");
}
