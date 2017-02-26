#include <stdio.h>

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
			printf("{EMPTY}");
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
 * elle renvoie 0 si il est présent, -1 sinon
 */
int check_presence(struct ensemble *e, int n)
{
	return -1;
}

/* Cette fonction ajoute l'entier n à l'ensemble.
 * Elle renvoie 0 si l'insertion est un succès, -1 sinon
 */
int add_element(struct ensemble *e, int n)
{
	return -1;
}

/* Cette fonction supprimer l'entier n de l'ensemble
 * Elle renvoie 0 si la suppression est un succès, -1 sinon
 */
int remove_element(struct ensemble *e, int n)
{
	return -1;
}

int main(int argc, char *argv[])
{
	struct ensemble e1;

	print_ensemble(&e1);
	return 0;
}
