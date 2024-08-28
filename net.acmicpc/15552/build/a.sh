#!/bin/bash
I=$(cat count)
cat <(echo -ne 'section .data\n\tdq ') <(echo -n $I) <(echo -ne '\n') $(echo '../a.asm') > a.asm
echo $(( $I + 1 )) > count
make
time ./a < $(echo -ne 'in.txt') > out.txt
