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
