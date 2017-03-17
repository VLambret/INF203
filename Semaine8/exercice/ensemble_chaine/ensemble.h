
#define MAX_SIZE 8

struct ensemble {
	unsigned int cardinal;
	int elements[MAX_SIZE];
};


void print_ensemble(struct ensemble *e);

/* Cette fonction initialise l'ensemble à l'ensemble vide */
void init_empty(struct ensemble *e);

/* Cette fonction initialise l'ensemble à partir d'un fichier formaté avec un entier par ligne */
int init_from_file(struct ensemble *e, char *filename);

/* Cette fonction vérifie si l'entier n est dans l'ensemble e
 * elle renvoie 1 si il est présent, -1 sinon
 */
int check_presence(struct ensemble *e, int n);

/* Cette fonction ajoute l'entier n à l'ensemble.
 * Elle renvoie 1 si l'insertion est un succès, -1 sinon
 */
int add_element(struct ensemble *e, int n);

/* Cette fonction supprimer l'entier n de l'ensemble
 * Elle renvoie 1 si la suppression est un succès, -1 sinon
 */
int remove_element(struct ensemble *e, int n);
