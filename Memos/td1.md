% INF203 - TD1
% Victor Lambret
% 12 Janvier 2017

# Memo Semaine 1

## Meta-caractères

- Les opérateurs `*`, `?` et `[ ]` permettent de décrire un motif.
- Avant d'exécuter la commande le shell lit le système de fichier pour remplacer le motif par les noms de fichiers ou répertoires correspondants.

`*` permet de représenter n'importe quelle suite de caractères. Cette suite peut potentiellement ne contenir aucun caractère

```bash
# Lister tous les fichiers du répertoire
ls *

# Lister les fichiers source C :
ls *.c

# Lister les TP :
ls TP*

# Lister les fichiers contenant le chiffre 4 :
ls *4*
```

- L'opérateur `?` correspond à exactement 1 caractère

```bash
# Lister les fichier main avec une extension à une seule lettre
ls main.?

# Lister les fichier main avec une extension à trois lettres
ls main.???

# Lister les fichiers dont la taille du nom est 5 caractères :
ls ?????
```

- l'opérateur `[ ]` fonctionne comme un opérateur `?` mais on peut préciser la liste des caractères correspondants :
- On peut définir des intervalles de valeurs avec un -
	- `0-9` correspond à 0123456789
	- `a-z` aux lettres minuscules
	- `A-Z` aux lettres majuscules
- Les bornes de l'intervalle correspondent aux codes ASCII des caractères

```bash
# Lister les fichiers main.c et main.h
ls main.[ch]

# Lister les fichiers toto dont l'extension est une lettre majuscule ou minuscule :
ls toto.[a-zA-Z]
```

On peut combiner ces opérateurs entre eux pour créer des motifs plus complexes :

```bash
# Lister tous les fichiers sources c
ls *.[ch]

# Lister les fichiers dont le nom commence par un chiffre :
ls [0-9]*
```

# Contrôle de l'exécution

## CTRL

`Ctrl + C` arrête un processus
`Ctrl + Z` suspend un processus
`Ctrl + L` nettoie le contenu de l'écran

`bg` passe un processus suspendu en arrière plan (son exécution reprends comme si il avait été lancé avec `&`)
`fg` repasse un processus suspendu au premier plan
	
# Droits & permissions

## Catégories

Dans Unix il y a 3 catégories d'utilisateurs :

- L'Utiliateurs (u)
- Le groupe (g)
- Les autres (o)

## Permissions

Il y a 3 types de permissions pour chaque catégorie d'utilisateurs :

- Read
- Write
- Execute

## Fichiers

Pour les fichiers

- R : Autorise l'accès au contenu du fichier (copie, afichage, etc.)
- W : Autorise la modificatio du contenu du fichier (suppression du fichier, modification du contenu)
- X : Autorise l'exécution du fichier (qui doit alors être un programme)

## Répertoires

- R : Autorise la consultation du contenu du répertoire (ls)
- W : Autorise la modification du contenu du répertoire :
	- Supprimer un fichier
	- Créer un nouveau fichier
	- Renommer un fichier
- X : Autorise la traversée du dossier
	- autorise à faire un cd dedans
	- autorise à utiliser le nom du dossier dans un chemin

## Modifier les droits

Pour modifier les droits on utiliser chmod

```
chmod [Utilisateurs Concernés][Type d'opération][Valeurs des permissions]
```

- Utilisateurs concernés (1 ou plus)
	- `u` l'utilisateur
	- `g` le groupe
	- `o` les ôtres
- Type d'opération (1 exactement)
	- `+` ajouter des droits
	- `-` enlever des droits
	- `=` mettre exactement ces droits
- Permissions (1 ou plus)
	- `r` lecture (read)
	- `w` écriture (write)
	- `x` exécution (execute)
