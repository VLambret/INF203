#include <stdio.h>

int main()
{
	FILE* f;
	unsigned char bufferr[32];
	unsigned char bufferw[6] = "Remi\n";
	size_t r = 0;

	f = fopen("etudiants.txt", "a+");
	if (f == NULL) {
		printf("Impossible d'ouvrir le fichier\n");
		return 1;
	}

	r = fread(bufferr, 32, 1, f);
	if (r != 1) {
		printf("Impossible de lire 32 octets dans le fichier !\n");
	}

	r = fwrite(bufferw, 5, 1, f);
	if (r != 1) {
		printf("Impossible d'ajouter Remi au fichier !\n");
	}

	fclose(f);

	return 0;
}
