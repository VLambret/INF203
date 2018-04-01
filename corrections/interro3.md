# IMA-02 - Interro 3 INF203

> If debugging is the process of removing software bugs, then programming must be the process of putting them in.
> - Edsger Dijkstra

## Redirections

La commande `find  /INF203 -type f -empty` permet de trouver les fichiers vides. Donner la commande qui permet de rediriger la sortie de cette commande dans un fichier nommé `vide.txt`

```bash
find  /INF203 -type f -empty > vide.txt
```

Compter le nombre de fichiers vides en utilisant ce fichier

```bash
wc -l vide.txt
wc -l < vide.txt
cat vide.txt | wc -l
```

Compter le nombre de fichiers vides en utilisant directement la sortie de la commande

```bash
find  /INF203 -type f -empty | wc -l
```

Rediriger la sortie d’erreur de la commande `gcc vide.txt` vers `/dev/null`

```bash
gcc vide.txt 2> /dev/null
```

## Compilation

Soit un programme composé des fichiers `main.c, pied.c, lib.c, lib.h`.  Les fichiers `main.c` et `lib.c` incluent `lib.h`. Dessiner les
dépendances entre tous les fichiers : le code source, les fichiers .o et l’exécutable produit.

![](https://github.com/VLambret/INF203/blob/master/corrections/graph.png)

Donner la commande pour compiler `pied.c` en `pied.o`.

```bash
gcc -c pied.c
```

Donner la commande pour compiler `main.o, pied.o, lib.o` en un exécutable nommé `despiedsetdesmains`

```bash
gcc -o despiedsetdesmains main.o pied.o lib.o
gcc main.o pied.o lib.o -o despiedsetdesmains
```

Donner la règle de Makefile concernant la cible lib.o (cible, dépendance et commande).

```Makefile
lib.o : lib.c lib.h
	gcc -c lib.c
```

Quel type d’indentation utiliser dans un Makefile ?

```
On indente les commandes avec des tabulations, jamais des espaces.
```

## GDB

Le programme `correction_interro.c` fait une segfault. Comment s’y prendre pour débugger ce programme avec gdb ?

```
gcc -g correction_interro.c
gdb ./a.out
> run
> info stack
> list
> break
> print
> up
  etc.
```
