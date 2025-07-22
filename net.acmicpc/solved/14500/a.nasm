;indent setting : \t (0x09) which has width of 4 spaces (0x20)

section .data align=16
	s0 db "Hello World!",10,0
	s1 db "%llx",10,0
	s2 times 35 db 0x41, 0x42, 0x43
	db "q", 0
	s3 db 10,0

;	ql.io.s times 40000000 db 0

	ql.io.data dq 0
	ql.io.is.offset equ 0x18
	ql.io.os.offsetStr equ 0x08
	ql.io.is.offsetStr equ 0x10

;	           			     $       7       6       5       4       3       2       1       0
	ql.io.is$			equ 0b0000000000000000000000000000000000000000000000000000000000000000
	ql.io.isNum			equ 0b0000001111111111000000000000000000000000000000000000000000000000
	ql.io.isWhiteSpace	equ 0b0000000000000000000000000000000100000000000000000011111000000000
;	           			     $       F       E       D       C       B       A       9       8
	ql.io.isLetter		equ 0b0000011111111111111111111111111000000111111111111111111111111110
	ql.io.isLetterS		equ 0b0000011111111111111111111111111000000000000000000000000000000000
	ql.io.isLetterB		equ 0b0000000000000000000000000000000000000111111111111111111111111110

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

	mov [ql.io.data], rax

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
	mov rdi, [ql.io.data]
	mov rsi, [rdi]
	sub rsi, rdi
	add rsi, 0x20
	syscall


	call ql.proc.end
	ret

ql.io.is.load:
	mov r10, [ql.io.data]
	xor eax, eax
	mov rsi, [r10+ql.io.is.offset]
	mov rdx, [r10+0x10]
	xor edi, edi
	sub rdx, rsi
	jle .e0
	syscall

	mov r10, [ql.io.data]
	add [r10+ql.io.is.offset], rax

	ret

	.e0:
	xor rax, rax
	not rax
	ret

ql.io.is.unload:
	mov r10, [ql.io.data]
	lea rsi, [r10+ql.io.is.offset+ql.io.is.offsetStr]
	mov [r10+ql.io.is.offset], rsi
	mov [r10+ql.io.is.offset+0x08], rsi

	ret

ql.io.is.read_iu8:
	; rdi : bool skipFollowingwhiteSpaces

	mov r10, [ql.io.data]
	mov r9, ql.io.isNum
	mov rsi, [r10+ql.io.is.offset+0x08]
	mov r11, [r10+ql.io.is.offset]

	xor eax, eax

	movzx r8, byte [rsi]
	xor ecx, ecx
	xor r8, 0x2d ; - sign
	jnz .l0s

	inc rsi
	not rcx

	.l0s:
		movzx r8, byte [rsi]

		cmp rsi, r11
		jge .l0e

		bt r9, r8
		jnc .l0e


		lea rdx, [rax*8+r8-0x30]
		inc rsi
		lea rax, [rdx + rax*2]
		jmp .l0s
	.l0e:

	jecxz .c0e
		neg rax
	.c0e:

	test dil, 0xff
	mov r9, ql.io.isWhiteSpace
	jz .c1e
		.l1s:
			movzx edx, byte [rsi]
			bt r9, rdx
			jnc .l1e

			inc rsi
			jmp .l1s
		.l1e:
	.c1e:

	mov rdi, [ql.io.data]
	mov [rdi+ql.io.is.offset+0x08], rsi

	ret

ql.io.os.flush:
	mov r10, [ql.io.data]
	mov r11, [r10+0x08]

	mov rax, 0x01
	mov rdi, 1
	lea rsi, [r11+ql.io.os.offsetStr]
	mov rdx, [r11]
	syscall

	mov r10, [ql.io.data]
	mov r11, [r10+0x08]
	mov qword [r11], 0

	ret

ql.io.os.write_cstr:
	;rdi : src

	mov r10, [ql.io.data]
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

	mov r10, [ql.io.data]
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

	mov r10, [ql.io.data]
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
ql.io.os.write_u8:
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

	mov r10, [ql.io.data]
	vmovdqu ymm0, [rdi+1]
	mov r11, [r10+0x08]
	mov r8, [r11]
	vmovdqu [r11+r8+ql.io.os.offsetStr], ymm0
	add [r11], rsi

	add rsp, 0x40
	pop rbp
	ret

