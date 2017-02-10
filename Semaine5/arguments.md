% INF203 - Arguments de la ligne de commande
% Victor Lambret
% 2017 - https://github.com/VLambret/INF203

# Les arguments en C

## Signature simple du main

- En C on peut utiliser comme fonction principale la fonction `main` suivante :
- main est la première fonction appelée par le programme

```C
int main() {
```

## Signature étendue du main

- Comme n'importe quel exécutable un programme C compilé peut être lancé avec des paramètres
- la fonction `main` est alors l'endroit logique ou l'on souhaite les récupérer
- En fait main accepte aussi une seconde signature qui permet de récupérer les paramètres :

```C
// Les deux notations sont équivalentes
int main(int argc, char *argv[]) {
int main(int argc, char **argv) {
```

## argc

- `argc` est un entier, il compte le nombre de paramètres au lancement de la commande
- Son équivalent en bash est `$#`
- La différence entre les deux est qu'`argc`compte le nom de l'exécutable dans la liste des arguments
- on a donc `argc = $# +1`

## Le type de argv

- argv est un double pointeur, ça veut dire quoi ?
- char * est le type d'une chaine de caractères.
- Notons string ce type et voyons ce que devient le type d'`argv` :

```C
int main(int argc, string argv[]);
```
- `argv` est donc un tableau de chaîne de caractères !

## argv

- `argv` permet de récupérer les paramètres passés au programme
- `argv` contient des paramètres de `argv[0]` jusqu'à `argv[argc -1]`
- `argv[0]` contient le nom de l'exécutable, comme `$0` en bash

## Exercice

A partir du programme mon_atoi.c écrit la semaine précédente, écrire un programme qui affiche la valeur numérique de tous ses paramètres

# Manipulation de fichiers

## Limitation des entrées/ sorties standard

Rappel : par défaut tout programme démarre avec :

- stdin, l'entrée standard
- stdout, la sortie standard
- stderr, la sortie d'erreur

Ces 3 fluxs sont suffisants pour des programmes simples. Pour des programmes plus complexes on a besoin de plus d'entrées sorties, en particulier vers des fichiers.

## Le modèle de fichier Unix

Dans Unix la manipulation des fichiers repose sur 4 opérations très simples :

- on ouvre un fichier
- on écrit dans un fichier
- on lit dans un fichier
- on ferme un fichier

## Les appels systèmes


- Ce sont des fonctions bas niveau
- Elles sont nécessaires mais pas très efficaces à utiliser directement
- On leur préfère des versions de plus haut niveau très efficaces

## La librairie C standard

Les 4 fonctions que l'on va utiliser pour cela sont :

- `fopen`
- `fwrite`
- `fread`
- `fclose`

- Ces fonctions emrobent les appels systèmes
- elles sont très bien documentées par man

# fopen

## signature

```
NAME
fopen, fdopen, freopen - stream open functions

SYNOPSIS
#include <stdio.h>

FILE *fopen(const char *path, const char *mode);
```

## Utilisation d'un fichier

Quand un programme ouvre un fichier il peut en faire plusieurs usages :

- Le lire
- écraser son contenu
- ajouter du contenu à la fin
- le créer

## mode lecture

Le mode d'ouverture de `fopen` permet d'indiquer l'usage qu'on veut faire du fichier :

```
r      Open text file for reading.  The stream is positioned at the beginning of the file.

r+     Open for reading and writing.  The stream is positioned at the beginning of the file.
```

## mode écriture

```
w      Truncate file to zero length or create text file for writing.  The stream is positioned at the beginning of the file.

w+     Open for reading and writing.  The file is created if it does not exist, otherwise it is truncated.  The stream  is  posi‐
tioned at the beginning of the file.
```

## mode ajout

```
a      Open  for  appending (writing at end of file).  The file is created if it does not exist.  The stream is positioned at the
end of the file.

a+     Open for reading and appending (writing at end of file).  The file is created if it does  not  exist.   The  initial  file
position for reading is at the beginning of the file, but output is always appended to the end of the file.
```



