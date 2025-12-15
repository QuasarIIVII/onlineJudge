;indent setting : \t (0x09) which has width of 4 spaces (0x20)

section .data align=16
	s0 db "A",10,0
	s1 db "B",10,0
	s2 db 32,10,0
	s3 db 10,0
	_s2 times 35 db 0x41, 0x42, 0x43

;	ql.io.s times 40000000 db 0

	ql.io.data dq 0
	ql.io.is.offset equ 0x18
	ql.io.os.offsetStr equ 0x08
	ql.io.is.offsetStr equ 0x10

;	           			     $       7       6       5       4       3       2       1       0
	ql.io.is$			equ 0b0000000000000000000000000000000000000000000000000000000000000000
;	           			     $       F       E       D       C       B       A       9       8
	ql.io.isLetter		equ 0b0000011111111111111111111111111000000111111111111111111111111110
	ql.io.isLetterS		equ 0b0000011111111111111111111111111000000000000000000000000000000000
	ql.io.isLetterB		equ 0b0000000000000000000000000000000000000111111111111111111111111110

section .data align=64
	ql.io.isNum:
;			$       7       6       5       4       3       2       1       0
		dq 0b0000001111111111000000000000000000000000000000000000000000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000

	ql.io.isWhiteSpace:
;			$       7       6       5       4       3       2       1       0
		dq 0b0000000000000000000000000000000100000000000000000011111000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000
		dq 0b0000000000000000000000000000000000000000000000000000000000000000

section .bss align=16

section .text
	global main
	extern scanf, printf, fgets, fputs, stdin, stdout
	extern sscanf, sprintf

ql.proc.begin:
	; usuage
	; push <nOWords> ; nOWords : number of owords (128 bits / 16 bytes) to reserve
	; call ql.proc.begin

	push r12
	mov r12, [rsp+0x10]
	push r13
	push r14
	push r15
	pushfq

	shl r12, 1
	neg r12

	lea rsp, [rsp+8*r12-0x08]

	neg r12

;	push qword [rsp+8*r12+0x38]
	push r12
	push qword [rsp+8*r12+0x38]

	mov [rsp+8*r12+0x40], rbp
	mov [rsp+8*r12+0x48], rbx
	lea rbp, [rsp+8*r12+0x18]

	mov r12, [rsp+8*r12+0x38]

	ret

ql.proc.end:
	mov rdi, [rsp+8]
	mov rbx, [rsp+8*rdi+72]
	pop qword [rsp+8*rdi+64]

	lea rsp, [rsp+8*rdi+16]
	popfq
	pop r15
	pop r14
	pop r13
	pop r12
	pop rbp

	ret

ql.context.save:
	sub rsp, 136
	push qword [rsp+136]
	pushfq
	pop qword [rsp+136]

	mov [rsp+0x08], rax
	mov [rsp+0x10], rbx
	mov [rsp+0x18], rcx
	mov [rsp+0x20], rdx
	mov [rsp+0x28], rsi
	mov [rsp+0x30], rdi
	mov [rsp+0x38], rbp
	mov [rsp+0x40], rsp
	add qword [rsp+0x40], 152

	mov [rsp+0x48], r8
	mov [rsp+0x50], r9
	mov [rsp+0x58], r10
	mov [rsp+0x60], r11
	mov [rsp+0x68], r12
	mov [rsp+0x70], r13
	mov [rsp+0x78], r14
	mov [rsp+0x80], r15

	ret

ql.context.load:
	mov r8 , [rsp+0x48]
	mov r9 , [rsp+0x50]
	mov r10, [rsp+0x58]
	mov r11, [rsp+0x60]
	mov r12, [rsp+0x68]
	mov r13, [rsp+0x70]
	mov r14, [rsp+0x78]
	mov r15, [rsp+0x80]

	mov rax, [rsp+0x08]
	mov rbx, [rsp+0x10]
	mov rcx, [rsp+0x18]
	mov rdx, [rsp+0x20]
	mov rsi, [rsp+0x28]
	mov rdi, [rsp+0x30]
	mov rbp, [rsp+0x38]
	
	push qword [rsp+136]
	popfq
	pop qword [rsp+136]
	add rsp, 136

	ret

