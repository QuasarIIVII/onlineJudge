	.section .data
	.p2align 4
s0:
	.ascii "Hello World!"
	.byte 10, 0
s1:
	.ascii "%llx"
	.byte 10, 0
s2:
	.rept 35
		.byte 0x41, 0x42, 0x43
	.endr

	.ascii "q"
	.byte 0

s3:
	.byte 10, 0

ql.io.s:
	.rept 2048
		.byte 0
	.endr

ql.io.data:
	.quad 0

	.equ ql.io.is.offset, 0x18
	.equ ql.io.os.offsetStr, 0x08
	.equ ql.io.is.offsetStr, 0x10

	;	           			     $       7       6       5       4       3       2       1       0
	.equ ql.io.is$,				0b0000000000000000000000000000000000000000000000000000000000000000
	.equ ql.io.isNum,			0b0000001111111111000000000000000000000000000000000000000000000000
	.equ ql.io.isWhiteSpace,	0b0000000000000000000000000000000100000000000000000011111000000000

	;	           			     $       F       E       D       C       B       A       9       8
	.equ ql.io.isLetter,		0b0000011111111111111111111111111000000111111111111111111111111110
	.equ ql.io.isLetterS,		0b0000011111111111111111111111111000000000000000000000000000000000
	.equ ql.io.isLetterB,		0b0000000000000000000000000000000000000111111111111111111111111110

	.section .bss
	.p2align 4

.section .text