section .data align=32
	a:
		dw +0,-1,+0,+0, -1,-1,+0,+0, +0,-1,+0,+0, +0,+0,+0,+0
		dw -1,+0,+0,+0, -1,-1,+0,+0, -1,+0,+0,+0, +0,+0,+0,+0
		dw -1,-1,-1,+0, +0,-1,+0,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw +0,-1,+0,+0, -1,-1,-1,+0, +0,+0,+0,+0, +0,+0,+0,+0

		dw -1,-1,+0,+0, +0,-1,-1,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw +0,-1,-1,+0, -1,-1,+0,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw +0,-1,+0,+0, -1,-1,+0,+0, -1,+0,+0,+0, +0,+0,+0,+0
		dw -1,+0,+0,+0, -1,-1,+0,+0, +0,-1,+0,+0, +0,+0,+0,+0

		dw -1,-1,-1,+0, +0,+0,-1,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw +0,+0,-1,+0, -1,-1,-1,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw -1,-1,+0,+0, -1,+0,+0,+0, -1,+0,+0,+0, +0,+0,+0,+0
		dw -1,-1,+0,+0, +0,-1,+0,+0, +0,-1,+0,+0, +0,+0,+0,+0
		dw -1,+0,+0,+0, -1,-1,-1,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw -1,-1,-1,+0, -1,+0,+0,+0, +0,+0,+0,+0, +0,+0,+0,+0
		dw +0,-1,+0,+0, +0,-1,+0,+0, -1,-1,+0,+0, +0,+0,+0,+0
		dw -1,+0,+0,+0, -1,+0,+0,+0, -1,-1,+0,+0, +0,+0,+0,+0

		dw -1,-1,+0,+0, -1,-1,+0,+0, +0,+0,+0,+0, +0,+0,+0,+0

		dw -1,+0,+0,+0, -1,+0,+0,+0, -1,+0,+0,+0, -1,+0,+0,+0
		dw -1,-1,-1,-1, +0,+0,+0,+0, +0,+0,+0,+0, +0,+0,+0,+0
	b:
		dw -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1, -1,-1,-1,-1


