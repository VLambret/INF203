% INF203 - Makefiles
% Victor Lambret
% 2017

# Le besoin

## La compilation séparée

- Avec la compilation séparée on ne recompile pas tout le projet après une modification
- Idéalement, on voudrait même ne recompiler que ce qui est nécessaire !
- Recompiler tout à la main c'est facile.
- Recompiler ce qui est nécessaire à la main c'est compliqué.
- Facilitons nous la vie !

## Quand recompiler ?

- Quand on modifie le code source il faut recompiler le programme
- Il faut des règles pour savoir ce qui faut recompiler !
- Ces règles dépendent du type de fichier

## Modification d'un fichier.c

- Quand on modifie un fichier.c on doit recompiler le fichier.o associé
- Comme on modifie le fichier.o on doit recompiler le programme complet qui est compilé à partie des fichiers .o

## Modification d'un fichier.h

- Quand on modifie un fichier.h on modifie en général l'interface public de fonctions
- On veut recompiler le fichier.c associé pour vérifier que les fonctions correspondent à la nouvelle interface
- On veut recompiler les fichiers .c incluant le .h afin de vérifier qu'ils utilisent correctement la nouvelle interface
- Comme on recompile les fichiers .c on crée de nouveau .o donc recompilation du programme

## Observations

- On compile pour créer un exécutable
- On utilise des fichiers intermédiaires
- Chaque fichier intermédiaire est créé à partir d'un ou plusieurs fichiers sources

## Structure en graphe

- On peut créer un graphe orienté modélisant ce genre de compilation
- Une racine : l'exécutable
- Des feuilles : le code source
- Le reste : des fichiers intermédiaires

## Cas d'étude : code source

Nous allons prendre pour la suite un code assez simple :

```bash
main.c
math.c
math.h
```

## Cas d'étude : graphe

![make_tree1.dot.png](make_tree1.dot.png)

## Automatiser le build

Afin d'automatiser le build il faut :

- Une description de ce graphe
- Chaque transition représente une dépendance
- On doit indiquer une commande pour construire chaque fichier intermédiaire ou final

Plusieurs approches sont possibles, l'une d'elle est d'utiliser la commande make !

# Make

## Historique

- Ce besoin de build automatique existe depuis longtemps
- Au début d'Unix il existait des scripts dédiés pour chaque application
- Première version de l'outil make tel qu'on l'utilise : 1977

## Le Makefile

- la commande make repose sur un fichier Makefile décrivant le projet
- Ce Makefile décrit les dépendances et les commandes pour construire le système
- `make` recherche le Makefile dans le répertoire courant

## Syntaxe générale :

Une makefile contient un ensemble de règle de ce genre :

```make
cible : dependance1 dependance2
	commandes pour
	construire la cible
```

## Important : erreur classique !

- Pour des raisons historiques les commandes d'une Makefile doivent être indentées avec une tabulation.
- Une erreur classique est d'utiliser un espace, on obtient alors l'erreur suivante :

```
Makefile:8: *** missing separator (did you mean TAB instead of 8 spaces?). Arrêt.
```

**Pensez à bien configurer votre éditeur de texte pour indenter avec des tabulations !**

## Exemple de Makefile

```make
main : main.o math.o
	gcc main.o math.o -o main

main.o : main.c math.h
	gcc -c -Wall -Werror -o main.o main.c

math.o : math.c math.h
	gcc -c -Wall -Werror -o math.o math.c
```

## Utilisation

- Pour compiler le programme on peut taper : `make target`
- `target` peut-être n'importe quelle cible décrite dans le Makefile
- `make` va recompiler ce qui est nécessaire pour recompiler la cible
- Si rien n'est nécessaire, `make` n'exécute aucune commande
- `make` est pensé pour que les cibles soient des noms de fichiers

## Quand recompiler une cible ?

- Si le fichier de la cible n'existe pas
- Si une de ses dépendances doit être recompilée
- Si le fichier d'une de ses dépendances est plus récent que la cible

## La première règle

- Un appel à `make` sans argument construit la première cible du Makefile
- Un usage courant est de créer une première règle all qui indique ce qu'il faut construire :

```make
all : main
```

