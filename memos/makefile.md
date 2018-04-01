# Makefile

## Graphe de dépendance

Pour créer un Makefile on commence par écrire un graphe de dépendance. Pour cela on utilise trois règles :

1. L'exécutable final dépend des fichiers `.o`
2. Chaque fichier `.o` dépend du fichier `.c` correspondant
3. Si un fichier `.c` inclu un fichier `.h` alors son fichier `.o` dépend également du fichier `.h` inclu

Si une dépendance est modifiée, on recrée la cible. Comme les fichiers `.c` et `.h` sont le code source de l'application ils ne sont jamais recréés. Cela signifie qu'aucune flêche ne doit aller vers un `.c` ou un `.h`.

![](https://github.com/VLambret/INF203/blob/master/corrections/graph.png)

## Makefile

On traduit ensuite le graphe de dépendance en un fichier Makefile. Pour cela on écrit plusieurs règles de la forme suivante :

```Makefile
cible : dépendance1 dépendance2
	commande pour construire la cible
```

1. La première règle du Makefile est l'exécutable à produire, on la met tout en haut. Elle dépend de tous les `.o`
2. Ensuite on écrit les règles pour construire les `.o`. On utilise l'option `-c` pour le compilateur ici. Les dépendances sont des fichiers `.c` (obligatoire) et `.h` (optionnel). La commande de compilation ne compile que les `.c` pas les `.h` !

```Makefile
prog : main.o add.o lib.o
	clang main.o add.o lib.o -o prog

main.o : main.c lib.h
	gcc -c main.c

lib.o : lib.c lib.h
	gcc -c lib.c

add.o : add.c
	gcc -c add.c
```

## Utilisation

- Si le fichier Makefile est présent dans le répertoire courant il suffit de taper la commande `make`
- Si on a déjà tapé `make` alors retaper cette commande ne fait rien si aucun fichier source n'a été modifié (make regarde l'heure du fichier)
- Si on a modifié des fichiers sources alors seules les cibles dans le sous-graphe de dépendance des fichiers modifiés sont recrées, les autres cibles sont conservées
