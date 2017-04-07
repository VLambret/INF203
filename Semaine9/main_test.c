#include <stdlib.h>
#include "test_manipulation_variables.h"
#include "variables.h"
#include "test.h"

void test_trouver_variable_ensemble_vide()
{
	int found;
	initialiser_variables();
	found = trouver_variable("CC");
	test_expect(found == 0, "Chercher une variable dans l'ensemble vide");
}

void test_trouver_variable_unique()
{
	int found;
	initialiser_variables();
	affecter_variable("CC", "gcc -Wall -Werror");
	found = trouver_variable("CC");
	test_expect(found == 1, "Chercher une variable présente");
}

int main(int argc, char*argv[])
{
	test_trouver_variable_ensemble_vide();
	test_trouver_variable_unique();

	test_manipulation_variables_complete();

	test_results();

	exit(0);
}
