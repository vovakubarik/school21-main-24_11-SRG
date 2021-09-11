#!/bin/bash

echo "enter the path to the file"
read way
if [ ! -f "$way" ]
then
	kill "$$"
fi
echo "enter the a mutable string"
read s1
echo "enter the replacement string"
read s2
sed -i '' "s/$s1/$s2/" "$way"
ssh=$(shasum --a 256 $way)
size=$(stat -f%z $way)
date=$(date +'%Y-%m-%d %k:%M')
echo "$way - $size - $date - $ssh - sha256" >> $PWD/files.log
