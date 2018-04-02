# Correction TP8

Tout le code source modifié du TP est disponible dans le répertoire TP8

## Gestion de l'ensemble des joueurs

a) Le nom du type représentant un ensemble de joueurs est `joueurs` ou `struct ensemble_joueurs`. Dans cet ensemble les joueurs sont représentés comme un tableau de `joueur`, une structure qui est définie juste au dessus.
Le cardinal de cet ensemble est représenté par le champ nb de la structure. `NB_MAX_JOUEURS` est la capacité maximale de l'ensemble mais le nombre de joueurs peut-être inférieur à cette valeur, par exemple dans le cas d'un ensemble vide.
La taille du nom d'un joueur est limitée par la taille du tableau qui contient son nom qui est `TAILLE_MAX_NOM`

b)

![](https://github.com/VLambret/INF203/blob/master/corrections/TP8/graphe_dependances_TP8.png)

```Makefile
billes : billes.o generer_entier.o joueurs.o
	gcc billes.o generer_entier.o joueurs.o -o billes

billes.o : billes.c generer_entier.h joueurs.h
	gcc -c billes.c

joueurs.o : joueurs.c joueurs.h
	gcc -c joueurs.c

generer_entier.o : generer_entier.c
	gcc -c generer_entier.c
```

c) On teste en donnant le nom de 2 joueurs. On vérifie que deux joueurs différents ont bien des scores différents. Quand on recherche un joueur qui n'existe pas on doit avoir une erreur.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ ./billes toto tata
Copie successive des arguments dans l'ensemble :
 toto - tata -
 Ensemble de joueurs dans lequel la recherche est faite :
{ toto 196 tata 427 }
Qui voulez-vous ? toto
196
Qui voulez-vous ? tata
427
Qui voulez-vous ? titi
-- Joueur absent de l'ensemble
```

## Lecture et écriture d'un ensemble dans un fichier

d)

```C
#include "joueurs_out.h"

/*
  Enregistre l'ensemble de joueurs dans un fichier portant le nom choisi.
  Le contenu du fichier devra suivre rigoureusement le format :
  - sur la première ligne, le nombre de joueurs de l'ensemble
  - puis, sur chaque ligne, un nom de joueur, une espace et son nombre de billes
 */
void ecrire_les_joueurs(joueurs *ens, char *nom_fich) {
	FILE *f;
	int i;

	f = fopen(nom_fich, "w");
	if (f == NULL) {
		fprintf(stderr, "Impossible de créer le fichier %s\n", nom_fich);
		return;
	}
	fprintf(f, "%d\n", ens->nb);
	for (i = 0; i < ens->nb ; i++) {
		fprintf(f, "%s %d\n", nom_joueur(ens, i), billes_joueur(ens, i));
	}
}

/* Utilisé uniquement pour l'exercice complémentaire.
  Enregistre un sous-ensemble de joueurs dans un fichier portant le nom choisi.
  Le format du fichier est le même que pour les autres fichiers de
  joueurs lus ou écrits jusque là.
 */
void ecrire_les_elements(joueurs *e, int ens[], char *nom_fich) {
	return;
}
```

e) Pour vérifier que le Makefile est correct on relance la commande make. Elle doit recompiler de nouveaux fichiers. On en profite pour lancer l'exécutable produit et quitter pour vérifier que le fichier est bien créé et que son contenu est bien formaté pour être sûr que la recompilation a bien utilisé le nouveau code.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ make
gcc -c billes.c
gcc -c joueurs_out.c
gcc billes.o generer_entier.o joueurs.o joueurs_out.o -o billes
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ ./billes toto tata
Copie successive des arguments dans l'ensemble :
 toto - tata -
 Ensemble de joueurs dans lequel la recherche est faite :
{ toto 198 tata 121 }
Qui voulez-vous ? q
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ cat Fichier_Joueurs 
2
toto 198
tata 121
```

f) Le contenu du fichier n'est pas modifié car pour le moment on réécrit ce que l'on vient de lire du fichier sans le modifier.
On peut le vérifier en affichant le contenu du fichier avant et apres exécution.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ cat Fichier_Joueurs 
2
toto 175
tata 50
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ ./billes

Ensemble de joueurs dans lequel la recherche est faite :
{ toto 175 tata 50 }
Qui voulez-vous ? 
q
lambret@debian-sogilis:~/INF203/INF203/corrections/TP8$ cat Fichier_Joueurs 
2
toto 175
tata 50
```














