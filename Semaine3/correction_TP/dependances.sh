#! /bin/bash

LIGNES=`grep '#include' $1`

echo "$LIGNES" | sed 's/#include "//' | sed 's/"//'
