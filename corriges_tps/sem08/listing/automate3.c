#include <stdio.h>
#include <string.h>
#include "automate.h"

#define NB_ETATS 5
#define NB_ENTREES 10
#define LG_MAX_SORTIE 128

#define Q0 0
#define Q1 1
#define Q2 2
#define Q3 3
#define Q4 4

typedef int etat; // Intérêt pédagogique ...

int transition[NB_ETATS][NB_ENTREES] = {
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 3, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 4, 0, 0, 0, 0, 0 },
	{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
};

char sortie[NB_ETATS][NB_ENTREES][LG_MAX_SORTIE];

void init_sorties (void) {
	for (int i=0; i<NB_ETATS; i++) {
		for (int j=0; j<NB_ENTREES; j++) {
			sortie[i][j][0] = '\0';
		}
	}
	strcpy(sortie[Q3][4], "Code bon, vous pouvez entrer.");
}

etat etat_initial() {
	return Q0;
}

int est_final(etat Q) {
	return Q == Q4;
}

int lire_entree() {
	char c;
	scanf("\n%c", &c);
	while (((c < '0') || (c > '9')) && (c != '-')) {
		printf("entree invalide ! un chiffre entre 0 et 9 (- pour finir) ?\n");
		scanf("\n%c", &c);
	}
	if (c == '-') {
		return -1;
	}
	else {
		return c-'0';
	}
}

void simule_automate() {
	int etat_courant=0, etat_suivant=0, entree=0;
	etat_courant = etat_initial();
	init_sorties();

	while (entree != -1) {
		entree = lire_entree();

		etat_suivant = transition[etat_courant][entree];
		printf("%s\n", sortie[etat_courant][entree]);
		printf("état courant : %d, état suivant : %d, entree : %d\n", etat_courant, etat_suivant, entree);
		etat_courant = etat_suivant;
	}
}
