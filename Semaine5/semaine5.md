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
- La différence entre les deux est qu'`argc` compte le nom de l'exécutable dans la liste des arguments
- on a donc `argc = $# +1`

## Le type de argv

- argv est un double pointeur, ça veut dire quoi ?
- char * est le type d'une chaine de caractères.
- Notons string ce type et voyons ce que devient le type d'`argv` :

```C
int main(int argc, string argv[]);
```
- `argv` est donc un tableau de chaînes de caractères !

## argv

- `argv` permet de récupérer les paramètres passés au programme
- `argv` contient des paramètres de `argv[0]` jusqu'à `argv[argc-1]`
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

> I think the major good idea in Unix was its clean and simple interface: open, close, read, and write.
>
> -- <cite>Ken Thompson</cite>

- Ce sont des fonctions bas niveau
- Elles sont nécessaires mais pas très efficaces à utiliser directement
- On leur préfère des versions de plus haut niveau très efficaces

## La librairie C standard

Les 4 fonctions que l'on va utiliser pour cela sont :

- `fopen`
- `fwrite`
- `fread`
- `fclose`

- Ces fonctions enrobent les appels systèmes

## Documentation

Ces fonctions sont très bien documentées par les pages de manuel. Le cours ici se base sur ces pages de manuel accessibles grâce aux commandes :

```
man fopen
man fread
man feof
man fwrite
man fclose
```

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

## mode r

Le mode d'ouverture de `fopen` permet d'indiquer l'usage qu'on veut faire du fichier :

```
r      Open text file for reading.  The stream is 
positioned at the beginning of the file.

r+     Open for reading and writing.  The stream is 
positioned at the beginning of the file.
```

Attention : `r+` est un faux ami puisqu'il permet aussi l'écriture !

## mode w

```
w      Truncate file to zero length or create text file
for writing.  The stream is positioned at the beginning
of the file.

w+     Open for reading and writing.  The file is created 
if it does not exist, otherwise it is truncated.  The 
stream  is  positioned at the beginning of the file.
```

- `w` est destructif : il permet de remplacer le contenu du fichier
- `w+` permet la lecture. La différence avec `r+` est qu'il crée le fichier s'il n'existe pas

## mode a

```
a      Open  for  appending (writing at end of file). The
file is created if it does not exist.  The stream is
positioned at the end of the file.

a+     Open for reading and appending (writing at end of
file). The file is created if it does  not  exist. The 
initial file position for reading is at the beginning of
the file, but output is always appended to the end of the
file.
```

- `a` n'est pas destructif à l'inverse de `w` : on ajoute en fin de fichier

## Valeur de retour

```
Upon successful completion fopen(), fdopen() and freopen()
return a FILE pointer.  Otherwise, NULL is returned and 
errno  is  set to indicate the error.
```

```C
FILE *fopen(const char *path, const char *mode);
```

- Le * permet de vérifier que le type de retour est un pointeur, donc une adresse
- En cas d'erreur on renvoie NULL. En fait NULL est une adresse dont la valeur est zéro.
- errno permet d'avoir le détail de l'erreur, ce n'est pas utile dans un premier temps.

## FILE*

Cet objet contient 2 informations :

- Quel est le fichier ouvert ?
- A quel endroit on lit ou écrit dans le fichier ?

## Exemple d'utilisation

```C
FILE *f = fopen("etudiants.txt", "r");
if (f == NULL) {
	printf("Impossible d'ouvrir le fichier\n");
	return 1;
}
```

Bonne pratique : vérifier immédiatement après fopen si le pointeur renvoyé est utilisable

# fread

## Signature

```
NAME
       fread, fwrite - binary stream input/output

SYNOPSIS
       #include <stdio.h>

       size_t fread(void *ptr, size_t size, size_t nmemb,
                    FILE *stream);
```

## Description

```
DESCRIPTION
       The  function  fread()  reads nmemb elements of
       data, each size bytes long, from the stream pointed
       to by stream, storing them at the location given
       by ptr.
```

## Explication des arguments

- ptr est le tampon dans lequel on stocke les données lues.
- size est la taille d'un élément de base que l'on souhaite lire
- nmemb est le nombre d'éléments que l'on souhaite lire
- le total d'octets demandé est donc : `size x nmemb`
- stream est le pointeur de fichier depuis lequel on lit

