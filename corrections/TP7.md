# Correction TP7

Tout le code source modifié du TP est disponible dans le répertoire TP7

## Instructions conditionnelles

a) Exemples de cas à tester :

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh 2 3
3 est plus grand que 2
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh 5 4
5 est plus grand que 4
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh 6 6
les deux entiers 6 et 6 sont egaux
```

On peut aussi s'amuser à tester des cas d'utilisation invalides pour vérifier que ce programme n'est pas résistant aux erreurs :

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh 6 abc
./max2.sh: ligne 3 : [: abc : nombre entier attendu comme expression
./max2.sh: ligne 6 : [: abc : nombre entier attendu comme expression
les deux entiers 6 et abc sont egaux
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh 6
./max2.sh: ligne 3 : [: 6 : opérateur unaire attendu
./max2.sh: ligne 6 : [: 6 : opérateur unaire attendu
les deux entiers 6 et sont egaux
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2.sh
est plus grand que
```

b) On s'aperçoit rapidement (ou pas) que -plouploum n'est pas un opérateur valide dans un test. Toutefois ça n'empêche pas le programme de donner un résultat. Dans un programme C une erreur de synthaxe n'aurait pas permis de compiler le programme.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2err.sh 2 3
./max2err.sh: ligne 6 : [: -ploumploum : opérateur binaire attendu
les deux entiers 2 et 3 sont egaux
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2err.sh 4 5
./max2err.sh: ligne 6 : [: -ploumploum : opérateur binaire attendu
les deux entiers 4 et 5 sont egaux
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./max2err.sh 6 6
./max2err.sh: ligne 6 : [: -ploumploum : opérateur binaire attendu
les deux entiers 6 et 6 sont egaux
```

c) Note : Afin d'afficher les messages d'erreur sur stderr j'ai redirigé la sortie standard de ces affichages vers la sortie de stderr avec `>&2`. C'est équivalent à utiliser `fprintf(stderr, ...)` en C au lieu de `printf`.

```bash
#!/bin/bash

if [ $# -ne 2 ]
then
	echo "Nombre d'arguments invalides" >&2
	echo "usage : $0 nombre1 nombre2" >&2
	exit 1
fi

if [ $1 -gt $2 ]
then
	echo $1 est plus grand que $2
elif [ $1 -lt $2 ]
then
	echo $2 est plus grand que $1
else
	echo les deux entiers $1 et $2 sont egaux
fi
```

## Instructions d'itération : boucle for

d) `mkdir -p` crée le fichier sans faire d'erreur si il existe
Pour éviter de déplacer le script on compare le nom de script actuel avec le fichier. On a besoin d'utiliser `basename` pour transformer `./description.sh` en `description.sh`

```bash
#!/bin/bash

for FILE in *
do
	if  [ -f $FILE ]
	then
		if [ -x $FILE ]
		then
			echo "$FILE est un fichier executable"
			if [ $FILE != $(basename $0) ]
			then
				mkdir -p Exec
				mv $FILE Exec
			fi
		else
			echo "$FILE est un fichier non executable"
		fi
	fi
	if [ -d $FILE ]
	then
		echo $FILE est un repertoire
	fi
done
```

## Enchaînement de l'exécution de deux programmes : le retour

e)

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./des_heures.sh | ./instant_suivant10
nouvelle heure : 13:52:10
nouvelle heure : 13:52:12
nouvelle heure : 13:52:14
nouvelle heure : 13:52:16
nouvelle heure : 13:52:18
nouvelle heure : 13:52:20
nouvelle heure : 13:52:22
nouvelle heure : 13:52:24
nouvelle heure : 13:52:26
nouvelle heure : 13:52:28
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$
```

f)

```bash
#! /bin/bash

if [ $# -ne 2 ]
then
	echo "Nombre d'arguments invalides" >&2
	echo "usage : $0 nombre_iterations delai_en_secondes" >&2
	exit 1
fi

NOMBRE_ITERATION=$1
DELAI_EN_SECONDE=$2

for i in $(seq 1 $NOMBRE_ITERATION)
do
	date +%T
	sleep $DELAI_EN_SECONDE
done
```

g) Avec `./des_heures_bonus.sh 10 2 | ./instant_suivant10` le comportement est similaire à ce que l'on a obtenu dans les questions précédentes.

Si le script affiche moins d'instants que ce qui est attendu alors le dernier instant est répliqué jusqu'à atteindre 10 affichages.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./des_heures_bonus.sh 5 2 | ./instant_suivant10
nouvelle heure : 13:58:17
nouvelle heure : 13:58:19
nouvelle heure : 13:58:21
nouvelle heure : 13:58:23
nouvelle heure : 13:58:25
nouvelle heure : 13:58:25
nouvelle heure : 13:58:25
nouvelle heure : 13:58:25
nouvelle heure : 13:58:25
nouvelle heure : 13:58:25
```

Si le nombre d'instants est suppérieur à 10, alors on a tous les affichages. Par contre une fois le dernier terminé le script ne rend pas la main tout de suite. On devine que le script bash continue de créer des instants même si le programme `instant_suivant10` ne les lit plus.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$ ./des_heures_bonus.sh 15 2 | ./instant_suivant10
nouvelle heure : 14:01:08
nouvelle heure : 14:01:10
nouvelle heure : 14:01:12
nouvelle heure : 14:01:14
nouvelle heure : 14:01:16
nouvelle heure : 14:01:18
nouvelle heure : 14:01:20
nouvelle heure : 14:01:22
nouvelle heure : 14:01:24
nouvelle heure : 14:01:26
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7$
```

## Exercice de synthèse

1) Le code de retour de la commande diff est 0 ce qui signifie que les deux fichiers sont identiques. Comme ces deux fichiers contiennent ce qu'on attendait du programme et ce que l'on a obtenu cela signifie que le test est OK.

```bash
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7/TEST_INSTANT_SUIVANT$ ./instant_suivant < 123030.entree > 123030.ma_sortie
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7/TEST_INSTANT_SUIVANT$ diff 123030.sortie  123030.ma_sortie
lambret@debian-sogilis:~/INF203/INF203/corrections/TP7/TEST_INSTANT_SUIVANT$ echo $?0
0
```

```bash
#!/bin/bash

for MOTIF_ENTREE in *.entree
do
	NOM_MOTIF=$(basename $MOTIF_ENTREE .entree)

	./instant_suivant < $NOM_MOTIF.entree > $NOM_MOTIF.ma_sortie
	diff $NOM_MOTIF.sortie $NOM_MOTIF.ma_sortie

	if [ $? -eq 0 ]
	then
		echo tout va bien pour le test $NOM_MOTIF
	else
		echo tout va mal pour le test $NOM_MOTIF
	fi
done
```
