# Memo de révision

Pendant cette matière on a vu pas mal de concepts. Afin de réviser efficacement et de s'y retrouver dans l'ensemble des ressources disponibles ce mémo classe les sujets par thématique avec des liens vers les ressources.

Courage à tous ! :-)

## Makefile

- l'option `-c` permet de compiler un fichier c en fichier objet
- Attention ! L'option `-o` sert à préciser le nom du fichier produit, pas à compiler un fichier objet. Cette option ne s'utilise pas toute seule car elle est suivie par le nom du fichier (il ne sort pas du chapeau !)
- On met dans le `.h` associé à un fichier `.c` les signatures des fonctions qui sont appelées de l'extérieur (par d'autres fichiers `.c` par exemple)
- Les dépendances :
	- l'exécutable final dépend des fichiers objets .o
	- Les fichiers objets dépendent de leur fichier c et des fichiers.h inclus
	- On ne compile **JAMAIS** un fichier `.h` !

[Un Makefile illustrant ces concepts](https://github.com/VLambret/INF203/blob/master/Semaine6/exercice/ensemble_chaine/Makefile)

## Main et test des arguments

- Retenir la signature étendue du main : `int main(int argc, char *argv[])`
- `argc` vaut 1 de plus que le `$#` du bash car `argc` compte le nom du programme.
- Savoir tester les arguments d'un programme comme [ici](https://github.com/VLambret/INF203/blob/master/Semaine6/exercice/commande_cp/cp.c#L28)

## Manipulation de fichier

- fopen (retenir les modes d'ouverture "r" et "w")
- fclose (reflexe : penser à fclose après chaque fopen)
- feof pour tester la fin de fichier
- fread (rappel : on peut lire moins que demandé, utiliser la valeur de retour)
- fwrite

exemple canonique : [la fonction cp](https://github.com/VLambret/INF203/blob/master/Semaine6/exercice/commande_cp/cp.c) donc à connaître par coeur. !

## Manipulation d'ensembles

- [Slides semaine 7 et 8 sur le site de l'UE](http://inf123.forge.imag.fr/)

## Interpreteur 

- strlen
- strcpy (dest en premier, puis source)
- strcmp (renvoie 0 si les chaines sont égales)
- Pour les variables : Bien comprendre comment sont utilisées les variables :
[nombre_variables ](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L15)
[noms_variables](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L16)
[valeurs_variables](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L17)

**Fonctions de gestion des variables**

- [trouver_variable](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L20)
- [initialiser_variables](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L35)
- [affecter_variable](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L39)
- [valeur_variable](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L53)
- [trouver_affectation_variable](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L63)
- [appliquer_expansion_variables](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/variables.c#L92)

**Fonctions de l'interpreteur**

[decouper_ligne](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/interpreteur.c#L18)
[lire_ligne_fichier](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/interpreteur.c#L57)
[executer_ligne_commande](https://github.com/VLambret/INF203/blob/master/revisions/TP11-12/interpreteur.c#L83)
