#!/bin/bash
# $1 : folder name

if [ $# -lt 1 ]; then
	echo "Usage: $0 [source file] <foldername>"
	exit 1
fi

src='a.cpp'

if [ $# -gt 1 ]; then
	if [ -f $1 ]; then
		src=$1
		shift
	else
		echo "File $1 does not exist"
		exit 1
	fi
fi

if [ ! -d solved ]; then
	mkdir solved
fi

if [ -z $1 ]; then
	echo "Usage: $0 <foldername>"
	exit 1
fi

if [ -d $1 ] || [ -d "solved/$1" ]; then
	echo "Folder $1 already exists"
	exit 2
fi

mkdir $1 && cd $1
cp "../$src" a.cpp
cp "../CMakeLists.txt" .

mkdir tests && cd tests
cp "../../add.sh" .
cd ..

mkdir build && cd build
cp "../../test.sh" .
cmake ..
cd ..
nvim a.cpp
