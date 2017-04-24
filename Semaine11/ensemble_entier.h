#define NMAX 10

struct ensemble_entier {
	int nombre;
	int values[NMAX];
};

void init_ensemble_entier(struct ensemble_entier *e);

void ajouter_entier(struct ensemble_entier *e, int entier);

void print_ensemble_entier(struct ensemble_entier *e);

/* Sous ensemble */

void sous_ensemble_multiple(struct ensemble_entier *e,
                            int *sous_ensemble,
                            int multiple);

void se_union(int *se1, int *se2,
           int *se_union);

void se_intersection(int *se1, int *se2,
           int *se_intersection);

void print_sous_ensemble(struct ensemble_entier *e, int sous_ensemble[NMAX]);
