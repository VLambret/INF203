#define NMAX 10

struct ensemble_entier {
	int nombre;
	int values[NMAX];
};

void init_ensemble_entier(struct ensemble_entier *e);

void ajouter_entier(struct ensemble_entier *e, int entier);

void print_ensemble_entier(struct ensemble_entier *e);