ql.io:
	; rdi : is
	; rsi : os

	push qword 0
	call ql.proc.begin

	mov r12, rdi
	mov r13, rsi

	xor edi, edi
	lea rsi, [r12+r13+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr+0x40]
	mov rdx, 3 ; PROT_READ | PROT_WRITE
	mov r10, 0x22 ; MAP_PRIVATE | MAP_ANONYMOUS
	mov r8, -1
	xor r9d, r9d
	mov rax, 0x09
	syscall

;	mov rax, ql.io.s

	mov [rel ql.io.data], rax

	lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr]
	add rsi, r13
	mov [rax], rsi

	lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr]
	mov [rax+0x10], rsi
	add rsi, 0x20
	mov [rax+0x08], rsi

	lea rsi, [rax+ql.io.is.offset+ql.io.is.offsetStr]
	mov [rax+ql.io.is.offset], rsi
	mov [rax+ql.io.is.offset+0x08], rsi

	xor esi, esi
	mov [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr], rsi

	xor eax, eax
	call ql.proc.end
	ret

ql.$io: ;ql.~io
	push qword 0
	call ql.proc.begin


	mov rax, 0x0b
	mov rdi, [rel ql.io.data]
	mov rsi, [rdi]
	sub rsi, rdi
	add rsi, 0x20
	syscall


	call ql.proc.end
	ret

ql.io.is.load:
	mov r10, [rel ql.io.data]
	xor eax, eax
	mov rsi, [r10+ql.io.is.offset]
	mov rdx, [r10+0x10]
	xor edi, edi
	sub rdx, rsi
	jle .e0
	syscall

	mov r10, [rel ql.io.data]
	add [r10+ql.io.is.offset], rax

	ret

	.e0:
	xor rax, rax
	not rax
	ret

ql.io.is.unload:
	mov r10, [rel ql.io.data]
	lea rsi, [r10+ql.io.is.offset+ql.io.is.offsetStr]
	mov [r10+ql.io.is.offset], rsi
	mov [r10+ql.io.is.offset+0x08], rsi

	ret

ql.io.is.read_iu8_ns:
	; abcd sdbs 8901 2345
	; 1 11 1             
	mov rcx, [rel ql.io.data]
	mov rsi, [rcx+ql.io.is.offset+0x08]
	mov rcx, [rcx+ql.io.is.offset]

	xor eax, eax

	cmp byte [rsi], 0x2d
	mov byte [rsp-1], 0
	jnz .l0s

	inc rsi
	not byte [rsp-1]

	xor edx, edx
	jmp .l0m

	.l0s:
		movzx edx, byte [rsi]
		bt [rel ql.io.isNum], dx
		jnc .l0e

		inc rsi
		lea rdx, [rax*8+rdx-0x30]
	.l0m:
		cmp rsi, rcx
		lea rax, [rdx + rax*2]
		jb .l0s
	.l0e:

	mov rdx, rax
	mov rcx, [rel ql.io.data]
	neg rax
	test byte [rsp-1], 0xff
	mov [rcx+ql.io.is.offset+0x08], rsi
	cmovz rax, rdx

	ret

ql.io.is.read_iu8_s:
	; abcd sdbs 8901 2345
	; 1 11 1             
	mov rcx, [rel ql.io.data]
	xor eax, eax
	mov rsi, [rcx+ql.io.is.offset+0x08]
	mov rcx, [rcx+ql.io.is.offset]

	cmp byte [rsi], 0x2d
	mov byte [rsp-1], 0
	jnz .l0s

	inc rsi
	not byte [rsp-1]

	xor edx, edx
	jmp .l0m

	.l0s:
		movzx edx, byte [rsi]
		bt [rel ql.io.isNum], dx
		jnc .l0e

		inc rsi
		lea rdx, [rax*8+rdx-0x30]
	.l0m:
		cmp rsi, rcx
		lea rax, [rdx + rax*2]
		jb .l0s
	.l0e:

	.l1s:
		movzx edx, byte [rsi]
		bt [rel ql.io.isWhiteSpace], dx
		jnc .l1e

		inc rsi
		cmp rsi, rcx
		jb .l1s
	.l1e:

	mov rdx, rax
	mov rcx, [rel ql.io.data]
	neg rax
	test byte [rsp-1], 0xff
	mov [rcx+ql.io.is.offset+0x08], rsi
	cmovz rax, rdx

	ret

ql.io.os.flush:
	mov r10, [rel ql.io.data]
	mov r11, [r10+0x08]

	mov rax, 0x01
	mov rdi, 1
	lea rsi, [r11+ql.io.os.offsetStr]
	mov rdx, [r11]
	syscall

	mov r10, [rel ql.io.data]
	mov r11, [r10+0x08]
	mov qword [r11], 0

	ret

