#ifndef __VARIABLE_H__
#define __VARIABLE_H__

#include "common.h"

#define TAILLE_MAX_VALEUR 512

void initialiser_variables();
int trouver_variable(char *nom);
void affecter_variable(char *nom, char *valeur);
char *valeur_variable(char *nom);
int trouver_affectation_variable(char *ligne);
void appliquer_expansion_variables(char *ligne_originale, char *ligne_expansee);

#endif
