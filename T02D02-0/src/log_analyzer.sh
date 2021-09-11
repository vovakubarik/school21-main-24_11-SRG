#!/bin/bash

echo "enter the path to the file"
read way
if [ ! -f "$way" ]; then
    kill "$$"
fi
entry=$(wc -l <"$way")
uniq=($(awk '{print -f $1}' $way | sort -u | wc -l))
change=($(awk '{print -f $8}' $way | sort -u | wc -l))
echo "$entry $uniq $change"
