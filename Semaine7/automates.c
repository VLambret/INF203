#include <stdio.h>

// entrees
#define Pile 0
#define Face 1

// sorties
#define A_Vainqueur 0
#define B_Vainqueur 1
#define Rien 2

// Etats
#define Init 0 
#define Avg_A 1
#define Avg_B 2
#define A_Gagne 3
#define B_Gagne 4

int f_transition[5][2] = {
	/* de Init */           {Avg_A, Avg_B},
	/* de Avg_A */          {A_Gagne, Init},
	/* de Avg_B  */         {Init, B_Gagne},
	/* de A_Gagne */        {A_Gagne, A_Gagne},
	/* de B_Gagne  */       {B_Gagne, B_Gagne}
} ;

int f_sortie[5][2] = {
	/* de Init */           {Rien, Rien},
	/* de Avg_A */          {A_Vainqueur, Rien},
	/* de Avg_B */          {Rien, B_Vainqueur},
	/* de A_Gagne */        {Rien, Rien},
	/* de B_Gagne */        {Rien, Rien}
} ;
int lire_entree() {
	char cc ;

	do
		scanf("%c", &cc) ;
	while ((cc != 'P') && (cc != 'F')) ;

	if (cc == 'P') return Pile ;
	else return Face ;
}

void traiter_sortie (int message) {
	switch (message) {
		case A_Vainqueur : printf("Victoire de Anemone (Pile)\n") ; break ;
		case B_Vainqueur : printf("Victoire de Barnabe (Face)\n") ; break ;
		default : break ;
	}
}

int Est_final(int etat) {
	return ((etat == A_Gagne) || (etat == B_Gagne)) ;
}

void simul_automate() {
	int etat_courant, etat_suivant ;
	int entree, sortie ;

	etat_courant = Init ;
	while (! Est_final(etat_courant)) {
		entree = lire_entree() ;
		sortie = f_sortie[etat_courant][entree] ;
		etat_suivant = f_transition[etat_courant][entree] ;
		traiter_sortie(sortie) ;
		etat_courant = etat_suivant ;
	}
}

int main() {
	simul_automate() ;
	return 0 ;
}
