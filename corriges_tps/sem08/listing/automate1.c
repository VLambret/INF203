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

	while (entree != -1) {
		entree = lire_entree();
		switch (etat_courant) {
		case Q0 :
			switch (entree) {
			case 1:
				etat_suivant = Q1;
				break;
			default:
				etat_suivant = Q0;
				break;
			}
			break;

		case Q1 :
			switch (entree) {
			case 1 :
				etat_suivant = Q1;
				break;
			case 2 :
				etat_suivant = Q2;
				break;
			default :
				etat_suivant = Q0;
				break;
			}
			break;

		case Q2 :
			switch (entree) {
			case 1 :
				etat_suivant = Q1;
				break;
			case 3 :
				etat_suivant = Q3;
				break;
			default :
				etat_suivant = Q0;
				break;
			}
			break;

		case Q3 :
			switch (entree) {
			case 1 :
				etat_suivant = Q1;
				break;
			case 4 :
				etat_suivant = Q4;
				break;
			default :
				etat_suivant = Q0;
				break;
			}
			break;

		case Q4 :
			switch (entree) {
			case 1 :
				etat_suivant = Q1;
				break;
			default :
				etat_suivant = Q0;
				break;
			}
			break;

		default : break;
		}
		printf("état courant : %d, état suivant : %d, entree : %d\n", etat_courant, etat_suivant, entree);

		if (est_final(etat_suivant)) {
			printf ("Vous pouvez entrer !\n");
		}
		etat_courant = etat_suivant;
	}
}