ql.io.os.write_cstr:
	;rdi : src

	mov r10, [rel ql.io.data]
	mov rsi, rdi
	mov r10, [r10+0x08]
	mov rdi, [r10]
	mov r8, rsi
	lea rdi, [r10+rdi+ql.io.os.offsetStr]

	.l0s:
		lodsb
		stosb

		test al, 0xff
		jnz .l0s

	sub rsi, r8
	dec rsi
	add [r10], rsi

	ret

ql.io.os.write_cstr_:
	; rdi : src

	mov r10, [rel ql.io.data]
	xor ecx, ecx
	vpxor ymm0, ymm0, ymm0
	mov r8, [r10+0x08]
	mov r9, [r8]
	lea r9, [r8+r9+ql.io.os.offsetStr]

	.l0s:
		vmovdqu ymm3, [rdi+rcx]

		vpcmpeqb ymm1, ymm3, ymm0
		vptest ymm0, ymm1
		jnc .l0e

		vmovdqu [r9+rcx], ymm3

		add rcx, 32
		jmp .l0s
	.l0e:
	
	lea rsi, [rdi+rcx]
	lea rdi, [r9+rcx]

	.l1s:
		lodsb
		stosb

		test al, 0xff
		jnz .l1s

	mov r10, [r10+0x08]
	lea rsi, [r10+ql.io.os.offsetStr]
	sub rdi, rsi
	mov [r10], rdi

	ret

ql.io.os.write_cstr_p: ; 64 packed
	;rdi : src

	mov r10, [rel ql.io.data]
	xor ecx, ecx
	vpxor ymm0, ymm0, ymm0
	mov r8, [r10+0x08]
	mov r9, [r8]
	lea r9, [r8+r9+ql.io.os.offsetStr]

	.l0s:
		vmovdqu ymm3, [rdi+rcx]
		vmovdqu [r9+rcx], ymm3

		vpcmpeqb ymm1, ymm3, ymm0
		vptest ymm0, ymm1
		jnc .l0e

		add rcx, 32
		jmp .l0s
	.l0e:

	lea rsi, [rdi+rcx-32]

	.l1s:
		lodsb

		test al, 0xff
		jnz .l1s

	mov r10, [r10+0x08]
	sub rsi, rdi
	add [r10], rsi

	ret

ql.io.os.write_i8:
	; rdi : u8 n

	push rbp
	mov rbp, rsp
	sub rsp, 0x40

	mov rax, rdi
	mov r10, 10
	mov byte [rbp-0x1f], 0
	lea rdi, [rbp-0x20]
	lea rsi, [rbp-0x20]

	bt rax, 0x3f
	jnc .l1s

		neg rax
		.l0s:
			xor edx, edx
			div r10
			add edx, 0x30
			mov [rdi], dl
			dec rdi
			test rax, rax
			jnz .l0s
		.l0e:
		mov byte [rdi], 0x2d
		dec rdi
		jmp .c0e

	.c0.1:
		.l1s:
			xor edx, edx
			div r10
			add edx, 0x30
			mov [rdi], dl
			dec rdi
			test rax, rax
			jnz .l1s
		.l1e:
	.c0e:


	sub rsi, rdi

	mov r10, [ql.io.data]
	vmovdqu ymm0, [rdi+1]
	mov r11, [r10+0x08]
	mov r8, [r11]
	vmovdqu [r11+r8+ql.io.os.offsetStr], ymm0
	add [r11], rsi

	add rsp, 0x40
	pop rbp
	ret

ql.io.os.write_u8_:
	; rdi : u8 n

	push rbp
	mov rbp, rsp
	sub rsp, 0x40

	mov rax, rdi
	mov r10, 10
	mov byte [rbp-0x1f], 0
	lea rdi, [rbp-0x20]
	lea rsi, [rbp-0x20]

	.l0s:
		xor edx, edx
		div r10
		add edx, 0x30
		mov [rdi], dl
		dec rdi
		test rax, rax
		jnz .l0s
	.l0e:

	sub rsi, rdi

	mov r10, [rel ql.io.data]
	vmovdqu ymm0, [rdi+1]
	mov r11, [r10+0x08]
	mov r8, [r11]
	vmovdqu [r11+r8+ql.io.os.offsetStr], ymm0
	add [r11], rsi

	add rsp, 0x40
	pop rbp
	ret

