#include <stdio.h>
#include "ensemble_entier.h"

void print_ensemble_entier(struct ensemble_entier *e)
{
	int i;
	printf("nombre = %d\n", e->nombre);
	for (i = 0; i < e->nombre; i++) {
		printf("    values[%d]=%d\n", i, e->values[i]);
	}
}

void init_ensemble_entier(struct ensemble_entier *e)
{
	e->nombre = 0;
}

void ajouter_entier(struct ensemble_entier *e, int entier)
{
	int i = 0;
	int j;

	if (e->nombre == NMAX) {
		fprintf(stderr, "Ensemble plein !\n");
		return;
	}

	while(e->values[i] < entier && i < e->nombre) {
		i++;
		if (e->values[i] == entier) {
			fprintf(stderr, "%d deja present\n", entier);
			return;
		}
	}

	for (j = e->nombre; j > i; j--) {
		e->values[j] = e->values[j - 1];
	}

	e->values[i] = entier;
	e->nombre++;
	return;
}
