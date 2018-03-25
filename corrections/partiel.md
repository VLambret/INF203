# Partiel INF203

## Beaucoup de programmes

1.  Créer un répertoire `Programmes` dans votre répertoire de login et y copier tous vos programmes en C.

```bash
mkdir ~/Programmes
cp ~/INF203/TP*/*.c  ~/Programmes
```

2.  Modifier les droits de vos fichiers et répertoires afin que votre binôme, qui ne fait pas partie du même groupe Unix que vous, puisse copier tous vos programmes C sur son compte.

```bash
chmod o+x ~/Programmes ~
```

3.  Déplacer votre répertoire `Programmes` vers le répertoire `Archives` de votre répertoire de login et le renommer en `Programmes_2017-2018`.

```bash
mv ~/Programmes/ ~/Archives/Programmes_2017-2018/
```

4.  Supprimer tous les fichiers et répertoires contenus dans le répertoire `Archives` et ayant `2016-2017` dans leur nom.

```bash
rm -r ~/Archives/*2016-2017*
```

5.  Compter le nombre de fichiers ayant `203` et `42` dans leur nom (dans n’importe quel ordre), parmis tous les fichiers contenant vos programmes en C.

```bash
# Plusieurs possibilités :
ls ~/Archives/Programmes_2017-2018/*203*.c | grep 42 | wc -w
ls ~/Archives/Programmes_2017-2018/*203*.c | grep -c 42
ls ~/INF203/TP*/*203*42*.c ~/INF203/TP*/*42*203*.c | wc -w
```

## Nom de base

1.  Écrivez une fonction permettant de copier la chaine de caractères `nom` dans `resultat`.

```C
void copie_chaine(char *resultat, char *nom) {
	int i = 0;

	while(nom[i] != '\0') {
		resultat[i] = nom[i];
		i++;
	}

	resultat[i] = '\0';
}
```

2.  Écrivez une fonction qui renvoie l’indice du dernier caractère `'/'` présent dans la chaîne `nom`, ou `-1` si celle-ci ne contient pas de caractère `'/'`

```C
int dernier_slash(char *nom) {
	int d = -1;
	int i = 0;

	while(nom[i] != '\0') {
		if(nom[i] == '/')
			d = i;
		i++;
	}
	return d;
}
```

3.  Écrivez une fonction permettant de supprimer tous les caractères `'/'` présents à la fin de `nom`. Si `nom` n’est pas terminée par un ou plusieurs caractères `'/'`, `supprime_slash` ne fait rien.

```C
void supprime_slash(char *nom) {
	int d = -1;
	int i = 0;

	while(nom[i] != '\0') {
		if(nom[i] != '/')
			d = i;
		i++;
	}
	nom[d + 1] = '\0';
}
```

4.  Écrivez une fonction permettant de copier le nom de base de la chaîne de caractères `nom` dans `resultat` (sans modifier `nom`).

```C
void nom_de_base(char *resultat, char *nom) {
	int d;
	copie_chaine(resultat, nom);

	if(resultat[0] == '\0') {
		resultat[0] = '.';
		resultat[1] = '\0';
		return;
	}

	supprime_slash(resultat);
	d = dernier_slash(resultat);
	copie_chaine(resultat, &resultat[d+1]);

	// si la chaine est vide maintenant, c'est parce qu'il n'y avait que
	// des slashs

	if(resultat[0] == '\0') {
		resultat[0] = '/';
		resultat[1] = '\0';
	}
}
```

## Tête à queue

1.  Écrivez une fonction permettant de copier dans `destination` les `n` premières lignes de `source`.

```C
void tete(int n, FILE *source, FILE *destination) {
	int i=1;
	char c;

	fscanf(source, "%c", &c);
	while(i<=n && !feof(source)) {
		fprintf(destination, "%c", c);
		if(c == '\n')
			i++;
		fscanf(source, "%c", &c);
	}
}
```

2.  Écrivez une fonction permettant de copier dans `destination` toutes les lignes de `source` sauf les `n` premières.

```C
void queue(int n, FILE *source, FILE *destination) {
	int i = 1;
	char c;

	fscanf(source, "%c", &c);
	while(!feof(source)) {
		if(i>n)
			fprintf(destination, "%c", c);
		if(c == '\n')
			i++;
		fscanf(source, "%c", &c);
	}
}
```

3.  En utilisant les fonctions `tete` et `queue`, écrivez une fonction permettant de copier dans `destination` :
    -   les `n` premières lignes de `source` si `bout` est égal à `tete`
    -   toutes sauf les `n` premières si `bout` est égal à `queue`

Cette fonction ne devra rien faire et renvoyer un entier strictement positif en cas de problème, et renvoyer 0 si tout va bien.

```C
int tete_ou_queue(char *nombre, char *bout, FILE *source, FILE *destination) {
	int n;

	if(sscanf(nombre, "%d", &n) == 0)
		return 1;

	if(strcmp(bout, "tete") == 0)
		tete(n, source, destination);
	else if (strcmp(bout, "queue") == 0)
		queue(n, source, destination);
	else
		return 2;
	return 0;
}
```

4.  Écrivez un programme prenant 3 arguments sur la ligne de commande qui appelle la fonction `tete_ou_queue` en lui passant en paramètres :

    -   les deux premiers arguments (pour `nombre` et `bout`)
    -   un descripteur de fichier ouvert sur un fichier ayant pour nom le troisième argument
    -   le descripteur `stdout`

    Ce programme devra afficher un message d’erreur et se terminer immédiatement dans les cas problématiques.

```C
int main(int argc, char *argv[]) {
	FILE *s;
	int r;

	if(argc != 4) {
		fprintf(stderr, "Usage : %s entier bout fichier\n", argv[0]);
		return 3;
	}

	s = fopen(argv[3], "r");
	if(s == NULL) {
		fprintf(stderr, "Impossible d'ouvrir le fichier %s en lecture\n", argv[3]);
		return 4;
	}

	r = tete_ou_queue(argv[1], argv[2], s, stdout) ;
	if(r != 0) {
		fprintf(stderr,"Usage : %s entier bout fichier\n",argv[0]);
	}

	return r;
}
```

5.  Modifier le programme de la question précédente pour que :
    -   avec deux arguments, il lise les lignes depuis l’entrée standard
    -   avec quatre arguments, il écrive les lignes dans le fichier dont le nom est donné en quatrième argument

```C
int main(int argc, char *argv[]) {
	FILE *s = stdin;
	FILE *d = stdout;
	int r;

	if(argc < 3 || argc > 5) {
		fprintf(stderr,"Usage : %s entier bout [fichier entree] [fichier sortie]\n", argv[0]);
		return 3;
	}

	if(argc > 3) {
		s = fopen(argv[3], "r");
		if(s == NULL) {
			fprintf(stderr, "Impossible d'ouvrir le fichier %s en lecture\n", argv[3]);
			return 4;
		}
	}

	if(argc == 5) {
		d = fopen(argv[4], "w");
		if(d==NULL) {
			fprintf(stderr, "Impossible d'ouvrir le fichier %s en ecriture\n", argv[4]);
			return 4;
		}
	}

	r = tete_ou_queue(argv[1], argv[2], s, d) ;
	if(r != 0) {
		fprintf(stderr, "Usage : %s entier bout fichier\n", argv[0]);
	}

	return r;
}
```
