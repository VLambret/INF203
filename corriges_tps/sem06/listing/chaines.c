#include <string.h>
#include <stdio.h>
#include "chaines.h"

void init_chaines(chaines *c) {
	c->cardinal = 0;
	for (int i=0; i<NB_MAX_CHAINES; i++) {
		c->tab[i][0] = '\0';
	}
}

int ajouter_chaine(chaines *c, char *s) {
	if (s == NULL) {
		printf ("Invalid string\n");
		return -1;
	}

	if (c->cardinal >= NB_MAX_CHAINES) {
		printf ("Maximum ensemble size reached\n");
		return -1;
	}

	if (trouver_chaine (c, s) == -1) {
		printf ("String already added\n");
		return -1;
	}

	strcpy(c->tab[c->cardinal], s);
	c->cardinal++;

	return c->cardinal-1;
}

int nombre_chaines(chaines *c) {
	return c->cardinal;
}

char *recuperer_chaine(chaines *c, int i) {
	return c->tab[i];
}

int trouver_chaine(chaines *c, char *s) {
	for (int i=0; i<c->cardinal; i++) {
		if (strcmp(c->tab[i], s) == 0) {
			return i;
		}
	}
	printf ("Not found\n");
	return -1;
}

void afficher_ensemble_chaines(chaines *c) {
	int i ;
	for (i=0 ; i<c->cardinal ; i++) {
		printf("%s\n", c->tab[i]);
	}
}
