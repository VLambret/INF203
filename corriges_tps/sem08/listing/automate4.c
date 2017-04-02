int load_automate (char * filename) {
	FILE * file = NULL;
	char buffer[10];
	int a=0, b=0, c=0, d=0;

	if (NULL == (file = fopen (filename, "r"))) {
		return 1;
	}
	fgets (buffer, 10, file);
	fclose (file);

	sscanf (buffer, "%d %d %d %d", &a, &b, &c, &d);
	if (invalide (a) ||
	    invalide (b) ||
	    invalide (c) ||
	    invalide (d)) {
		return 2;
	}

	// Init transitions with 0
	init_null ();
	init_sorties (d);

	transition[Q0][a] = 1;
	transition[Q1][a] = 1;
	transition[Q2][a] = 1;
	transition[Q3][a] = 1;
	transition[Q4][a] = 1;

	transition[Q1][b] = 2;
	transition[Q2][c] = 3;
	transition[Q3][d] = 4;

	return 0;
}
