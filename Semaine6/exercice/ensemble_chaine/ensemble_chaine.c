#include <stdio.h>
#include "test.h"

#define MAX_SIZE 8

struct ensemble {
	unsigned int cardinal;
	int elements[MAX_SIZE];
};

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

int main(int argc, char *argv[])
{
	int rt;
	struct ensemble e1;

	init_empty(&e1);

	rt = add_element(&e1, 1);
	test_expect(rt == 1, "Insertion OK");

	rt = check_presence(&e1, 1);
	test_expect(rt == 1, "Présence d'un nombre présent");

	rt = check_presence(&e1, 2);
	test_expect(rt == -1, "Présence d'un nombre absent");

	add_element(&e1, 2);
	rt = add_element(&e1, 2);
	test_expect(rt == -1, "Insertion d'un nombre déjà présent");

	add_element(&e1, 3);

	rt = remove_element(&e1, 2);
	test_expect(rt == 1, "Retirer un nombre présent");

	rt = remove_element(&e1, 2);
	test_expect(rt == -1, "Retirer un nombre absent");

	rt = check_presence(&e1, 3);
	test_expect(rt == 1, "Présence quand le précédent a été enlevé");

	print_ensemble(&e1);

	add_element(&e1, 4);

	test_results();

	return 0;
}
