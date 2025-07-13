#!/bin/bash
# $1 : folder name

if [ -z $1 ]; then
	echo "Usage: $0 <foldername>"
	exit 1
fi

if [ -d $1 ] || [ -d "solved/$1" ]; then
	echo "Folder $1 already exists"
	exit 2
fi

mkdir $1 && cd $1
mkdir build
cp ../a.nasm .
cp ../Makefile ../a.sh build
echo "1" > count
nvim a.nasm
