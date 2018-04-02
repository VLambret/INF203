#include "joueurs_out.h"

/*
  Lit un ensemble de joueurs depuis un fichier portant le nom choisi.
  Le contenu du fichier doit suivre rigoureusement le format :
  - sur la première ligne, le nombre de joueurs de l'ensemble
  - puis, sur chaque ligne, un nom de joueur, une espace et son nombre de billes
 */
void lire_les_joueurs(joueurs *ens, char *nom_fich) {
	FILE *f;
	int nombre_joueurs;
	int scanf_err;
	char buf_pseudo[TAILLE_MAX_NOM] ;
	int nombre_billes;
	int i;

	init_joueurs(ens);

	f = fopen(nom_fich, "r");
	if (f == NULL) {
		fprintf(stderr, "Impossible d'ouvrir le fichier %s\n", nom_fich);
		return;
	}

	scanf_err = fscanf(f, "%d\n", &nombre_joueurs);
	if (scanf_err != 1) {
		fprintf(stderr, "Impossible de lire le nombre de joueurs du fichier %s\n", nom_fich);
		return;
	}
	for (i = 0; i < nombre_joueurs ; i++) {
		scanf_err = fscanf(f, "%s %d\n", buf_pseudo, &nombre_billes);
		if (scanf_err != 2) {
			fprintf(stderr, "%s : Format incorrect pour le joueur %d\n", nom_fich, i);
			return;
		}
		ajouter_joueur(ens, buf_pseudo, nombre_billes);
	}
}
