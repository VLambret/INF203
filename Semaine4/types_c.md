% INF203 - Elements de programmation C
% Victor Lambret
% 2017 - https://github.com/VLambret/INF203

# Rappels sur les bases

## Les bases utiles

- La plupart des humains ont dix doigts et comptent donc en base dix
- Cette norme est tellement répandue que les humains n'ayant pas dix doigts comptent aussi en base 10
- Mais comme le disait une personne célèbre :

> Il y a 10 catégories de personnes, les informaticiens et les autres
>
> -- <cite>Benjamin Franklin</cite>

## Le binaire : la base 2

- Le matériel utilisé en informatique en général limité à stocker l'information sous deux états.
- On combine ces états pour représenter l'information.
- La première base utile est donc la base 2

chiffres utilisés :

```
0 1
```

## L'octal : la base 8

- Un chiffre octal correspond à 3 chiffres binaires, la conversion est donc facile
- Utilise les mêmes chiffres que la base 10 :
- On l'utilise pour les droits Unix (`chmod 764`)

chiffres utilisés :

```
0 1 2 3 4 5 6 7
```

## L'hexadécimal : la base 16

- Un chiffre hexadécimal correspond à 4 chiffres binaires, la conversion est donc facile
- Permet une représentation compacte de données binaires : `11011110101011011011111011101111` se stocke mieux en DEADBEEF

chiffres utilisés :

```
0 1 2 3 4 5 6 7 8 9 A B C D E F
```

## Exercice

Parmis les nombres suivants :

```C
10      14      ADA     70      0
```

- Combien sont valides en binaire ?
- Combien sont valides en octal ?
- Combien sont valides en décimal ?
- Combien sont valides en hexadecimal ?

## Notations en C

```C
int n1 = 0b10;      // binaire
int n2 = 010;       // octal
int n3 = 10;        // decimal
int n4 = 0x10;      // hexadecimal
```

- Attention ! La notation C pour l'octal est très dangereuse, il est facile de la confondre avec du décimal
- Ces notations se retrouvent dans de nombreux autres langages



