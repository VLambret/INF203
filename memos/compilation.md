# Compilation

`clang` et `gcc` sont des compilateurs absolument équivalents et qui acceptent les mêmes options de compilation

## Compilation séparée

En temps normal la compilation prends un ou plusieurs fichiers C pour créer un exécutable.

```bash
gcc main.c lib.c add.c
```

Problème : si on modifie un seul fichier on doit tout recompiler.

On va donc procéder en deux étapes :

- La compilation en code objet qui crée des fichiers `.o` en compilant des `.o`
- L'édition de lien qui compile des `.o` pour créer l'exécutable final. On parle d'éditions de liens car on à cette étape on vérifie que les liens entre fichiers `.o`, c'est à dire les appels de fonctions sont tous bien remplis.

```bash
gcc -c main.c
gcc -c lib.c
gcc -c add.c
gcc main.o lib.o add.o
```

## Options de compilation à retenir

- `-c` : permet d'arrêter la compilation d'un fichier pour créer uniquement un fichier `.o`, pas l'exécutable final
- `-o nomfichier` : permet de donner le nom du fichier résultat attendu plutôt que d'utiliser celui par défaut

```diff
- ATTENTION ! l'option -o ne crée pas des fichier .o !
- L'option -c est orpheline, on peut la placer n'importe ou dans la commande
gcc -c main.c
gcc main.c -c
```

```bash
# Quand on ne précise rien l'exécutable produit est a.out
gcc main.c lib.c add.c

# Pour créer un exécutable précis on peut donc procéder ainsi :
gcc -o monexecutable main.c lib.c add.c
gcc main.c lib.c add.c -o monexecutable

# On peut aussi spécifier un nom de fichier .o précis :
gcc -c main.c -o programme.o
```

```diff
- ATTENTION ! l'option -o doit être immédiatement suivie du nom de fichier !
- gcc -o main.c lib.c add.c monexecutable
- Cette commande tente de compiler un exécutable nommé main.c à partir de lib.c, add.c et monexecutable. Comme ce dernier n'existe pas, la compilation échoue.
```
