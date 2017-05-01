#include <string.h>
#include <sys/stat.h>
#include <stdio.h>
#include "gestion_path.h"
#include "common.h"

#include "variables.h"

#define NOMBRE_MAX_CHEMINS 128
#define TAILLE_MAX_CHEMIN 128

static char liste_chemins[NOMBRE_MAX_CHEMINS][TAILLE_MAX_CHEMIN];
static int nombre_chemins;
static char commande_finale[TAILLE_MAX_LIGNE+TAILLE_MAX_CHEMIN];

void initialiser_path() {
    strcpy(liste_chemins[0], "/bin");
    strcpy(liste_chemins[1], "/usr/bin");
    nombre_chemins = 2;
    affecter_variable("PATH", "/bin:/usr/bin");
}

static void mettre_a_jour_path() {
    char *valeur = valeur_variable("PATH");
    int i, j, k, terminer_courant = 0;
    i = 0;
    j = 0;
    k = 0;
    while ((valeur[k] != '\0') && (i < NOMBRE_MAX_CHEMINS)) {
        if (valeur[k] == ':') {
            terminer_courant = 1;
        } else {
            liste_chemins[i][j] = valeur[k];
            j++;
            if (j >= TAILLE_MAX_CHEMIN-1) {
                fprintf(stderr, "Erreur : chemin trop long dans le PATH, "
                                "fin ignoree\n");
                while ((valeur[k] != '\0') && (valeur[k] == ':'))
                    k++;
                terminer_courant = 1;
            }
        }
        if (terminer_courant) {
            liste_chemins[i][j] = '\0';
            i++;
            j = 0;
            terminer_courant = 0;
        }
        k++;
    }
    liste_chemins[i][j] = '\0';
    if (j > 0)
        i++;
    nombre_chemins = i;
}

char *trouver_commande(char *nom) {
    int trouve, i;
    struct stat infos;

    mettre_a_jour_path();
    if ((nom == NULL) || (index(nom, '/') != NULL)) {
        /* Commande vide ou chemin donne par l'utilisateur : */
        // on utilise pas le path */
        return nom;
    } else {
        /* On cherche le bon chemin dans le path */
        trouve = 0;
        i = 0;
        while (!trouve && (i < nombre_chemins)) {
            strcpy(commande_finale, liste_chemins[i]);
            strcat(commande_finale, "/");
            strcat(commande_finale, nom);

            /* Si le fichier existe et est executable */
            debug(printf("J'examine %s\n", commande_finale));
            if ((stat(commande_finale, &infos) != -1) &&
                ((infos.st_mode & S_IXUSR) != 0)) {
                trouve = 1;
            }
            i++;
        }
    }

    if (trouve) {
        debug(printf("Commande trouvee : %s\n", commande_finale));
        return commande_finale;
    } else {
        fprintf(stderr, "Impossible de trouver la commande %s\n",
                nom);
        return nom;
    }
}
