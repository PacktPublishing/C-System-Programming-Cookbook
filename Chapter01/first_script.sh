#!/bin/bash
cat does_not_exists.txt
if [ $? -eq 0 ]
then
    echo "All good, does_not_exists.txt exists!"
    exit 0
else
    echo "does_not_exists.txt really DOES NOT exists!!" >&2
    exit 11
fi

