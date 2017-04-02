/**
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include "automate.h"

int transitions[NB_ETAT][NB_ENTREE] = {
	{ Q4, Q2, Q3, Q1, Q1 },
	{ Q1, Q1, Q1, Q1, Q1 },
	{ Q1, Q1, Q1, Q1, Q1 },
	{ Q4, Q4, Q4, Q1, Q4 }
};

int sorties[NB_ETAT][NB_ENTREE] = {
	{ S_NEANT,    S_IDENTITE, S_IDENTITE, S_IDENTITE, S_IDENTITE },
	{ S_IDENTITE, S_IDENTITE, S_IDENTITE, S_IDENTITE, S_IDENTITE },
	{ S_IDENTITE, S_IDENTITE, S_IDENTITE, S_IDENTITE, S_IDENTITE },
	{ S_NEANT,    S_NEANT,    S_NEANT,    S_IDENTITE, S_NEANT    }
};

void executer_sortie (Sortie sortie, FILE * destination, char caractere) {
	switch (sortie) {
	case S_IDENTITE:
		fprintf (destination, "%c", caractere);
		return;
	case S_NEANT:
		return;
	}
}

int lire_entree (FILE * source, Entree * entree, char * caractere_ptr) {
	char caractere = fgetc(source);
	if (feof (source)) {
		return 0;
	}

	switch (caractere) {
	case '#':
		*entree = E_DIESE;
		break;
	case '$':
		*entree = E_DOLLAR;
		break;
	case '\\':
		*entree = E_ANTISLASH;
		break;
	case '\n':
		*entree = E_RETOUR;
		break;
	default:
		*entree = E_AUTRE;
	}

	*caractere_ptr = caractere;
	return 1;
}

void traiter_fichier (FILE * source, FILE * destination) {
	char   caractere    = 0;
	Etat   etat_courant = Q1, etat_suivant = Q1;
	Entree entree       = E_AUTRE;
	Sortie sortie       = S_NEANT;

	while (lire_entree (source, &entree, &caractere)) {
		etat_suivant = transitions[etat_courant][entree];
		sortie       = sorties[etat_courant][entree];

		executer_sortie (sortie, destination, caractere);
		etat_courant = etat_suivant;
	}
}
