% INF203 - Compléments de la correction d'interrogation
% Victor Lambret
% 2017 - https://github.com/VLambret/INF203

# Différence entre \[ \] et \{ \}

## \[ \]

- L'opérateur `[]` s'utilise comme l'opérateur `?` car il correspond à un seul caractère
- Au lieu de correspondre à n'importe quel caractère on spécifie la liste des caractères entre \[ et \]

```bash
ls fichier[123]
```

On peut définir des intervalles

```bash
ls fichier[1-3]
```

## \{ \}

- L'opérateur `{}` ne permet pas de définir des intervalles
- On donne un ensemble de caractères séparés par des virgules :

```bash
ls fichier{1,2,3}
```

## Différence

- On pourrait croire que `[]` et `{}` malgré une notation légèrement différentes sont équivalents
- En réalité ces deux opérateurs ont des usages radicalement différents
- Nous allons l'illustrer sur un répertoire qui contient trois fichiers :

```bash
user@machine$ ls
fichier1 fichier2 fichier3
```

On va chercher à lister tous les fichiers de ce répertoire finissant par un numéro impair

## Lister avec \[ \]

```bash
user@machine$ ls fichier[13579]
fichier1 fichier3
```

ça marche, ls ne liste que fichier1 et fichier3 présents sur le disque

## Lister avec \{ \}

```bash
user@machine$ ls fichier{1,3,5,7,9}
ls: impossible d'accéder à fichier5: Aucun fichier ou dossier de ce type
ls: impossible d'accéder à fichier7: Aucun fichier ou dossier de ce type
ls: impossible d'accéder à fichier9: Aucun fichier ou dossier de ce type
fichier1  fichier3
```

- On voit ici que `ls` a été appelé sur fichier1, fichier3, fichier5, fichier7 et fichier9
- Les trois derniers ne sont pas présents sur le disque donc erreur !

## Mais alors, c'est quoi \[ \] ?

- L'opérateur `[]` fonctionne pour être utilisé dans le mécanisme de substitution avec le système de fichier
- C'est un opérateur plus précis que `*` et `?` mais il repose sur les mêmes principes
- C'est un standard du shell

## Mais alors, c'est quoi \{ \} ?

- C'est le produit cartésien !
- C'est spécifique bash

```bash
echo {Roi,Dame}-{Pique,Trefle,Coeur,Carreau}
Roi-Pique Roi-Trefle Roi-Coeur Roi-Carreau Dame-Pique Dame-Trefle Dame-Coeur Dame-Carreau
```

## Conclusion

- Oubliez `{}` pour le moment, c'est un opérateur très spécialisé qui n'est pas utile tous les jours
- Retenez `[]`, c'est un opérateur utile et mignon
