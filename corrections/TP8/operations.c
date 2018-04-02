#include <stdio.h>

#include "joueurs.h"
#include "operations.h"

int gain(joueurs *e) {
	char nom[TAILLE_MAX_NOM] ;
	int i, solde, depose ;

	printf("Nom du joueur et billes gagnées ? ") ;
	scanf("%s %d", nom, &depose) ;
	i = trouver_joueur(e, nom) ;
	if (i == -1) { 
		printf("Inconnu\n") ; return 1 ;
	}
	solde = billes_joueur(e, i) ;
	solde = solde + depose ;
	modifier_billes(e, i, solde) ;
	return 0 ;
}

int perte(joueurs *e) {
	char nom[TAILLE_MAX_NOM] ;
	int i, solde, retire ;

	printf("Nom du joueur et billes perdues ? ") ;
	scanf("%s %d", nom, &retire) ;
	i = trouver_joueur(e, nom) ;
	if (i == -1) { 
		printf("Inconnu\n") ; return 1 ;
	}
	solde = billes_joueur(e, i) ;
	solde = solde - retire ;
	modifier_billes(e, i,solde) ;
	return 0 ;
}

/* Lecture du nom du joueur a debiter, du nom
   du joueur a crediter, et du montant du transfert.
   Mise a jour des deux comptes.*/
int transfert(joueurs *e) {
	char nom_debiteur[TAILLE_MAX_NOM] ;
	char nom_crediteur[TAILLE_MAX_NOM] ;
	int indice_debiteur, indice_crediteur, montant, solde_crediteur, solde_debiteur;

	printf("Nom du joueur debiteur et billes perdues ? ") ;
	scanf("%s %d", nom_debiteur, &montant) ;
	indice_debiteur = trouver_joueur(e, nom_debiteur) ;
	if (indice_debiteur == -1) { 
		printf("Debiteur inconnu\n") ; return 1 ;
	}

	printf("Nom du joueur crediteur ?") ;
	scanf("%s", nom_crediteur);
	indice_crediteur= trouver_joueur(e, nom_crediteur) ;
	if (indice_crediteur== -1) { 
		printf("Crediteur inconnu\n") ; return 1 ;
	}

	solde_crediteur = billes_joueur(e, indice_crediteur) + montant;
	solde_debiteur = billes_joueur(e, indice_debiteur) - montant;
	modifier_billes(e, indice_crediteur,solde_crediteur);
	modifier_billes(e, indice_debiteur,solde_debiteur);

	return 0 ;
}
