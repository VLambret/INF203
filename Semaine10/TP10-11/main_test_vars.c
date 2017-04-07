#include <stdio.h>
#include <stdlib.h>

#include "variables.h"

int main(int argc, char *argv[]) {
int i ;
char val[512] ;

    if (argc<2) {
	printf("ce programme necessite un argument au moins\n") ;
        exit(1) ;
	}

    initialiser_variables() ;
    for (i=1 ; i<argc ; i++) {
	printf("valeur de %s ?\n", argv[i]) ;
	scanf("%s", val) ;
	affecter_variable(argv[i], val) ;
	}

    for (i=1 ; i<argc ; i++) {
	if (trouver_variable(argv[i]) == -1) {
		printf("PROBLEME ! %s n'a pas ete trouvee dans la table\n", argv[i]) ;
		}
	else {
		printf("%s vaut %s\n", argv[i], valeur_variable(argv[i])) ;
		}

	}
     affecter_variable(argv[1], "INF123 C'est SUPER !!!") ;

     printf("%s\n", valeur_variable(argv[1])) ;
    return 0;
}
