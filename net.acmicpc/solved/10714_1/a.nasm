;indent setting : \t (0x09) which has width of 4 spaces (0x20)

section .data align=16
	s0 db "A",32,0
	s1 db "B",32,0
	s2 db 32,0
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

main.jt dq main.s1, main.s2

section .text

main:
	.st.sz equ 2048*4 + 2048*2048*8 + 4
	.st.d equ 2048*4 + 4

	push qword (.st.sz-1 >> 4)+1
	call ql.proc.begin

	mov rdi, 120000000
	mov rsi, 120000000
	call ql.io
	call ql.io.is.load

	vpxor ymm0, ymm0
	lea rbx, [rbp - .st.sz]
	lea rdx, [rbp - .st.d]
	.l2s:
		vmovdqu [rbx+0x00], ymm0
		vmovdqu [rbx+0x20], ymm0
		vmovdqu [rbx+0x40], ymm0
		vmovdqu [rbx+0x60], ymm0
		vmovdqu [rbx+0x80], ymm0
		vmovdqu [rbx+0xa0], ymm0
		vmovdqu [rbx+0xc0], ymm0
		vmovdqu [rbx+0xe0], ymm0
		add rbx, 32*8
		cmp rbx, rdx
		jnz .l2s
	.l2e:

	call ql.io.is.read_iu8_s
	mov ebx, eax
	mov [rbp - 4], eax

	.l0s:
		call ql.io.is.read_iu8_s
		mov [rbp + rbx*4 -4 - .st.d], eax
		dec ebx
		jnz .l0s
	.l0e:

	cmp dword [rbp - 4], 3
	mov eax, [rbp - 4]
	jae .s0
	jmp [main.jt + rax*8 - 8]

.s1:
	mov edi, [rbp - .st.d]
	call ql.io.os.write_u8_
	call ql.io.os.flush
	xor eax,eax
	call ql.proc.end
	ret
.s2:
	mov edi, [rbp - .st.d]
	mov esi, [rbp - .st.d + 4]
	cmp edi, esi
	cmovb edi, esi
	call ql.io.os.write_u8_
	call ql.io.os.flush
	xor eax,eax
	call ql.proc.end
	ret

.s0:
	mov r12d, dword [rbp - 4] ; 0 (-1 + 1)
	xor r13d, r13d ; 0
	mov r14d, 1 ; 1
	mov rbx, rbp
	mov ebp, dword [rbp - 4]
	xor r15d, r15d

	.l1s:
		mov edi, r14d
		lea esi, [r12d - 1]

		call g
		mov ecx, [rbx + r13*4 - .st.d]

		lea edx, [r14d + ebp - 1]
		dec r14d
		cmovl r14d, edx

		add rax, rcx

		lea edx, [r13d + ebp - 1]
		dec r13d
		cmovl r13d, edx

		cmp rax, r15
		cmova r15, rax

		dec r12d
		jnz .l1s
	.l1e:

	mov rbp, rbx

	mov rdi, r15
	call ql.io.os.write_u8_

	call ql.io.os.flush

	call ql.$io

	xor eax,eax

	call ql.proc.end
	ret

; rbx : base
; edi : l
; esi : r
f:
	.st.sz equ 12

	mov eax, edi ; eax = l
	shl rax, 11+3 ; rax = l*2048 * 8
	lea rcx, [rax + rsi*8] ; rcx = 8 * (l*2048 + r)
	xor edx, edx
	cmp [rbx + rcx - main.st.sz], rdx
	cmovnz rax, [rbx + rcx - main.st.sz]
	jnz .ret

	cmp edi, esi
	cmovz eax, [rbx + rsi*4 - main.st.d]
	mov [rbx + rcx - main.st.sz], rax

	cmp edi, esi
	jz .ret

	sub rsp, .st.sz

	mov [rsp], di ; push di = l
	mov eax, [rbx - 4] ; n
	inc di ; di = l + 1
	mov [rsp+2], si ; push si = r
	mov ecx, edi ; l+1
	lea edx, [esi - 1] ; r - 1
	lea esi, [esi + eax - 1] ; r + n - 1
	sub edi, eax ; l - n + 1

	cmp esi, eax
	cmovae esi, edx ; rr
	cmp ecx, eax
	mov [rsp+4], esi ; push esi = rr
	cmovb edi, ecx ; ll

	movzx esi, word [rsp+2]
	call g

	movzx edi, word [rsp]
	mov esi, [rsp+4]
	mov [rsp + 4], rax

	call g

	mov rcx, [rsp + 4] ; rcx = g(ll, r)
	movzx edi, word [rsp]
	movzx esi, word [rsp+2]
	mov edx, [rbx + rdi*4 - main.st.d]
	add rcx, rdx ; rcx = g(ll, r) + a[l]
	mov edx, [rbx + rsi*4 - main.st.d]
	add rax, rdx ; rax = g(l, rr) + a[r]

	shl rdi, 11+3; rdi = l*2048 * 8

	cmp rcx, rax
	lea rdi, [rdi + rsi*8] ; rdi = 8 * (l*2048 + r)
	cmova rax, rcx ; rax = max(rax, rcx)
	add rsp, .st.sz
	mov [rbx + rdi - main.st.sz], rax ; a[l][r] = rax
.ret:
	ret

; rbx : base
; edi : l
; esi : r
g:
	.st.sz equ 4

	mov eax, edi ; eax = l
	shl rax, 11+3 ; rax = l*2048 * 8
	lea rax, [rax + rsi*8] ; rax = 8 * (l*2048 + r)
	xor edx, edx
	cmp [rbx + rax - main.st.sz], rdx ; if a[l][r] != 0
	cmovnz rax, [rbx + rax - main.st.sz] ; then ret = a[l][r]
	jnz .ret ; then return

	cmp edi, esi
	cmovz eax, edx
	mov [rbx + rax - main.st.sz], rdx
	jz .ret

	sub rsp, .st.sz

	mov ecx, [rbx + rdi*4 - main.st.d] ; ecx = a[l]
	mov edx, [rbx + rsi*4 - main.st.d] ; edx = a[r]
	mov [rsp], di ; push di = l
	mov [rsp+2], si ; push si = r

	cmp ecx, edx
	jae .c0m

	.c0s:
		mov eax, [rbx - 4] ; eax = n
		lea eax, [esi + eax - 1] ; edx = r + n - 1
		dec esi ; esi = r - 1
		cmovl esi, eax ; esi = r < 1 ? r + n - 1 : r - 1
		call f
		jmp .c0e
	.c0m:
		mov eax, [rbx - 4] ; eax = n
		lea edx, [edi + 1] ; edx = l + 1
		inc edi ; edi = l + 1
		sub edi, eax ; edx = l - n + 1
		cmovb edi, edx ; edi = l+1 < n ? l + 1 : l - n + 1
		call f
	.c0e:

	movzx edi, word [rsp]
	movzx esi, word [rsp+2]
	shl rdi, 11+3; rdi = l*2048 * 8
	lea rdi, [rdi + rsi*8] ; rdi = 8 * (l*2048 + r)
	mov [rbx + rdi - main.st.sz], rax ; a[l][r] = rax
	add rsp, .st.sz

.ret:
	ret
