#include "ensemble.h"
#include <stdio.h>

void print_ensemble(struct ensemble *e)
{
	int i;
	printf("Cardinal : %d\n", e->cardinal);
	for (i = 0; i < MAX_SIZE; i++) {
		printf("    elements[%d]=", i);
		if (i < e->cardinal) {
			printf("%d\n", e->elements[i]);
		} else {
			printf("{EMPTY}\n");
		}
	}

	return;
}

/* Cette fonction initialise l'ensemble à l'ensemble vide */
void init_empty(struct ensemble *e)
{
	return;
}

/* Cette fonction vérifie si l'entier n est dans l'ensemble e
 * elle renvoie 1 si il est présent, -1 sinon
 */
int check_presence(struct ensemble *e, int n)
{
	return 0;
}

/* Cette fonction ajoute l'entier n à l'ensemble.
 * Elle renvoie 1 si l'insertion est un succès, -1 sinon
 */
int add_element(struct ensemble *e, int n)
{
	return 0;
}

/* Cette fonction supprimer l'entier n de l'ensemble
 * Elle renvoie 1 si la suppression est un succès, -1 sinon
 */
int remove_element(struct ensemble *e, int n)
{
	return 0;
}
