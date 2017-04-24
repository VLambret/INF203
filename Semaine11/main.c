#include <stdio.h>
#include "ensemble_entier.h"

int main()
{
	struct ensemble_entier e;
	int sous_ensemble_2[NMAX];
	int sous_ensemble_3[NMAX];
	int sous_ensemble_union[NMAX];
	int sous_ensemble_intersection[NMAX];

	init_ensemble_entier(&e);
	ajouter_entier(&e, 3);
	ajouter_entier(&e, 2);
	ajouter_entier(&e, 4);
	ajouter_entier(&e, 1);
	ajouter_entier(&e, 6);
	ajouter_entier(&e, 5);

	print_ensemble_entier(&e);

	printf("Multiples de 2\n");
	sous_ensemble_multiple(&e, sous_ensemble_2, 2);
	print_sous_ensemble(&e, sous_ensemble_2);

	printf("Multiples de 3\n");
	sous_ensemble_multiple(&e, sous_ensemble_3, 3);
	print_sous_ensemble(&e, sous_ensemble_3);

	printf("Union :\n");
	se_union(sous_ensemble_2, sous_ensemble_3, sous_ensemble_union);
	print_sous_ensemble(&e, sous_ensemble_union);

	printf("Intersection :\n");
	se_intersection(sous_ensemble_2, sous_ensemble_3, sous_ensemble_intersection);
	print_sous_ensemble(&e, sous_ensemble_intersection);

	return 0;
}
