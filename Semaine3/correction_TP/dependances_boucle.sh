#! /bin/bash

# Dans la boucle for comme l'espace est un séparateur d'éléments il serait
# compliqué de supprimer le #include dans le for. La solution consiste à le
# supprimer juste après le grep en utilisant un pipe.

LIGNES=`grep '#include' $1 | sed 's/#include "//' | sed 's/"//'`

for L in $LIGNES
do
	echo -n $L
done

# On saute une ligne a la fin
echo
