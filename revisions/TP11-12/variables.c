#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "variables.h"
#include "systeme.h"

#define NOMBRE_MAX_VARIABLES 512
#define TAILLE_MAX_NOM 128
/* defini dans variables.h
#define TAILLE_MAX_VALEUR 512
*/

int nombre_variables;
char noms_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_NOM];
char valeurs_variables[NOMBRE_MAX_VARIABLES][TAILLE_MAX_VALEUR];
char *valeur_vide="";

int trouver_variable(char *nom) {
    int i=0;

    debug(printf("Je cherche la variable %s\n", nom));
    while ((i < nombre_variables) && (strcmp(nom, noms_variables[i]) != 0))
        i++;
    if (i >= nombre_variables) {
        debug(printf("Je ne la trouve pas\n"));
        i = -1;
    } else {
        debug(printf("Je la trouve en position %d\n", i));
    }
    return i;
}

void initialiser_variables() {
    nombre_variables = 0;
}

void affecter_variable(char *nom, char *valeur) {
    int i;

    i = trouver_variable(nom);
    if (i == -1) {
            i = nombre_variables;
            strcpy(noms_variables[i], nom);
            nombre_variables++;
    }
    strcpy(valeurs_variables[i], valeur);
    debug(printf("Affectation de la variable %s a la valeur %s\n",
          noms_variables[i], valeurs_variables[i]));
}

char *valeur_variable(char *nom) {
    int i;

    i = trouver_variable(nom);
    if (i == -1)
        return valeur_vide;
    else
        return valeurs_variables[i];
}

int trouver_affectation_variable(char *ligne) {
    int j;
    char *nom;
    char *nouvelle_valeur;

    j = 0;
    nom = &ligne[0];
    while ((ligne[j] != '=') && (ligne[j] != '\0')) {
        j++;
    }
    if (ligne[j] == '=') {
        ligne[j] = '\0';
        j++;
        nouvelle_valeur = &ligne[j];
        affecter_variable(nom, nouvelle_valeur);
        return 1;
    } else {
        return 0;
    }
}

/*************** A COMPRENDRE *****************/
/*
  appliquer_expansion_variables
  Fonction qui prend une ligne lue en parametre et la recopie dans le tableau
  resultat en remplacant toutes les utilisations de variable (de la forme
  '$nom' ou nom est une chaine de caracteres alphanumeriques ou * ou #) par la
  valeur de la variable correspondante.
*/
void appliquer_expansion_variables(char *ligne_originale,
                                   char *ligne_expansee) {
    char *nom, *valeur, caractere_ecrase;
    int i, j;

    i = 0;
    j = 0;
    while (ligne_originale[i] != '\0') {
        if (ligne_originale[i] == '$') {
            i++;
            nom = &ligne_originale[i];
            switch (ligne_originale[i]) {
              case '*':
              case '#':
                i++;
                break;
              default:
                while (isalnum(ligne_originale[i]))
                    i++;
            }
            caractere_ecrase = ligne_originale[i];
            ligne_originale[i] = '\0';
            if (nom[0] == '\0') {
                ligne_expansee[j] = '$';
                j++;
            } else {
                valeur = valeur_variable(nom);
                strcpy(&ligne_expansee[j], valeur);
                j += strlen(valeur);
            }
            ligne_originale[i] = caractere_ecrase;
        } else {
            ligne_expansee[j] = ligne_originale[i];
            i++;
            j++;
        }
    }
    ligne_expansee[j] = '\0';
}
/**********************************************/
