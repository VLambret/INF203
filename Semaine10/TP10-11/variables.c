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

/*************** A COMPLETER ******************/
    /*
      Fonction qui recherche le nom de variable donne dans le tableau des noms
      des variables definies. Si le nom est trouve, la fonction retourne
      l'indice correspondant dans le tableau, dans le cas
      contraire elle retourne -1.
    */
/**********************************************/
    return i;
}

void initialiser_variables() {
/*************** A COMPLETER ******************/
    /* 
      Initialiser une table vide
    */
/**********************************************/
}

void affecter_variable(char *nom, char *valeur) {
/*************** A COMPLETER ******************/
    /*
      Fonction qui affecte la valeur donnee au nom de variable donne.
      Si la variable existe deja dans les variables definies, il suffit juste
      de changer sa valeur. Dans le cas contraire, il faut l'ajouter aux
      variables definies : ajouter son nom a la fin du tableau des noms de
      variables et sa valeur a la fin du tableau des valeurs.
    */
/**********************************************/
}

char *valeur_variable(char *nom) {
/*************** A COMPLETER ******************/
    /*
      Fonction qui retourne la valeur de la variable de nom donne, ou une
      valeur vide si la variable n'est pas definie.
    */
/**********************************************/
    return valeur_vide;
}

int trouver_affectation_variable(char *ligne) {
/*************** A COMPLETER ******************/
    /*
      trouver_affectation_variable
      Fonction qui cherche a reconnaitre une affectation de variable dans le 
      morceau de ligne de commande transmise. 
      Pour cela il faut determiner si ce morceau de
      ligne decoupee est de la forme :
      nom=valeur
      Cette fonction est destructive : elle modifie ligne lorsqu'elle
      trouve une affectation. Retourne 1 en cas d'affectation trouvee, 0 dans le
      cas contraire.
    */
/**********************************************/
return 0 ;
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
