;indent setting : \t (0x09) which has width of 4 spaces (0x20)

section .data align=16
	s0 db "Hello World!",10,0
	s1 db 0x20, 0
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
	mov r10, 10

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


		mul r10
		inc rsi
		lea rax, [rax+r8-0x30]
		jmp .l0s
	.l0e:

	jecxz .c0e
		neg rax
	.c0e:

	mov rcx, rdi
	mov r9, ql.io.isWhiteSpace
	jecxz .c1e
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

main:
	push qword 0x2aaa+2 ; 0x2aac0 bytes
	call ql.proc.begin

	mov rdi, 0x2aac0
	neg rdi
	vpxor ymm0, ymm0, ymm0
	.l1s:
		vmovdqu [rbp+rdi], ymm0
		vmovdqu [rbp+rdi+32], ymm0
		add rdi, 64
		jnz .l1s
	.l1e:

	mov rdi, 150000
	mov rsi, 400000
	call ql.io
	call ql.io.is.load

	mov dil, 1
	call ql.io.is.read_iu8

	mov dil, 1
	mov ebx, eax
	vpinsrb xmm0, eax, 0

	call ql.io.is.read_iu8
	vpinsrb xmm0, eax, 1

	; xmm0[0] : u1 n
	; xmm0[1] : u1 r

	mov r15d, 9
	.l0s:
		dec ebx
		shlx r13d, ebx, r15d

		vpextrb r12d, xmm0, 0
		add r13, rbp

		; jmp .l0.l0m
		.l0.l0s:
			mov dil, 1
			dec r12d
			call ql.io.is.read_iu8

			mov [r13 + r12*2 - 0x20000], ax
		.l0.l0m:
			test r12d, r12d
			jnz .l0.l0s
		.l0.l0e:

		test ebx, ebx
		jnz .l0s
	.l0e:

	xor edi, edi
	xor esi, esi
	mov rdx, rbp
	call f

	vmovdqa xmm1, xmm0
	vpextrb r12d, xmm1, 0

	.l2s:
		vpextrb r13d, xmm1, 0
		dec r12b

		.l2.l0s:
			dec r13b

			movzx edi, r12b
			movzx esi, r13b
			vpextrb edx, xmm1, 1
			call g

			movzx edi, ax
			call ql.io.os.write_i8
			lea rdi, [rel s1]
			call ql.io.os.write_cstr
		.l2.l0m:
			test r13b, r13b
			jnz .l2.l0s
		.l2.l0e:

		lea rdi, [rel s3]
		call ql.io.os.write_cstr

		test r12b, r12b
		jnz .l2s
	.l2e:

	call ql.io.os.flush

	call ql.$io

	xor eax,eax

	call ql.proc.end
	ret

f:
	mov r10d, 1
	mov ecx, 8
	mov r9, rdx
.f0:
	test cl, cl
	jnz .c0e
		mov eax, edi
		shl eax, 9
		add rax, r9
		mov ax, [rax + rsi*2 - 0x20000]
		ret
	.c0e:

	dec cl
	push rbx
	push di
	shlx ebx, r10d, ecx
	push si
	push word 0
		; (dil, sil)
		call .f0
		add [rsp], ax

		; (dil+bl, sil)
		add dil, bl
		call .f0
		add [rsp], ax

		; (dil+bl, sil+bl)
		add sil, bl
		call .f0
		add [rsp], ax

		; (dil, sil+bl)
		sub dil, bl
		call .f0
		add ax, [rsp]
	add rsp, 2
	inc cl
	movzx esi, word [rsp]
	movzx edi, word [rsp+2]

	mov r8, [t + 8*rcx]
	add r8, r9

	mov edx, 9
	shr dil, cl
	sub dl, cl
	shr sil, cl
	shlx edi, edi, edx

	add rdi, r8

	mov [rdi + rsi*2], ax

	movzx esi, word [rsp]
	movzx edi, word [rsp+2]
	mov rbx, [rsp+4]
	add rsp, 2+2+8

	ret

g:
	; rdi : u4 x
	; rsi : u4 y
	; rdx : u4 r

	mov ax, dx
	xor r10w, r10w
	lea dx, [edi + edx + 1] ; x+r
	lea cx, [esi + eax + 1] ; y+r

	cmp di, ax
	cmovl di, r10w
	jl .c0e
		sub di, ax
	.c0e:

	cmp si, ax
	cmovl si, r10w
	jl .c1e
		sub si, ax
	.c1e:

	push r15

	xor r8d, r8d
	xor r9d, r9d
	mov r10d, 8
	mov r15d, 1

	call .g0

	pop r15
	ret

.g0:
	; rdi : u2 l [l, r)
	; rsi : u2 t [t, b)
	; rdx : u2 r
	; rcx : u2 b
	; r8  : u4 x [x, x+lv)
	; r9  : u4 y [y, y+lv)
	; r10 : u4 lv

	shlx r11d, r15d, r10d ; [sz]r11d = (r15d=1) << (r10d&0x1F)

	; check if exclusive
	; x - r
	cmp r8w, dx
	lea ax, [r8d + r11d]
	jge .lb0
	; x+sz - l
	cmp ax, di
	jle .lb0
	; y - b
	cmp r9w, cx
	lea ax, [r9d + r11d]
	jge .lb0
	; y+sz - t
	cmp ax, si
	jle .lb0

	; check if inclusive
	; x - l
	cmp r8w, di
	lea ax, [r8d + r11d]
	jl .lb1
	; x+sz - r
	cmp ax, dx
	jg .lb1
	; y - t
	cmp r9w, si
	lea ax, [r9d + r11d]
	jl .lb1
	; y+sz - b
	cmp ax, cx
	jg .lb1

	.lb_0: ; inclusive
		push r8
		push r9
		push r11
		mov rax, [t + 8*r10]
		add rax, rbp
		mov r11d, 9
		shrx r8d, r8d, r10d
		sub r11b, r10b ; r11b = 8 - [lv]r10b
		shrx r9d, r9d, r10d
		shlx r8d, r8d, r11d

		add r8, rax
		mov ax, [r8 + r9*2]

		pop r11
		pop r9
		pop r8
		ret

	.lb0: ; exclusive
		xor eax, eax
		ret

	.lb1: ; overlapped && !inclusive
		shr r11w, 1

		push r8w
		push r9w
		dec r10b
		sub rsp, 2
			; (r8w, r9w)
			call .g0

			add r8w, r11w
			mov [rsp], ax

			; (r8w+r11w, r9w)
			call .g0

			add r9w, r11w
			add [rsp], ax

			; (r8w+r11w, r9w+r11w)
			call .g0

			sub r8w, r11w
			add [rsp], ax

			; (r8w, r9w+r11w)
			call .g0
			add ax, [rsp]
		movzx r9d, word [rsp + 2]
		movzx r8d, word [rsp + 4]
		add rsp, 6
		inc r10b

		shl r11w, 1

	ret

section .data align=16
	t dq -0x20000, -0x28000, -0x2a000, -0x2a800, -0x2aa00, -0x2aa80, -0x2aaa0, -0x2aaa8, -0x2aaaa
