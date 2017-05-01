#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "commandes.h"
#include "systeme.h"
#include "common.h"
#include "interpreteur.h"

/********* Etats de l'Automate ************/
#define NB_ETATS 12

/* Gestion du if/then/else/fi */
#define NORMAL 0
#define ATTENTE_THEN_VRAI   1
#define ATTENTE_THEN_FAUX   2
#define DANS_THEN 3
#define DANS_ELSE 4
#define ATTENTE_FI 5
#define ATTENTE_ELSE_OU_FI 6
#define ERREUR 7

/* Gestion du while/do/done */
#define ATTENTE_DO_VRAI 8
#define ATTENTE_DO_FAUX 9
#define DANS_DO 10
#define ATTENTE_DONE 11

/********* Entrees de l'Automate *************/
#define NB_ENTREES 12

/* Gestion du if/then/else/fi */
#define IF 0
#define THEN 1
#define ELSE 2
#define FI 3
#define INSTRUCTION 4
#define IF_VRAI 5
#define IF_FAUX 6

/* Gestion du while/do/done */
#define WHILE 7
#define DO 8
#define DONE 9
#define WHILE_VRAI 10
#define WHILE_FAUX 11

/********* Sorties de l'Automate (resultat de commandes_internes) ************/
#define NON 0   /* ne pas executer */
#define OUI 1   /* ligne a executer */
#define BOUCLE 2 /* revenir au while */

int transition[NB_ETATS][NB_ENTREES];
int sortie[NB_ETATS][NB_ENTREES];
int etat;

char *mnemonique[] = {"if", "then", "else", "fi", "while", "do", "done"};
int valeur_mnemonique[] = {IF, THEN, ELSE, FI, WHILE, DO, DONE};

int decode_entree(char *mot) {
/* comparer la chaine mot passee en parametre aux mnemoniques, retourner la
valeur du mnemonique si le mot est un mnemonique, retourner INSTRUCTION sinon */
/** A COMPLETER **/
        return INSTRUCTION;
}

void initialiser_commandes() {
    int i, j;

    /* La majorite des transitions vont dans l'etat d'erreur et la sortie est
       majoritairement NON
    */
    for (i=0 ; i<NB_ETATS ; i++)
        for (j=0 ; j<NB_ENTREES ; j++) {
            transition[i][j]=ERREUR;
            sortie[i][j]=NON ;
        }

    transition[NORMAL][INSTRUCTION] = NORMAL;
    sortie[NORMAL][INSTRUCTION] = OUI;

/******* transitions ******************************************************/
/** toutes les transitions qui ne sont pas egales a la valeur par defaut **/
/** A COMPLETER **/

/******* sorties ******************************************************/
/** toutes les sorties qui ne sont pas egales a la valeur par defaut **/
/** A COMPLETER **/

/**** etat initial ******************************/
    etat = NORMAL;
}

int analyse_commande_interne(char *ligne_courante) {
    char *premier_mot, caractere_supprime;
    int entree, code_sortie=OUI, resultat_test;
    int i, fin_premier_mot;

    /*
      On extrait d'abord le premier mot de la ligne pour voir si c'est un
      mnemonique de commande interne
    */
    i=0;
    while (isspace(ligne_courante[i]))
        i++;
    premier_mot = &ligne_courante[i];
    while (!isspace(ligne_courante[i]) && (ligne_courante[i] != '\0'))
        i++;
    fin_premier_mot = i;
    caractere_supprime = ligne_courante[fin_premier_mot];
    ligne_courante[fin_premier_mot] = '\0';
 
    /* On essaie de reconnaitre une commande interne */
    entree = decode_entree(premier_mot);
    if (entree != INSTRUCTION) {
        /*
          Si on a reconnu un mnemonique, on l'affiche (en mode debug)
        */
        debug(printf("Commande interne reconnue : %s\n", premier_mot));
        /*
          La ligne courante devient ce qui reste apres le premier mot :
          - rien si on etait deja a la fin
          - ce qui suit sinon
        */
        if (caractere_supprime == '\0')
            ligne_courante = &ligne_courante[fin_premier_mot];
        else
            ligne_courante = &ligne_courante[fin_premier_mot+1];
    } else {
        /* Sinon, le ligne de commande redevient ce qu'elle etait avant */
        ligne_courante[fin_premier_mot] = caractere_supprime;
    }

    if (entree == IF) {
        /*
          Dans le cas du if, il faut tout de suite executer le reste de la
          ligne pour recuperer le resultat du test. Dans ce cas le code de
          sortie sera NON (puisqu'on execute la fin de ligne pour le test)
        */
        resultat_test = executer_ligne_commande(ligne_courante);
        code_sortie = NON;
        /* l'entree devient IF_VRAI ou IF_FAUX selon le resultat du test */
        debug(printf("Resultat du test : "));
        if (resultat_test) {
            entree = IF_FAUX ;
            debug(printf("FAUX\n"));
        } else {
            entree = IF_VRAI ;
            debug(printf("VRAI\n"));
        }
    }

/****** calculer code_sortie et changer d'etat en fonction
        de etat_courant et de entree ********************/
/** A COMPLETER **/

    switch (code_sortie) {
      case OUI:
        /*
          Dans le cas d'une ligne de commande contenant un mnemonique de commande
          interne, on execute, s'il y a lieu, la fin de ligne. Sinon, on laisse
          la fonction appelante executer la ligne selon le code de sortie.
        */
        if (entree != INSTRUCTION) {
            executer_ligne_commande(ligne_courante);
            return NON;
        } else {
            return code_sortie;
        }
      default:
        return code_sortie;
    }
}
