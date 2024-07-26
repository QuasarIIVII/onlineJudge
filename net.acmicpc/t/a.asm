section .data
	s0 db "Hello World!",10,0

section .text
	global main
	extern scanf, printf, fgets, fputs, stdin, stdout
	extern sscanf, sprintf

proc.Begin:
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

proc.End:
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

main:
	mov rbp, 0x12
	mov r12, 0x34
	mov r13, 0x56
	mov r14, 0x78
	mov r15, 0x9a
	mov rbx, 0xbc

	mov rdi, 2
	call proc.Begin

	mov rdi, s0
	call printf

	xor rbp,rbp
	xor r12,r12
	xor r13,r13
	xor r14,r14
	xor r15,r15
	xor rbx,rbx

	xor rax,rax

	call proc.End
	ret
