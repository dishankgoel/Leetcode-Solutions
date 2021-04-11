#!/bin/bash

if [[ $# -eq 0 ]]
    then
        echo "Usage: ./complete.sh <file>"
        exit 1
fi
extension=${1#*.}
mv "$1" "${1%_*}.$extension"  