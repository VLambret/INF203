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
