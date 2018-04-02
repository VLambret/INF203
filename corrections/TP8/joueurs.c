#include <string.h>
#include <stdio.h>
#include "joueurs.h"

void init_joueurs(joueurs *ens) {
	ens->nb = 0;
}

int ajouter_joueur(joueurs *ens, char *nom, int billes) {
	strcpy(ens->T[ens->nb].pseudo, nom);
	ens->T[ens->nb].nb_billes = billes;
	ens->nb++;
	return ens->nb -1;
}

int nombre_joueurs(joueurs *ens) {
	return ens->nb;
}

int trouver_joueur(joueurs *ens, char *nom) {
	int i;
	for (i = 0 ; i < ens->nb ; i++) {
		if (strcmp(ens->T[i].pseudo, nom) == 0) {
			return i;
		}
	}
	return -1;
}

char *nom_joueur(joueurs *ens, int i) {
	return ens->T[i].pseudo;
}

int billes_joueur(joueurs *ens, int i) {
	return ens->T[i].nb_billes;
}

void modifier_billes(joueurs *ens, int i, int cpt) {
	ens->T[i].nb_billes = cpt;
}

void afficher_ensemble_joueurs(joueurs *ens) {
	int i ;
	for (i=0 ; i<ens->nb ; i++) 
		printf("%s %d\n", ens->T[i].pseudo, ens->T[i].nb_billes) ;
}
