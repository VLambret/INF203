% INF203 - Compilation
% Victor Lambret
% 2017

# Introduction

## Le Processeur

- Dans un ordinateur les programmes s'exécutent sur un ou plusieurs processeurs.

- Un processeur est un composant matériel permettant d'effectuer des opérations simples.

1. Lire ou écrire de la mémoire
2. Effectuer des opérations arithmétiques ou logiques
3. Sauter à une instruction précise (pour faire des if, boucles, appels de fonction, etc.)

## Une instruction

- Les instructions des processeurs prennent quelques octets. Chaque bit y a une signification particulière.

- Ces instructions sont conçues pour être rapides à décoder et exécuter par le processeur. Elles ne sont pas faites pour être lisibles par un humain !

Exemple d'instruction en binaire :

```
10110000 01100001
```

## L'assembleur

Le binaire n'étant pas facile à manipuler, on lui associe une représentation textuelle compréhensible par un humain lorsque c'est nécessaire.

```asm
movb $0x61,%al
```

## Programmer en assembleur

Programmer en assembleur est possible, mais ce n'est pas pratique.

- Les instructions étant simples, il en faut beaucoup pour faire des choses compliquées
- Un jeu d'instruction étant spécifique à une famille de processeurs on ne peut pas écrire des programmes portables avec.
- Au delà de programmes triviaux un développeur ne produit pas du code efficace et fonctionnel en assembleur

# Le compilateur

## Role

- Les développeurs souhaitent programmer dans des langages de haut niveau (C, C++, Java, Ocaml, etc. )
- Les développeurs souhaitent écrire un programme une fois et pouvoir l'exécuter sur des machines différentes
- Un composant doit donc s'occuper de traduire le langage de haut niveau vers les instructions bas niveau d'un processeur : c'est le compilateur !

## Le code source

- Le code source est fait pour être compris par un humain.
- Sa syntaxe reste lourde car elle doit être compréhensible aussi par le compilateur

## Analyse lexicale et syntaxique

Afin de transformer un code source en binaire exécutable le compilateur va effectuer différente étapes :

1. Il analyse le code source pour identifier des éléments de bases (mots clefs du langages, noms, etc...)
2. Il vérifie que ces éléments de base respectent la syntaxe du langage

Pour faire la parallèle avec le français :

1. Vérifier que les mots appartiennent bien au dictionnaire
2. Vérifier que la grammaire des phrases est correcte

## Représentation interne

- Une fois le code source analysé le compilateur transforme le programme dans son format interne
- Ce format interne est une représentation pratique pour que le compilateur effectue des optimisations du programme
- La représentation interne est encore indépendante du processeur

## Création de l'exécutable

- Une fois le programme optimisé, le compilateur va traduire sa représentation interne en un programme exécutable
- Pour cela il fait appel à un traducteur capable de transformer la représentation interne du programme vers le processeur ciblé

# Compilation ou interprétation ?

## Différence

- Dans la compilation, on crée un binaire à partir du code source. Le programme exécuté sera ensuite le binaire seul.

- Dans les langages interprétés le code source est fait pour être exécuté par l'interpréteur. Cela signifie
