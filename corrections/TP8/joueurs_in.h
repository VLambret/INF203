#ifndef __JOUEURS_IN_H__
#define __JOUEURS_IN_H__
#include <stdio.h>
#include "joueurs.h"

/*
  Lit un ensemble de joueurs depuis un fichier portant le nom choisi.
  Le contenu du fichier doit suivre rigoureusement le format :
  - sur la première ligne, le nombre de joueurs de l'ensemble
  - puis, sur chaque ligne, un nom de joueur, une espace et son nombre de billes
 */
void lire_les_joueurs(joueurs *ens, char *nom_fich);

#endif
