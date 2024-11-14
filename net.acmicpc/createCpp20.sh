#!/bin/bash
# $1 : folder name

if [ -z $1 ]; then
	echo "Usage: $0 <foldername>"
	exit 1
fi

if [ -d $1 ]; then
	echo "Folder $1 already exists"
	exit 2
fi

mkdir $1 && cd $1
cp "../a.cpp" "../CMakeLists.txt" .

mkdir tests && cd tests
cp "../../add.sh" .
cd ..

mkdir build && cd build
cp "../../test.sh" .
cmake ..
cd ..
nvim a.cpp
