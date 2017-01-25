% INF203 - Flux d'entrée / sortie standard
% Victor Lambret
% 2017

# les 3 flux

## Entrée / sortie

Sous Unix chaque processus qui s'exécute est créé avec 3 flux :

- l'entrée standard
- La sortie standard
- La sortie d'erreur

## Qu'est-ce qu'un flux ?

Un flux est un descripteur de fichier ouvert par défaut à la création du processus.

l'entrée standard est en lecture seule
La sortie standard et la sortie d'erreur sont en écriture seule

## Valeurs

```
| Nom             | I/O stream  | file descriptor |
| entrée standard | stdin       |               0 |
| sortie standard | stdout      |               1 |
| sortie d'erreur | stderr      |               2 |
```

## L'entrée standard

Dans Unix c'est le fichier depuis lequel le processus lit ses données d'entrée.

Exemple de fonction C utilisant l'entrée standard :

```c
int getchar(void);
```

Exemple d'instruction shell lisant l'entrée standard :

```bash
read variable
```

## La sortie standard

Dans Unix la sortie standard est le fichier dans lequel le processus écrit ses résultats.

Exemple de fonction C utilisant la sortie standard  :

```c
printf("hacker vaillant rien d'impossible !\n");
fprintf(stdin, "hacker vaillant rien d'impossible !\n");
```

Exemple d'instruction shell utilisant la sortie standard :

```bash
echo "no place like $HOME"
```

## La sortie d'erreur

A quoi sert cette seconde sortie ?

- Aux affichages d'erreurs pour l'utilisateur
- Aux affichage de debug
- Aux affichages de diagnostique

Cette seconde sortie laisse la possibilité de traiter autrement ces informations (c'est souvent utile)

## Exemples de sorties d'erreurs

En C on peut préciser un flux pour certaines fonctions :

```c
fprintf(stderr, "All your bases are belong to us");
```

En shell c'est le flux ou s'affichent les erreurs :

```bash
user@machine:~$ ./main
bash: ./main: Permission non accordée
```
## Comportement par défaut

Quand on lance une commande dans un interpréteur shell par défaut :

- L'entrée standard lit les données saisie du clavier
- La sortie standard et la sortie d'erreur s'affichent dans le shell

# Redirection de flux

## Rediriger l'entrée standard en shell

Voici le programme add.sh qui additionne 2 entiers

```bash
#! /bin/bash

read NUMBER1
read NUMBER2
echo $(( NUMBER1 + NUMBER2 ))
```

## Rediriger l'entrée standard

Par défaut avec ce programme l'utilisateur doit saisir les nombres à additionner au clavier

```bash
user@machine:~$ ./add.sh
3
4
7
```

## Rediriger l'entrée standard

On peut créer un fichier dataFile qui contient les deux nombres :

```bash
3
4
```

Et utiliser l'opérateur < pour indiquer au shell d'utiliser le fichier comme entrée standard de la commande

```bash
user@machine:~$ ./add.sh < dataFile
5
```

## Notes importantes

Bien que l'opérateur < soit spécifique au shell, la redirection est possible pour tout type d'exécutables : scripts shell, code compilé, etc.

On peut placer la redirection également en début de commande :

```bash
user@machine:~$ < dataFile ./add.sh
5
```
