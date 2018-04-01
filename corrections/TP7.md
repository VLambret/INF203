# Correction TP7

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

```diff
#!/bin/bash

+if [ $# -ne 2 ]
+then
+	echo "Nombre d'arguments invalides" >&2
+	echo "usage : $0 nombre1 nombre2" >&2
+	exit 1
+fi
+
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

d) 

