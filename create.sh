#!/bin/bash

if [[ $# -eq 0 ]]
    then
        echo "Usage: ./create.sh <number>"
        exit 1
fi
touch "$1_incomplete.cpp"
# echo "#include <bits/stdc++.h>

# using namespace std;
# " > "$1_incomplete.cpp"