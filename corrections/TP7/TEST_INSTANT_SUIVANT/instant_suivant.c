#include <stdio.h>

typedef struct {
	int heure;
	int minute;
	int seconde;
} instant;

int main() {
	instant instant_courant, instant_suivant;

	scanf("%d:%d:%d", &instant_courant.heure,
	                  &instant_courant.minute,
	                  &instant_courant.seconde);

	instant_suivant.seconde = instant_courant.seconde + 1;
	if (instant_suivant.seconde == 60) {

		instant_suivant.seconde = 0;
		instant_suivant.minute = instant_courant.minute + 1;
		if (instant_suivant.minute == 60) {

		  instant_suivant.minute = 0;
		  instant_suivant.heure = instant_courant.heure + 1;
			if (instant_suivant.heure == 24) {
				instant_suivant.heure = 0;
			}

		} else {
			instant_suivant.heure = instant_courant.heure;
		}

	} else {
	  instant_suivant.minute = instant_courant.minute;
	  instant_suivant.heure = instant_courant.heure;
	}

	printf("%02d:%02d:%02d\n",
	       instant_suivant.heure, instant_suivant.minute, 
	       instant_suivant.seconde);

	return 0;
}