section .text
main:
	push qword 32768
	; 0 - 524_288
	call ql.proc.begin

	mov rdi, 1_500_000
	mov rsi, 16
	call ql.io
	call ql.io.is.load

	mov dil, 1
	call ql.io.is.read_iu8
	mov r12w, ax

	mov dil, 1
	call ql.io.is.read_iu8
	mov r13w, ax

	lea rbx, [rbp-524_288]
	mov r14w, r12w

	vpxor ymm0, ymm0
	.l0s:
		movzx r15d, r13w
		movdqu [rbx + r15*2], xmm0

		.l0.l0s:
			mov dil, 1
			call ql.io.is.read_iu8
			mov [rbx + r15*2 - 2], ax
		.l0.l0m:
			dec r15w
			jnz .l0.l0s
		.l0.l0e:
	.l0m:
		dec r14w
		lea rbx, [rbx + 1024]
		jnz .l0s
	.l0e:

	vmovdqu [rbx+0x000], ymm0
	vmovdqu [rbx+0x020], ymm0
	vmovdqu [rbx+0x040], ymm0
	vmovdqu [rbx+0x060], ymm0
	vmovdqu [rbx+0x080], ymm0
	vmovdqu [rbx+0x0a0], ymm0
	vmovdqu [rbx+0x0c0], ymm0
	vmovdqu [rbx+0x0e0], ymm0
	vmovdqu [rbx+0x100], ymm0
	vmovdqu [rbx+0x120], ymm0
	vmovdqu [rbx+0x140], ymm0
	vmovdqu [rbx+0x160], ymm0
	vmovdqu [rbx+0x180], ymm0
	vmovdqu [rbx+0x1a0], ymm0
	vmovdqu [rbx+0x1c0], ymm0
	vmovdqu [rbx+0x1e0], ymm0
	vmovdqu [rbx+0x200], ymm0
	vmovdqu [rbx+0x220], ymm0
	vmovdqu [rbx+0x240], ymm0
	vmovdqu [rbx+0x260], ymm0
	vmovdqu [rbx+0x280], ymm0
	vmovdqu [rbx+0x2a0], ymm0
	vmovdqu [rbx+0x2c0], ymm0
	vmovdqu [rbx+0x2e0], ymm0
	vmovdqu [rbx+0x300], ymm0
	vmovdqu [rbx+0x320], ymm0
	vmovdqu [rbx+0x340], ymm0
	vmovdqu [rbx+0x360], ymm0
	vmovdqu [rbx+0x380], ymm0
	vmovdqu [rbx+0x3a0], ymm0
	vmovdqu [rbx+0x3c0], ymm0
	vmovdqu [rbx+0x3e0], ymm0
	vmovdqu [rbx+0x400], ymm0
	vmovdqu [rbx+0x420], ymm0
	vmovdqu [rbx+0x440], ymm0
	vmovdqu [rbx+0x460], ymm0
	vmovdqu [rbx+0x480], ymm0
	vmovdqu [rbx+0x4a0], ymm0
	vmovdqu [rbx+0x4c0], ymm0
	vmovdqu [rbx+0x4e0], ymm0
	vmovdqu [rbx+0x500], ymm0
	vmovdqu [rbx+0x520], ymm0
	vmovdqu [rbx+0x540], ymm0
	vmovdqu [rbx+0x560], ymm0
	vmovdqu [rbx+0x580], ymm0
	vmovdqu [rbx+0x5a0], ymm0
	vmovdqu [rbx+0x5c0], ymm0
	vmovdqu [rbx+0x5e0], ymm0
	vmovdqu [rbx+0x600], ymm0
	vmovdqu [rbx+0x620], ymm0
	vmovdqu [rbx+0x640], ymm0
	vmovdqu [rbx+0x660], ymm0
	vmovdqu [rbx+0x680], ymm0
	vmovdqu [rbx+0x6a0], ymm0
	vmovdqu [rbx+0x6c0], ymm0
	vmovdqu [rbx+0x6e0], ymm0
	vmovdqu [rbx+0x700], ymm0
	vmovdqu [rbx+0x720], ymm0
	vmovdqu [rbx+0x740], ymm0
	vmovdqu [rbx+0x760], ymm0
	vmovdqu [rbx+0x780], ymm0
	vmovdqu [rbx+0x7a0], ymm0
	vmovdqu [rbx+0x7c0], ymm0
	vmovdqu [rbx+0x7e0], ymm0
	vmovdqu [rbx+0x800], ymm0
	vmovdqu [rbx+0x820], ymm0
	vmovdqu [rbx+0x840], ymm0
	vmovdqu [rbx+0x860], ymm0
	vmovdqu [rbx+0x880], ymm0
	vmovdqu [rbx+0x8a0], ymm0
	vmovdqu [rbx+0x8c0], ymm0
	vmovdqu [rbx+0x8e0], ymm0
	vmovdqu [rbx+0x900], ymm0
	vmovdqu [rbx+0x920], ymm0
	vmovdqu [rbx+0x940], ymm0
	vmovdqu [rbx+0x960], ymm0
	vmovdqu [rbx+0x980], ymm0
	vmovdqu [rbx+0x9a0], ymm0
	vmovdqu [rbx+0x9c0], ymm0
	vmovdqu [rbx+0x9e0], ymm0
	vmovdqu [rbx+0xa00], ymm0
	vmovdqu [rbx+0xa20], ymm0
	vmovdqu [rbx+0xa40], ymm0
	vmovdqu [rbx+0xa60], ymm0
	vmovdqu [rbx+0xa80], ymm0
	vmovdqu [rbx+0xaa0], ymm0
	vmovdqu [rbx+0xac0], ymm0
	vmovdqu [rbx+0xae0], ymm0
	vmovdqu [rbx+0xb00], ymm0
	vmovdqu [rbx+0xb20], ymm0
	vmovdqu [rbx+0xb40], ymm0
	vmovdqu [rbx+0xb60], ymm0
	vmovdqu [rbx+0xb80], ymm0
	vmovdqu [rbx+0xba0], ymm0
	vmovdqu [rbx+0xbc0], ymm0
	vmovdqu [rbx+0xbe0], ymm0

	mov cx, r12w
	lea rbx, [rbp-524_288]
	xor rax, rax

	lea r14w, [r13d + 1]
	and r14w, 0xfffe

	.l1s:
		movzx edx, r14w

		.l1.l0s:
			vpinsrq xmm1, [rbx + 2*rdx - 2 +1024*2], 0
			vpinsrq xmm0, [rbx + 2*rdx - 2 +1024*0], 0
			vpinsrq xmm1, [rbx + 2*rdx - 2 +1024*3], 1
			vpinsrq xmm0, [rbx + 2*rdx - 2 +1024*1], 1
			vperm2f128 ymm0, ymm0, ymm1, 0x20

			vpinsrq xmm3, [rbx + 2*rdx - 4 +1024*2], 0
			vpinsrq xmm2, [rbx + 2*rdx - 4 +1024*0], 0
			vpinsrq xmm3, [rbx + 2*rdx - 4 +1024*3], 1
			vpinsrq xmm2, [rbx + 2*rdx - 4 +1024*1], 1
			vperm2f128 ymm2, ymm2, ymm3, 0x20

			lea rsi, [rel a]
			lea rdi, [rel b]
			.l1.l0.l0s:
				vpand ymm1, ymm0, [rsi]
				vpand ymm3, ymm2, [rsi]
				vphaddw ymm1, ymm1, ymm3
				vpermq ymm1, ymm1, 0b11011000
				vphaddw ymm1, ymm1, ymm1
				vphaddw ymm1, ymm1, ymm1
				vphaddw ymm1, ymm1, ymm1
				vpermq ymm1, ymm1, 0b11011000

				vpextrw r8d, xmm1, 0
				vpextrw r9d, xmm1, 4
				cmp ax, r8w
				cmovb ax, r8w
				cmp ax, r9w
				cmovb ax, r9w
			.l1.l0.l0m:
				add rsi, 32
				cmp rsi, rdi
				jnz .l1.l0.l0s
			.l1.l0.l0e:
		.l1.l0m:
			sub dx, 2
			jnz .l1.l0s
		.l1.l0e:
	.l1m:
		dec cx
		lea rbx, [rbx+1024]
		jnz .l1s
	.l1e:

	movzx edi, ax
	call ql.io.os.write_u8

	call ql.io.os.flush

	call ql.$io

	xor eax,eax

	call ql.proc.end
	ret
