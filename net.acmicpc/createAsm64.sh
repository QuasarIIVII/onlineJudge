# $1 : folder name
#!/bin/bash

if [ -z $1 ]; then
	echo "Usage: $0 <foldername>"
	exit 1
fi

if [ -d $1 ]; then
	echo "Folder $1 already exists"
	exit 2
fi

mkdir $1 && cd $1
mkdir build
cp ../a.asm .
cp ../Makefile ../a.sh build
echo "1" > count
nvim a.asm
