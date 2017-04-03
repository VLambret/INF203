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
	e->cardinal = 0;
}

/* Cette fonction initialise l'ensemble à partir d'un fichier formaté avec un entier par ligne */
int init_from_file(struct ensemble *e, char *filename)
{
	/* 1. On doit commencer à ouvrir le fichier avec les bons droits */
	/* 2. Si va bien on va lire un entier sur chaque ligne dans le fichier */
	return 0;
}

/* Cette fonction vérifie si l'entier n est dans l'ensemble e
 * elle renvoie 1 si il est présent, -1 sinon
 */
int check_presence(struct ensemble *e, int n)
{
	int i;
	for (i = 0; i < e->cardinal; i++) {
		if (e->elements[i] == n) {
			return 1;
		}
	}
	return -1;
}

/* Cette fonction ajoute l'entier n à l'ensemble.
 * Elle renvoie 1 si l'insertion est un succès, -1 sinon
 */
int add_element(struct ensemble *e, int n)
{
	if (check_presence(e, n) == 1) {
		return -1;
	}

	if (e->cardinal >= MAX_SIZE) {
		return -1;
	}

	e->elements[e->cardinal] = n;
	e->cardinal++;
	return 1;
}

/* Cette fonction supprimer l'entier n de l'ensemble
 * Elle renvoie 1 si la suppression est un succès, -1 sinon
 */
int remove_element(struct ensemble *e, int n)
{
	int i = 0;

	if (check_presence(e, n) == -1) {
		return -1;
	}

	if (e->cardinal == 0) {
		return -1;
	}

	while(e->elements[i] != n) {
		i++;
	}

	e->elements[i] = e->elements[e->cardinal - 1];
	e->cardinal--;

	return 1;
}
