#!/bin/bash

export LANG=en

data=`date | cut -d " " -f 1`

echo "Today is $data."

if [ $data == 'Sat' ] || [ $data == 'Sun' ]
then
    echo "It is your lucky day. Enjoy your free time! :]"
else
    echo "You have to go to the work. :("
fi
