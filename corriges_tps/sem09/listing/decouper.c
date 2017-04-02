void decouper_ligne(char *ligne, char *ligne_decoupee[]) {
	int i=0, nb_word = 0;
	int skip_sep = 0, skip_word = 0;

	while (ligne[i] != '\0') {
		if (ligne[i] == ' ' || ligne[i] == '\t') {
			skip_word = 0;
			if (skip_sep) {
				i++;
				continue;
			}

			ligne[i] = '\0';
			skip_sep = 1;
		} else {
			skip_sep = 0;
			if (skip_word) {
				i++;
				continue;
			}

			ligne_decoupee[nb_word] = &ligne[i];
			skip_word = 1;

			nb_word++;
		}
		i++;
	}

	ligne_decoupee[nb_word] = NULL;
}
