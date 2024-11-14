#!/bin/bash

$CXX -std=gnu++20 -DONLINE_JUDGE -O2 ../a.cpp -o a
if [ $? -ne 0 ]; then
	echo "Compilation failed"
	exit 1
fi

nfiles=$(echo "$(find -E ../tests -type f -regex ".*/i[0-9]+")" | wc -l)
for i in $(seq 0 $((nfiles-1))); do
	echo -n "$i    "
	out=$(./a < ../tests/i$i)
	if [ "$out" != "$(cat ../tests/o$i)" ]; then
		echo "$1 Fail"
		# echo "Expected: $(cat ../tests/o$i)"
		# echo "Got: $out"
	else
		:
		# echo "Pass"
	fi
done

echo ""
