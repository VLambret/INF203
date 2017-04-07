#include <stdio.h>
#include <string.h>
#define TAILLE 24

int main() {
char entier[TAILLE] ;
int e ;
char morceau[TAILLE] ;
char bout_a_bout[TAILLE] ;
int lg=0 ; /* lg=longueur occupee dans bout_a_bout */
int i ;

printf("un entier ?\n") ;
scanf("%d", &e) ;
sprintf(entier, "%d", e) ;
printf(" voici l'entier : %d    et la chaine %s\n", e, entier) ;

strcpy(bout_a_bout, "") ; lg++ ;
for (i=1 ; i<=5 ; i++) {
	printf("morceau numero %d ? (de longueur <= %d)\n", i, TAILLE-lg) ;
	scanf("%s", morceau) ;
	if (strlen(morceau) <= TAILLE-lg) {
		strcat(bout_a_bout, morceau) ;
		lg = lg + strlen(morceau) ;
		}
	else
		printf("perdu ! c'est trop long !\n") ;
	}

printf("bout a bout fait %s\n", bout_a_bout) ;
return 0 ;

}

