section .data align=16
	s0 db "Hello World!",10,0
	s1 db "%llx",10,0

	ql.io.data dq 0
	ql.io.is.offset equ 0x10
	ql.io.os.offsetStr equ 0x08
	ql.io.is.offsetStr equ 0x08

section .bss align=16

section .text
	global main
	extern scanf, printf, fgets, fputs, stdin, stdout
	extern sscanf, sprintf

ql.proc.begin_:
	; rdi : nOWords (128 bits / 16 bytes)

	push rbp
	push r12
	push r13
	push r14
	push r15
	pushfq
	shl rdi, 1
	mov rbp, rsp
	neg rdi
	lea rsp, [rsp+8*rdi-8]
	neg rdi
	push rdi

	push qword [rsp+8*rdi+64]
	mov [rsp+8*rdi+72], rbx

	ret

ql.proc.begin:
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

	xor rdi, rdi
	lea rsi, [r12+r13+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr+0x20]
	mov rdx, 3 ; PROT_READ | PROT_WRITE
	mov r10, 0x22 ; MAP_PRIVATE | MAP_ANONYMOUS
	mov r8, -1
	xor r9, r9
	mov rax, 0x09
	syscall


	mov [ql.io.data], rax

	lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr]
	add rsi, r13
	mov [rax], rsi

	lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr]
	mov [rax+0x08], rsi

	xor rsi, rsi
	mov [rax+ql.io.is.offset], rsi
	mov [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr], rsi

	xor rax, rax
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
	push qword 0
	call ql.proc.begin

	mov r12, [ql.io.data]

	mov rcx, [r12+ql.io.is.offset]
	mov rdx, [r12+0x08]
	neg rcx
	sub rdx, r12

	lea rsi, [r12+ql.io.is.offset+ql.io.is.offsetStr]
	xor rax, rax
	xor rdi, rdi
	lea rdx, [rdx+rbx-ql.io.is.offset-ql.io.is.offsetStr]
	add rsi, [r12+ql.io.is.offset]
	test rdx, rdx
	jz .ql.io.is.load.e0
	syscall

	add [r12+ql.io.is.offset], rax

	call ql.proc.end
	ret

.ql.io.is.load.e0:
	mov rax, 1
	ret

ql.io.is.unload:
	mov rdi, [ql.io.data]
	mov qword [rdi+ql.io.is.offset], 0

	ret

ql.io.os.flush:
ql.io.os.write_cstr:
ql.io.os.write_cstr_p: ; 64 packed
	; rdi : src

	mov rsi, [ql.io.data]
	xor rcx, rcx
	vpxor ymm0, ymm0, ymm0
	mov r8, [rsi+0x08]
	mov r9, [r8]
	lea r9, [r8+r9+ql.io.os.offsetStr]

.ql.io.os.write_cstr_p.l0s:
		vmovdqu ymm3, [rdi+rcx]
		vpcmpeqb ymm1, ymm3, ymm0

		vextractf128 xmm2, ymm1, 1
		vpor xmm1, xmm1, xmm2

		pextrq rax, xmm1, 0
		pextrq rdx, xmm1, 1

		or rax, rdx
		jnz .ql.io.os.write_cstr_p.l0e

		vmovdqu [r9+rcx], ymm3

		add rcx, 32
		jmp .ql.io.os.write_cstr_p.l0s
.ql.io.os.write_cstr_p.l0e:

	ret

ql.io.os.write_i8:
ql.io.os.write_u8:
	ret

main:
	push qword 2
	call ql.proc.begin

	mov rdi, 32
	mov rsi, 128
	call ql.io
	call ql.io.is.load

	call ql.context.save
		mov rax, 1
		mov rdi, 1
		mov r12, [ql.io.data]
		lea rsi, [r12+ql.io.is.offset+ql.io.is.offsetStr]
		mov rdx, [r12+ql.io.is.offset]
		sub rdx, 1
		syscall
	call ql.context.load

	mov rdi, 1
	mov rsi, s0
	mov rdx, 13
	mov rax, 1
	syscall

	mov rdi, s0
	call printf

	call ql.$io

	xor rax,rax

	call ql.proc.end
	ret
