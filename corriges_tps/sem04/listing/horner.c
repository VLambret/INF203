/**
 * Fichier de démonstration pour l'Université Grenoble Alpes
 *
 * @autor <corentin@marciau.fr>
 */

#include <stdio.h>
#include <stdlib.h>

int mon_atoi (char num[]) {
	int i = 0;
	int resultat = 0;

	while (num[i] != '\0') {
		int digit = num[i] - '0';
		resultat = (resultat * 10) + digit;
		i++;
	}

	return resultat;
}

int main (int argc, char *arcv[]) {
	char input[10] = "";

	printf ("Entrez un nombre : \n");
	scanf ("%s", input);

	int resultat = mon_atoi (input);
	printf ("Vous avez entré : %d\n", resultat);

	return 0;
}
