;indent setting : \t (0x09) which has width of 4 spaces (0x20)

; ql v1
section .data align=16
	s0 db 32,0
	s1 db 10,0
	sa db "A",10,0
	sb db "B",10,0
	sc db "C",10,0

;	ql.io.s times 40000000 db 0

	ql.io.data dq 0

	ql.io.end equ 0
	ql.io.os.pdata equ 0x08
	ql.io.os.data_e equ 0x10
	ql.io.os.p equ 0x18
	ql.io.is.data_e equ 0x20
	ql.io.is.p equ 0x28
	ql.io.is.q equ 0x30
	ql.io.reserved0 equ 0x38
	ql.io.is.data equ 0x40
	ql.io.sz equ ql.io.is.data

section .data align=16
	; 0 : is_control
	; 1 : is_space
	; 2 : is_digit
	; 3 : is_upper
	; 4 : is_lower
ql.io.type:
	db 01,01,01,01,01,01,01,01,01,03,03,03,03,03,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01,01
	db 02,00,00,00,00,00,00,00,00,00,00,00,00,00,00,00,04,04,04,04,04,04,04,04,04,04,00,00,00,00,00,00
	db 00,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,08,00,00,00,00,00
	db 00,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,16,00,00,00,00,01
	times 128 db 0

section .bss align=16

section .text

ql.proc.begin:
	; usuage
	; r10 : return address
	; r11 : nOWords ; nOWords : number of owords (128 bits / 16 bytes) to reserve
	; jmp ql.proc.begin
	; rbx = old rsp

	mov [rsp - 0x08], r12
	lea r11, [r11*2]
	mov [rsp - 0x10], r13
	mov [rsp - 0x18], r14
	mov [rsp - 0x20], r15
	neg r11
	mov [rsp - 0x28], rbx

	lea r11, [rsp + r11*8 - 0x48]
	mov rbx, rsp
	mov rsp, r11

	mov [r11 + 8], rbp
	mov [r11], rbx
	lea rbp, [rbx - 0x28]

	jmp r10

ql.proc.end:
	; jmp ql.proc.end
	mov rsi, [rsp]
	mov rbp, [rsp + 8]
	mov rsp, [rsp]

	mov r12, [rsi - 0x08]
	mov r13, [rsi - 0x10]
	mov r14, [rsi - 0x18]
	mov r15, [rsi - 0x20]
	mov rbx, [rsi - 0x28]

	ret

ql.ctx.setjmp:
	; rdi : *buf

	; return values
	; rax : 0 if returning directly,
	;       rip of longjmp caller if returning via longjmp
	; rdx : sig if returning via longjmp
	mov rax, [rsp]
	mov [rdi       ], rbx
	mov [rdi + 0x08], rbp
	mov [rdi + 0x10], r12
	mov [rdi + 0x18], r13
	mov [rdi + 0x20], r14
	mov [rdi + 0x28], r15
	mov [rdi + 0x30], rsp
	mov [rdi + 0x38], rax
	xor eax, eax
	ret

ql.ctx.longjmp:
	; rdi : *buf
	; rsi : sig
	mov rax, [rdi + 0x38]
	mov rbx, [rdi       ]
	mov rbp, [rdi + 0x08]
	mov r12, [rdi + 0x10]
	mov r13, [rdi + 0x18]
	mov r14, [rdi + 0x20]
	mov r15, [rdi + 0x28]
	mov rsp, [rdi + 0x30]

	mov rdi, [rsp]
	mov [rsp], rax
	mov rax, rsi
	mov rdx, rdi

	ret

ql.ctx.save:
	 ; no recursive calls
	pushfq
	lea rsp, [rsp + 8]

	mov [rsp - 0x10], rax
	mov [rsp - 0x18], rbx
	mov [rsp - 0x20], rcx
	mov [rsp - 0x28], rdx
	mov [rsp - 0x30], rsi
	mov [rsp - 0x38], rdi
	mov [rsp - 0x40], rbp
	mov [rsp - 0x48], r8
	mov [rsp - 0x50], r9
	mov [rsp - 0x58], r10
	mov [rsp - 0x60], r11
	mov [rsp - 0x68], r12
	mov [rsp - 0x70], r13
	mov [rsp - 0x78], r14
	mov [rsp - 0x80], r15

	ret

ql.ctx.load:
	lea rsp, [rsp - 8]
	popfq

	mov r15, [rsp - 0x88]
	mov r14, [rsp - 0x80]
	mov r13, [rsp - 0x78]
	mov r12, [rsp - 0x70]
	mov r11, [rsp - 0x68]
	mov r10, [rsp - 0x60]
	mov r9 , [rsp - 0x58]
	mov r8 , [rsp - 0x50]
	mov rbp, [rsp - 0x48]
	mov rdi, [rsp - 0x40]
	mov rsi, [rsp - 0x38]
	mov rdx, [rsp - 0x30]
	mov rcx, [rsp - 0x28]
	mov rbx, [rsp - 0x20]
	mov rax, [rsp - 0x18]

	ret

ql.ctx.save#r:
	; support recursive calls
	lea rsp, [rsp - 0x70]
	pushfq
	push qword [rsp + 0x78]

	mov [rsp + 0x10], r15
	mov [rsp + 0x18], r14
	mov [rsp + 0x20], r13
	mov [rsp + 0x28], r12
	mov [rsp + 0x30], r11
	mov [rsp + 0x38], r10
	mov [rsp + 0x40], r9
	mov [rsp + 0x48], r8
	mov [rsp + 0x50], rbp
	mov [rsp + 0x58], rdi
	mov [rsp + 0x60], rsi
	mov [rsp + 0x68], rdx
	mov [rsp + 0x70], rcx
	mov [rsp + 0x78], rbx
	mov [rsp + 0x80], rax

	ret

