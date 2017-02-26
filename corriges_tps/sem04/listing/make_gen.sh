#!/bin/bash

#####################################
# Bloc 1
extract_headers()
{
    for i in $(grep '#include "' $1 | sed 's/#include "//' | sed 's/"//')
    do
       echo -n $i" "
    done
    echo
}

#####################################
# Bloc 2
if [ $# -ne 1 ]
then
    echo Donnez le nom du programme principal en argument
    exit 1
fi

#####################################
# Bloc 3
PRGM=$1

#####################################
# Bloc 4

DEPPRGM="$PRGM: "
COMPRGM="\tgcc -o $PRGM "
for FILE in *.c
do
    FILEO=$(basename $FILE .c).o
    DEPPRGM=$DEPPRGM"$FILEO "
    COMPRGM=$COMPRGM"$FILEO "
done

echo -e $DEPPRGM > Makefile
echo -e $COMPRGM >> Makefile

#####################################
# Bloc 5
for source_file in *.c
do
    object="$(basename $source_file .c).o"
    headers=$(extract_headers $source_file)
    echo -e "$object: $source_file $headers" >> Makefile
    echo -e "\tgcc -c $source_file" >> Makefile
done