ql.io.os.write_u8:
	; rdi : u8 n
	mov rax, 14757395258967641292

	mul rdi					;0
	mov rax, rdi			;1
	shr rdx, 3				;0
	lea rcx, [rdx+rdx*8]	;0
	mov rdi, rdx			;1
	add rcx, rdx			;0

	; ======== legacy ========
	push rbp
	mov rbp, rsp
	sub rsp, 0x40

	mov rax, rdi
	mov r10, 10
	mov byte [rbp-0x1f], 0
	lea rdi, [rbp-0x20]
	lea rsi, [rbp-0x20]

	.l0s:
		xor edx, edx
		div r10
		add edx, 0x30
		mov [rdi], dl
		dec rdi
		test rax, rax
		jnz .l0s
	.l0e:

	sub rsi, rdi

	mov r10, [rel ql.io.data]
	vmovdqu ymm0, [rdi+1]
	mov r11, [r10+0x08]
	mov r8, [r11]
	vmovdqu [r11+r8+ql.io.os.offsetStr], ymm0
	add [r11], rsi

	add rsp, 0x40
	pop rbp
	ret

section .bss
	as	resd 1_000_000
	a	resd 1_000_001
	ae:

section .text

main:
	push qword 80
	call ql.proc.begin

	mov rdi, 120000000
	mov rsi, 120000000
	call ql.io
	call ql.io.is.load

	call ql.io.is.read_iu8_s
	mov r12d, eax
	call ql.io.is.read_iu8_s
	vpxor ymm0, ymm0
	mov ebx, eax
	mov r14d, eax

	vmovdqu [rbp - 0x4c0], ymm0
	vmovdqu [rbp - 0x4a0], ymm0
	vmovdqu [rbp - 0x480], ymm0
	vmovdqu [rbp - 0x460], ymm0
	vmovdqu [rbp - 0x440], ymm0
	vmovdqu [rbp - 0x420], ymm0
	vmovdqu [rbp - 0x400], ymm0
	vmovdqu [rbp - 0x3e0], ymm0
	vmovdqu [rbp - 0x3c0], ymm0
	vmovdqu [rbp - 0x3a0], ymm0
	vmovdqu [rbp - 0x380], ymm0
	vmovdqu [rbp - 0x360], ymm0
	vmovdqu [rbp - 0x340], ymm0
	vmovdqu [rbp - 0x320], ymm0
	vmovdqu [rbp - 0x300], ymm0
	vmovdqu [rbp - 0x2e0], ymm0
	vmovdqu [rbp - 0x2c0], ymm0
	vmovdqu [rbp - 0x2a0], ymm0
	vmovdqu [rbp - 0x280], ymm0
	vmovdqu [rbp - 0x260], ymm0
	vmovdqu [rbp - 0x240], ymm0
	vmovdqu [rbp - 0x220], ymm0
	vmovdqu [rbp - 0x200], ymm0
	vmovdqu [rbp - 0x1e0], ymm0
	vmovdqu [rbp - 0x1c0], ymm0
	vmovdqu [rbp - 0x1a0], ymm0
	vmovdqu [rbp - 0x180], ymm0
	vmovdqu [rbp - 0x160], ymm0
	vmovdqu [rbp - 0x140], ymm0
	vmovdqu [rbp - 0x120], ymm0
	vmovdqu [rbp - 0x100], ymm0
	vmovdqu [rbp - 0x0e0], ymm0
	vmovdqu [rbp - 0x0c0], ymm0
	vmovdqu [rbp - 0x0a0], ymm0
	vmovdqu [rbp - 0x080], ymm0
	vmovdqu [rbp - 0x060], ymm0
	vmovdqu [rbp - 0x040], ymm0
	vmovdqu [rbp - 0x020], ymm0

	.l0s:
		xor r13d, r13d
		mov ebx, r14d
		.l0.l0s:
			call ql.io.is.read_iu8_s

			cmp r13d, [rbp + rbx*4 - 0x4c0]
			cmovb r13d, [rbp + rbx*4 - 0x4c0]
			add r13d, eax

			dec bx
			mov [rbp + rbx*4 - 0x4c0 + 4], r13d
			jnz .l0.l0s
		.l0.l0e:
		dec r12w
		jnz .l0s
	.l0e:

	mov edi, r13d
	call ql.io.os.write_u8_

	call ql.io.os.flush

	call ql.$io

	xor eax,eax

	call ql.proc.end
	ret