ql.ctx.load#r:
	mov rax, [rsp + 0x80]
	pop qword [rsp + 0x78]
	popfq
	lea rsp, [rsp + 0x70]

	mov rbx, [rsp - 0x08]
	mov rcx, [rsp - 0x10]
	mov rdx, [rsp - 0x18]
	mov rsi, [rsp - 0x20]
	mov rdi, [rsp - 0x28]
	mov rbp, [rsp - 0x30]
	mov r8 , [rsp - 0x38]
	mov r9 , [rsp - 0x40]
	mov r10, [rsp - 0x48]
	mov r11, [rsp - 0x50]
	mov r12, [rsp - 0x58]
	mov r13, [rsp - 0x60]
	mov r14, [rsp - 0x68]
	mov r15, [rsp - 0x70]

	ret

ql.io:
	; rdi : is
	; rsi : os

	mov r11d, 0
	lea r10, [rel $+12]
	jmp ql.proc.begin

	xor r8d, r8d
	mov eax, 9 ; mmap
	mov r12, rdi ; backup r12 = rdi = is
	mov r13, rsi ; backup r13 = rsi = os
	lea rsi, [rdi+rsi + ql.io.sz+0x40] ; length
	mov edx, 3 ; PROT_READ | PROT_WRITE
	xor edi, edi ; addr = 0 (no hint)
	not r8 ; fd = -1
	mov r10, 0x22 ; ANON | PRIVATE
	xor r9d, r9d ; offset = 0
	syscall ; -1 on fail

	lea rcx, [rax + r12 + ql.io.sz] ; rcx = base + is
	lea rdx, [rax + r12 + ql.io.sz + 0x20] ; rdx = base + is + 0x20
	lea rbx, [rax + ql.io.sz]
	mov [rel ql.io.data], rax ; *ql.io.data = mmap(...)
	mov [rax + ql.io.is.data_e], rcx
	lea rcx, [rcx + r13 + 0x20] ; rcx += r13+0x20
	mov [rax + ql.io.os.pdata], rdx
	mov [rax + ql.io.os.p], rdx
	lea rdx, [rdx + r13 + 0x20] ; rdx += r13+0x20
	mov [rax + ql.io.is.p], rbx
	mov [rax + ql.io.is.q], rbx
	mov [rax + ql.io.os.data_e], rcx
	mov [rax], rdx ; ql.io.end

	xor eax, eax
	jmp ql.proc.end

	xor r11d, r11d
	lea r10, [rel $+12]
	jmp ql.proc.begin

ql.$io:
	mov rdi, [rel ql.io.data]
	mov rax, 0xb ; munmap
	mov rsi, [rdi]
	sub rsi, rdi ; size = ql.io.end - **ql.io.data
	syscall
	ret

ql.io.is.load:
	push r12

	mov r12, [rel ql.io.data]
	xor eax, eax

section .text
	global main
	extern setjmp, longjmp, puts, fflush, stdout

main:
	mov r11d, 16
	lea r10, [rel $+7+5]
	jmp ql.proc.begin

	mov edi, 16
	mov esi, 16
	call ql.io
	call ql.$io

	mov rbx, 0x0b0b0b0b
	mov rcx, 0x0c0c0c0c
	mov rdx, 0x0d0d0d0d
	mov rsi, 0x0e0e0e0e
	mov rdi, 0x0f0f0f0f
	mov r8,  0x08080808
	mov r9,  0x09090909
	mov r10, 0x10101010
	mov r11, 0x11111111
	mov r12, 0x12121212
	mov r13, 0x13131313
	mov r14, 0x14141414
	mov r15, 0x15151515

	xor eax, eax
	mov rax, 0x0a0a0a0a

	call ql.ctx.save
	xor eax, eax
	xor ebx, ebx
	xor ecx, ecx
	xor edx, edx
	xor esi, esi
	xor edi, edi
	xor ebp, ebp
	xor r8d, r8d
	xor r9d, r9d
	xor r10d, r10d
	xor r11d, r11d
	xor r12d, r12d
	xor r13d, r13d
	xor r14d, r14d
	xor r15d, r15d
	call ql.ctx.load

	xor eax,eax
	jmp ql.proc.end

f:
	mov rax, 0x0a0a0a0a
	mov rbx, 0x0b0b0b0b
	mov rcx, 0x0c0c0c0c
	mov rdx, 0x0d0d0d0d
	mov rsi, 0x0e0e0e0e
	mov rdi, 0x0f0f0f0f
	mov r8,  0x08080808
	mov r9,  0x09090909
	mov r10, 0x10101010
	mov r11, 0x11111111
	mov r12, 0x12121212
	mov r13, 0x13131313
	mov r14, 0x14141414
	mov r15, 0x15151515

	xor eax, eax

	call ql.ctx.save
	xor eax, eax
	xor ebx, ebx
	xor ecx, ecx
	xor edx, edx
	xor esi, esi
	xor edi, edi
	xor ebp, ebp
	xor r8d, r8d
	xor r9d, r9d
	xor r10d, r10d
	xor r11d, r11d
	xor r12d, r12d
	xor r13d, r13d
	xor r14d, r14d
	xor r15d, r15d
	call ql.ctx.load

g:
	lea rdi, [rbp - 0x100]
	call ql.ctx.setjmp
	test eax, eax
	lea rdi, [rel $+7+6]
	cmovnz rdi, rdx

	jmp rdi

	lea rdi, [rbp - 0x100]
	call ql.ctx.longjmp


