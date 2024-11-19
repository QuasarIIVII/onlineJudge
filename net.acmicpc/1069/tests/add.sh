#!/bin/bash

N=1

if [ $# -lt 1 ]; then
	nvim "i$N"
	nvim "o$N"

	if command -v gsed &> /dev/null; then
		GNU_SED="gsed"
	else
		GNU_SED="sed"
	fi

	$GNU_SED -i -E 's/(N=)([0-9]+)/echo "\1$((\2 + 1))"/e' "$0"
else
	nvim "i$1"
	nvim "o$1"
fi
