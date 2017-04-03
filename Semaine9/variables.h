#pragma once

#define NOMBRE_MAX_VARIABLES 512
#define TAILLE_MAX_NOM 128
#define TAILLE_MAX_VALEUR 512

/* Initialise les structures de données contenant les variables */
void initialiser_variables();

/* Renvoie l'indice de la variable dont le nom est passé en paramètre.
 * Si aucune variable de ce nom n'existe renvoie -1 */
int trouver_variable(char *nom);

char *valeur_variable(char *nom);

void affecter_variable(char *nom, char *valeur);
