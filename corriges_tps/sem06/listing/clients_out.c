/* Ecriture d'un fichier de clients */
void ecrire_les_clients(ensemble_clients *e, char * nom_fich) {
	FILE *f;
	int i;

	f = fopen(nom_fich, "w");
	if (f == NULL) {
		printf("%s n'a pas pu être ouvert en écriture\n", nom_fich);
		exit(1);
	}

	fprintf (f, "%d\n", e->nb);
	for (i=0; i<e->nb; i++) {
		fprintf (f, "%s %d\n", e->T[i].nom, e->T[i].compte);
	}

	fclose(f);
}
