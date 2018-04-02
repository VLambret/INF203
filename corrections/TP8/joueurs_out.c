#include "joueurs_out.h"

/*
  Enregistre l'ensemble de joueurs dans un fichier portant le nom choisi.
  Le contenu du fichier devra suivre rigoureusement le format :
  - sur la première ligne, le nombre de joueurs de l'ensemble
  - puis, sur chaque ligne, un nom de joueur, une espace et son nombre de billes
 */
void ecrire_les_joueurs(joueurs *ens, char *nom_fich) {
	FILE *f;
	int i;

	f = fopen(nom_fich, "w");
	if (f == NULL) {
		fprintf(stderr, "Impossible de créer le fichier %s\n", nom_fich);
		return;
	}
	fprintf(f, "%d\n", ens->nb);
	for (i = 0; i < ens->nb ; i++) {
		fprintf(f, "%s %d\n", nom_joueur(ens, i), billes_joueur(ens, i));
	}
}

/* Utilisé uniquement pour l'exercice complémentaire.
  Enregistre un sous-ensemble de joueurs dans un fichier portant le nom choisi.
  Le format du fichier est le même que pour les autres fichiers de
  joueurs lus ou écrits jusque là.
 */
void ecrire_les_elements(joueurs *e, int ens[], char *nom_fich) {
	return;
}