## Valeur de retour

```
RETURN VALUE
       On  success, fread() and fwrite() return the number
       of items read or written.  This number equals the
       number of bytes transferred only when size is 1. If
       an error occurs, or the end of the file is reached,
       the return value is a short item count (or zero).

       fread() does not distinguish between end-of-file
       and error, and callers  must use feof(3) and
       ferror(3) to determine which occurred.
```

Attention : Bien noter que fread renvoie le nombre d'éléments lus et que cette valeur peut-être inférieure au nombre demandé !

## Exemple d'utilisation

On veut lire 32 octets d'un fichier :

```C
unsigned char buffer[32];

r = fread(buffer, 32, 1, f);
if (r != 1) {
	printf("Impossible de lire 32 octets dans le
	       fichier !\n");
	return 2;
}
```

# fwrite

## Signature

```
size_t fwrite(const void *ptr, size_t size, size_t nmemb,
                     FILE *stream);
```

- Même signature que `fread` à une différence : le buffer est const
- normal, quand on écrit le contenu d'un buffer on n'en change pas le contenu

## Valeur de retour

Même fonctionnement que `fread` : on demande à écrire un certain nombre d'éléments, fwrite renvoie le nombre d'éléments qu'il a en pratique réussi à écrire

## Exemple d'utilisation

```C
unsigned char bufferw[6] = "Remi\n";

r = fwrite(bufferw, 5, 1, f);
if (r != 1) {
	printf("Impossible d'ajouter Remi au fichier !\n");
}
```

# fclose

## Signature

```
NAME
       fclose - close a stream

SYNOPSIS
       #include <stdio.h>

       int fclose(FILE *fp);
```

## Utilisation

- Quand on ouvre un fichier avec fopen on prend une ressource
- fclose permet de fermer le fichier, c'est-à-dire qu'on libère la ressource
- La librairie C peut conserver des données dans ses buffers internes. fclose permet de s'assurer que ces buffers là sont bien vidés.

## Oubli de fclose

- L'oubli de fclose après un fopen est une erreur classique
- Si le programme termine normalement la librairie C regarde les `FILE*` ouverts restants et s'occupe de les fermer
- Problème : si le programme se termine anormalement ce mécanisme ne marche pas donc il y a un risque de perte de données
- Si on ouvre trop de fichiers sans les libérer au bout d'un moment on ne peut plus ouvrir de nouveaux fichiers. C'est une erreur vicieuse car elle se déclenche au bout d'un temps d'exécution long.

# Pour aller plus loin

## Recycler ses connaissances

- Pour le moment vous savez déjà utiliser certaines fonctions qui sont associées à un flux standard.
- En général il existe un équivalent générique permettant d'utiliser n'importe quel flux et donc n'importe quel fichier.

## printf / fprintf

```C
// Les deux appels suivants sont équivalents
printf("Toto\n");
fprintf(stdout, "Toto\n");

// mais fprintf peut aussi être utilisée pour écrire
// dans un fichier
FILE *file = fopen("etudiants.txt", "w");
fprintf(file, "Toto\n");
```

## scanf / fscanf

```C
char str1[20];

// Les deux appels suivants sont équivalents
scanf("%s", str1);
fscanf(stdin, "%s", str1);

// mais fscanf peut aussi être utilisée pour lire
// depuis un fichier
FILE *file = fopen("etudiants.txt", "w");
fscanf(file, "%s", str1);
```

Il existe sans doutes d'autres fonction spécialisées que vous savez déjà utiliser. Les pages de man vont permettront en général de trouver leur équivalent générique.

## Lecture incomplète

Quand on lit un fichier il est possible que l'on arrive pas à lire tout ce qu'on voulait. Il peut y avoir plusieurs raisons :

- On est à la fin du fichier
- Il y a eu une erreur

Si on a besoin de savoir ce qu'il en est on peut faire appel aux fonctions :

```C
       int feof(FILE *stream);
       int ferror(FILE *stream);
```

- si on est à la fin du fichier feof renvoie une valeur différente de 0
- s'il y a eu une erreur, ferror renvoie une valeur différente de 0

## Exercice

Ecrire un programme my_cp qui prend 2 paramètres exactement. Ces deux paramètres sont des noms de fichier, il recopie le contenu du premier vers le second. Si celui-ci n'existe pas, il est créé.
