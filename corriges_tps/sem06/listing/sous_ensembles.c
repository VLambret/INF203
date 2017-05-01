#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clients.h"
#include "clients_out.h"
#include "clients_in.h"

void clients_debiteurs(ensemble_clients *e, int ens[]) {
	int i;
	for (i=0; i < nombre_de_clients(e); i++) {
		if (compte_client(e, i) < 0) {
			ens[i] = 1;
		} else {
			ens[i] = 0;
		}
	}
}

void clients_trop_riches (ensemble_clients *e, int ens[]) {
	int i;
	for (i=0; i<nombre_de_clients(e); i++) {
		if (compte_client(e, i) > 1000000) {
			ens[i] = 1;
		} else {
			ens[i] = 0;
		}
	}
}

void clients_avec_compte_rond (ensemble_clients *e, int ens[]) {
	int i;
	for (i=0; i<nombre_de_clients(e); i++) {
		if (compte_client (e, i) % 100 == 0) {
			ens[i] = 1;
		} else {
			ens[i] = 0;
		}
	}
}

void dixieme_client (ensemble_clients *e, int ens[]) {
	int i = 0;
	for (i=0; i<nombre_de_clients (e); i++) {
		ens[i] = 0;
	}

	int heureux_gagnant = 10;
	if (nombre_de_clients (e) > heureux_gagnant) {
		ens[heureux_gagnant] = 1;
	}
}

int main(int argc, char *argv[]) {
	int sous_ens_clients[NB_MAX];
	ensemble_clients e;

	if (argc != 1 + 5) {
		printf("syntaxe : %s fich_clients_entree fich_fauche"
		       " fich_riches fich_comptes_rond fich_gagnant\n",
		       argv[0]);
		exit(1);
	}
	lire_les_clients(&e, argv[1]);
	afficher_les_clients(&e);

	/* calcul du sous-ensemble des clients debiteurs */
	clients_debiteurs(&e, sous_ens_clients);
	ecrire_les_elements(&e, sous_ens_clients, argv[2]);

	/* calcul du sous-ensemble des clients trop riches */
	clients_trop_riches(&e, sous_ens_clients);
	ecrire_les_elements(&e, sous_ens_clients, argv[3]);

	/* calcul du sous-ensemble des clients racistes */
	clients_avec_compte_rond (&e, sous_ens_clients);
	ecrire_les_elements(&e, sous_ens_clients, argv[4]);

	/* calcul du sous-ensemble des clients racistes */
	dixieme_client (&e, sous_ens_clients);
	ecrire_les_elements(&e, sous_ens_clients, argv[5]);

	return 0;
}
