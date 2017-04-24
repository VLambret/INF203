#include "ensemble_entier.h"

int main()
{
	struct ensemble_entier e;

	init_ensemble_entier(&e);
	ajouter_entier(&e, 4);
	ajouter_entier(&e, 2);
	ajouter_entier(&e, 3);
	ajouter_entier(&e, 5);
	ajouter_entier(&e, 5);
	ajouter_entier(&e, 13);
	ajouter_entier(&e, 1);

	print_ensemble_entier(&e);

	return 0;
}
