#pragma once

#define NOMBRE_MAX_VARIABLES 512
#define TAILLE_MAX_NOM 128
#define TAILLE_MAX_VALEUR 512

/* Initialise les structures de données contenant les variables */
void initialiser_variables();

/* si la variable existe renvoie 1, sinon -1 */
int trouver_variable(char *nom);

char *valeur_variable(char *nom);

void affecter_variable(char *nom, char *valeur);
