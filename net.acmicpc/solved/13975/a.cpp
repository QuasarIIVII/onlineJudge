//; echo """
#include<iostream>
#include<sstream>
#include<string>
#include<string_view>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<memory>
#include<array>
#include<tuple>
#include<bitset>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<functional>
#include<algorithm>
#include<cmath>
#include<cstring>
//; echo """

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
										using f4=float;		using f8=double;	using f16=long double;
using uf1=uint_fast8_t;	using uf2=uint_fast16_t;using uf4=uint_fast32_t;using uf8=uint_fast64_t;
using if1=int_fast8_t;	using if2=int_fast16_t;	using if4=int_fast32_t;	using if8=int_fast64_t;

#ifdef ONLINE_JUDGE
constexpr bool debug=false;
#else
constexpr bool debug=true;
#endif

#ifdef ONLINE_JUDGE
#define DEBUG_MACRO(x)
#define DEBUG_MACRO_ELSE(x) x
#else
#define DEBUG_MACRO(x) x
#define DEBUG_MACRO_ELSE(x)
#endif

#define DEBUG if constexpr(debug)

asm(
".intel_syntax noprefix\n\t"
".text\n\t"
".globl main\n\t"
"	.section .data\n\t"
"	.p2align 4\n\t"
"s0:\n\t"
"	.ascii \"Hello World!\"\n\t"
"	.byte 10, 0\n\t"
"s1:\n\t"
"	.ascii \"%llx\"\n\t"
"	.byte 10, 0\n\t"
"s2:\n\t"
"	.rept 35\n\t"
"		.byte 0x41, 0x42, 0x43\n\t"
"	.endr\n\t"
"	.ascii \"q\"\n\t"
"	.byte 0\n\t"
"s3:\n\t"
"	.byte 10, 0\n\t"
"ql.io.s:\n\t"
"	.rept 2048\n\t"
"		.byte 0\n\t"
"	.endr\n\t"
"ql.io.data:\n\t"
"	.quad 0\n\t"
"	.equ ql.io.is.offset, 0x18\n\t"
"	.equ ql.io.os.offsetStr, 0x08\n\t"
"	.equ ql.io.is.offsetStr, 0x10\n\t"
"	.equ ql.io.is__dollar__,				0b0000000000000000000000000000000000000000000000000000000000000000\n\t"
"	.equ ql.io.isNum,			0b0000001111111111000000000000000000000000000000000000000000000000\n\t"
"	.equ ql.io.isWhiteSpace,	0b0000000000000000000000000000000100000000000000000011111000000000\n\t"
"	.equ ql.io.isLetter,		0b0000011111111111111111111111111000000111111111111111111111111110\n\t"
"	.equ ql.io.isLetterS,		0b0000011111111111111111111111111000000000000000000000000000000000\n\t"
"	.equ ql.io.isLetterB,		0b0000000000000000000000000000000000000111111111111111111111111110\n\t"
"	.section .bss\n\t"
"	.p2align 4\n\t"
".section .text\n\t"
"	ql.proc.begin:\n\t"
"		push r12\n\t"
"		mov r12, [rsp+0x10]\n\t"
"		push r13\n\t"
"		push r14\n\t"
"		push r15\n\t"
"		pushfq\n\t"
"		shl r12, 1\n\t"
"		neg r12\n\t"
"		lea rsp, [rsp+8*r12-0x08]\n\t"
"		neg r12\n\t"
"		push r12\n\t"
"		push QWORD PTR [rsp+8*r12+0x38]\n\t"
"		mov [rsp+8*r12+0x40], rbp\n\t"
"		mov [rsp+8*r12+0x48], rbx\n\t"
"		lea rbp, [rsp+8*r12+0x18]\n\t"
"		mov r12, [rsp+8*r12+0x38]\n\t"
"		ret\n\t"
"	ql.proc.end:\n\t"
"		mov rdi, [rsp+8]\n\t"
"		mov rbx, [rsp+8*rdi+72]\n\t"
"		pop QWORD PTR [rsp+8*rdi+64]\n\t"
"		lea rsp, [rsp+8*rdi+16]\n\t"
"		popfq\n\t"
"		pop r15\n\t"
"		pop r14\n\t"
"		pop r13\n\t"
"		pop r12\n\t"
"		pop rbp\n\t"
"		ret\n\t"
"	ql.context.save:\n\t"
"		sub rsp, 136\n\t"
"		push QWORD PTR [rsp+136]\n\t"
"		pushfq\n\t"
"		pop QWORD PTR [rsp+136]\n\t"
"		mov [rsp+0x08], rax\n\t"
"		mov [rsp+0x10], rbx\n\t"
"		mov [rsp+0x18], rcx\n\t"
"		mov [rsp+0x20], rdx\n\t"
"		mov [rsp+0x28], rsi\n\t"
"		mov [rsp+0x30], rdi\n\t"
"		mov [rsp+0x38], rbp\n\t"
"		mov [rsp+0x40], rsp\n\t"
"		add QWORD PTR [rsp+0x40], 152\n\t"
"		mov [rsp+0x48], r8\n\t"
"		mov [rsp+0x50], r9\n\t"
"		mov [rsp+0x58], r10\n\t"
"		mov [rsp+0x60], r11\n\t"
"		mov [rsp+0x68], r12\n\t"
"		mov [rsp+0x70], r13\n\t"
"		mov [rsp+0x78], r14\n\t"
"		mov [rsp+0x80], r15\n\t"
"		ret\n\t"
"	ql.context.load:\n\t"
"		mov r8 , [rsp+0x48]\n\t"
"		mov r9 , [rsp+0x50]\n\t"
"		mov r10, [rsp+0x58]\n\t"
"		mov r11, [rsp+0x60]\n\t"
"		mov r12, [rsp+0x68]\n\t"
"		mov r13, [rsp+0x70]\n\t"
"		mov r14, [rsp+0x78]\n\t"
"		mov r15, [rsp+0x80]\n\t"
"		mov rax, [rsp+0x08]\n\t"
"		mov rbx, [rsp+0x10]\n\t"
"		mov rcx, [rsp+0x18]\n\t"
"		mov rdx, [rsp+0x20]\n\t"
"		mov rsi, [rsp+0x28]\n\t"
"		mov rdi, [rsp+0x30]\n\t"
"		mov rbp, [rsp+0x38]\n\t"
"		push QWORD PTR [rsp+136]\n\t"
"		popfq\n\t"
"		pop QWORD PTR [rsp+136]\n\t"
"		add rsp, 136\n\t"
"		ret\n\t"
"	ql.io:\n\t"
"		push QWORD PTR 0\n\t"
"		call ql.proc.begin\n\t"
"		mov r12, rdi\n\t"
"		mov r13, rsi\n\t"
"		xor edi, edi\n\t"
"		lea rsi, [r12+r13+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr+0x40]\n\t"
"		mov rdx, 3\n\t"
"		mov r10, 0x22\n\t"
"		mov r8, -1\n\t"
"		xor r9d, r9d\n\t"
"		mov rax, 0x09\n\t"
"		syscall\n\t"
"		mov [rip + ql.io.data], rax\n\t"
"		lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr]\n\t"
"		add rsi, r13\n\t"
"		mov [rax], rsi\n\t"
"		lea rsi, [rax+r12+ql.io.is.offset+ql.io.is.offsetStr]\n\t"
"		mov [rax+0x10], rsi\n\t"
"		add rsi, 0x20\n\t"
"		mov [rax+0x08], rsi\n\t"
"		lea rsi, [rax+ql.io.is.offset+ql.io.is.offsetStr]\n\t"
"		mov [rax+ql.io.is.offset], rsi\n\t"
"		mov [rax+ql.io.is.offset+0x08], rsi\n\t"
"		xor esi, esi\n\t"
"		mov [rax+r12+ql.io.is.offset+ql.io.is.offsetStr+ql.io.os.offsetStr], rsi\n\t"
"		xor eax, eax\n\t"
"		call ql.proc.end\n\t"
"		ret\n\t"
"	ql.__dollar__io:\n\t"
"		push QWORD PTR 0\n\t"
"		call ql.proc.begin\n\t"
"		mov rax, 0x0b\n\t"
"		mov rdi, [rip + ql.io.data]\n\t"
"		mov rsi, [rdi]\n\t"
"		sub rsi, rdi\n\t"
"		add rsi, 0x20\n\t"
"		syscall\n\t"
"		call ql.proc.end\n\t"
"		ret\n\t"
"	ql.io.is.load:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		xor eax, eax\n\t"
"		mov rsi, [r10+ql.io.is.offset]\n\t"
"		mov rdx, [r10+0x10]\n\t"
"		xor edi, edi\n\t"
"		sub rdx, rsi\n\t"
"		jle .QL0\n\t"
"		syscall\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		add [r10+ql.io.is.offset], rax\n\t"
"		ret\n\t"
"		.QL0:\n\t"
"		xor rax, rax\n\t"
"		not rax\n\t"
"		ret\n\t"
"	ql.io.is.unload:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		lea rsi, [r10+ql.io.is.offset+ql.io.is.offsetStr]\n\t"
"		mov [r10+ql.io.is.offset], rsi\n\t"
"		mov [r10+ql.io.is.offset+0x08], rsi\n\t"
"		ret\n\t"
"	ql.io.is.read_iu8:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		mov r9, ql.io.isNum\n\t"
"		mov rsi, [r10+ql.io.is.offset+0x08]\n\t"
"		mov r11, [r10+ql.io.is.offset]\n\t"
"		xor eax, eax\n\t"
"		mov r10, 10\n\t"
"		movzx r8, BYTE PTR [rsi]\n\t"
"		xor ecx, ecx\n\t"
"		xor r8, 0x2d\n\t"
"		jnz .QL1\n\t"
"		inc rsi\n\t"
"		not rcx\n\t"
"		.QL1:\n\t"
"			movzx r8, BYTE PTR [rsi]\n\t"
"			cmp rsi, r11\n\t"
"			jge .QL2\n\t"
"			bt r9, r8\n\t"
"			jnc .QL2\n\t"
"			mul r10\n\t"
"			inc rsi\n\t"
"			lea rax, [rax+r8-0x30]\n\t"
"			jmp .QL1\n\t"
"		.QL2:\n\t"
"		jecxz .QL3\n\t"
"			neg rax\n\t"
"		.QL3:\n\t"
"		mov rcx, rdi\n\t"
"		mov r9, ql.io.isWhiteSpace\n\t"
"		jecxz .QL4\n\t"
"			.QL5:\n\t"
"				movzx edx, BYTE PTR [rsi]\n\t"
"				bt r9, rdx\n\t"
"				jnc .QL6\n\t"
"				inc rsi\n\t"
"				jmp .QL5\n\t"
"			.QL6:\n\t"
"		.QL4:\n\t"
"		mov rdi, [rip + ql.io.data]\n\t"
"		mov [rdi+ql.io.is.offset+0x08], rsi\n\t"
"		ret\n\t"
"	ql.io.os.flush:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		mov r11, [r10+0x08]\n\t"
"		mov rax, 0x01\n\t"
"		mov rdi, 1\n\t"
"		lea rsi, [r11+ql.io.os.offsetStr]\n\t"
"		mov rdx, [r11]\n\t"
"		syscall\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		mov r11, [r10+0x08]\n\t"
"		mov QWORD PTR [r11], 0\n\t"
"		ret\n\t"
"	ql.io.os.write_cstr:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		mov rsi, rdi\n\t"
"		mov r10, [r10+0x08]\n\t"
"		mov rdi, [r10]\n\t"
"		mov r8, rsi\n\t"
"		lea rdi, [r10+rdi+ql.io.os.offsetStr]\n\t"
"		.QL7:\n\t"
"			lodsb\n\t"
"			stosb\n\t"
"			test al, 0xff\n\t"
"			jnz .QL7\n\t"
"		sub rsi, r8\n\t"
"		dec rsi\n\t"
"		add [r10], rsi\n\t"
"		ret\n\t"
"	ql.io.os.write_cstr_:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		xor ecx, ecx\n\t"
"		vpxor ymm0, ymm0, ymm0\n\t"
"		mov r8, [r10+0x08]\n\t"
"		mov r9, [r8]\n\t"
"		lea r9, [r8+r9+ql.io.os.offsetStr]\n\t"
"		.QL8:\n\t"
"			vmovdqu ymm3, [rdi+rcx]\n\t"
"			vpcmpeqb ymm1, ymm3, ymm0\n\t"
"			vptest ymm0, ymm1\n\t"
"			jnc .QL9\n\t"
"			vmovdqu [r9+rcx], ymm3\n\t"
"			add rcx, 32\n\t"
"			jmp .QL8\n\t"
"		.QL9:\n\t"
"		lea rsi, [rdi+rcx]\n\t"
"		lea rdi, [r9+rcx]\n\t"
"		.QL10:\n\t"
"			lodsb\n\t"
"			stosb\n\t"
"			test al, 0xff\n\t"
"			jnz .QL10\n\t"
"		mov r10, [r10+0x08]\n\t"
"		lea rsi, [r10+ql.io.os.offsetStr]\n\t"
"		sub rdi, rsi\n\t"
"		mov [r10], rdi\n\t"
"		ret\n\t"
"	ql.io.os.write_cstr_p:\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		xor ecx, ecx\n\t"
"		vpxor ymm0, ymm0, ymm0\n\t"
"		mov r8, [r10+0x08]\n\t"
"		mov r9, [r8]\n\t"
"		lea r9, [r8+r9+ql.io.os.offsetStr]\n\t"
"		.QL11:\n\t"
"			vmovdqu ymm3, [rdi+rcx]\n\t"
"			vmovdqu [r9+rcx], ymm3\n\t"
"			vpcmpeqb ymm1, ymm3, ymm0\n\t"
"			vptest ymm0, ymm1\n\t"
"			jnc .QL12\n\t"
"			add rcx, 32\n\t"
"			jmp .QL11\n\t"
"		.QL12:\n\t"
"		lea rsi, [rdi+rcx-32]\n\t"
"		.QL13:\n\t"
"			lodsb\n\t"
"			test al, 0xff\n\t"
"			jnz .QL13\n\t"
"		mov r10, [r10+0x08]\n\t"
"		sub rsi, rdi\n\t"
"		add [r10], rsi\n\t"
"		ret\n\t"
"	ql.io.os.write_i8:\n\t"
"	ql.io.os.write_u8:\n\t"
"		push rbp\n\t"
"		mov rbp, rsp\n\t"
"		sub rsp, 0x40\n\t"
"		mov rax, rdi\n\t"
"		mov r10, 10\n\t"
"		mov BYTE PTR [rbp-0x1f], 0\n\t"
"		lea rdi, [rbp-0x20]\n\t"
"		lea rsi, [rbp-0x20]\n\t"
"		.QL14:\n\t"
"			xor edx, edx\n\t"
"			div r10\n\t"
"			add edx, 0x30\n\t"
"			mov [rdi], dl\n\t"
"			dec rdi\n\t"
"			test rax, rax\n\t"
"			jnz .QL14\n\t"
"		.QL15:\n\t"
"		sub rsi, rdi\n\t"
"		mov r10, [rip + ql.io.data]\n\t"
"		vmovdqu ymm0, [rdi+1]\n\t"
"		mov r11, [r10+0x08]\n\t"
"		mov r8, [r11]\n\t"
"		vmovdqu [r11+r8+ql.io.os.offsetStr], ymm0\n\t"
"		add [r11], rsi\n\t"
"		add rsp, 0x40\n\t"
"		pop rbp\n\t"
"		ret\n\t"
".att_syntax prefix\n\t"
"nop\n\t"
);

/*
"	main:\n\t"
"		push QWORD PTR 2\n\t"
"		call ql.proc.begin\n\t"
"		mov rdi, 12000000\n\t"
"		mov rsi, 12000000\n\t"
"		call ql.io\n\t"
"		call ql.io.os.flush\n\t"
"		call ql.__dollar__io\n\t"
"		xor eax,eax\n\t"
"		call ql.proc.end\n\t"
"		ret\n\t"
*/

inline void qio_init(){
	asm(
	".intel_syntax noprefix\n\t"
	"	mov rdi, 1000000\n\t"
	"	mov rsi, 1000000\n\t"
	"	call ql.io\n\t"
	".att_syntax prefix\n\t"
	::: "rdi", "rsi"
	);
}

inline void qio_flush(){
	asm volatile(
	"	call ql.io.os.flush\n\t"
	::: "rax", "rdx", "rsi", "rdi", "r10","r11"
	);
}


inline void qio_close(){
	asm(
	"	call ql.__dollar__io\n\t"
	::: "rdi", "rsi"
	);
}

inline void qio_is_load(){
	asm volatile(
	"	call ql.io.is.load\n\t"
	::: "rax", "rdx", "rsi", "rdi", "r10"
	);
}

inline void qio_is_read_iu8(uint64_t& ret){
	asm volatile(
	".intel_syntax noprefix\n\t"
	"	mov dil, 1\n\t"
	"	call ql.io.is.read_iu8\n\t"
	"	mov %0, rax\n\t"
	".att_syntax prefix\n\t"
	: "=r"(ret)
	:: "rax", "rcx", "rdx", "rsi", "rdi", "r8", "r9", "r10","r11"
	);
}

inline void qio_os_write_cstr(const char *str){
	asm(
	".intel_syntax noprefix\n\t"
	"	mov rdi, %0\n\t"
	"	call ql.io.os.write_cstr\n\t"
	".att_syntax prefix\n\t"
	:: "r"(str)
	: "rax", "rsi", "rdi", "r8","r10"
	);
}

inline void qio_os_write_u8(uint64_t x){
	asm(
	".intel_syntax noprefix\n\t"
	"	mov rdi, %0\n\t"
	"	call ql.io.os.write_u8\n\t"
	".att_syntax prefix\n\t"
	:: "r"(x)
	: "rax", "rdx", "rsi", "rdi", "r8", "r10","r11"
	);
}


template<class T, size_t N>
class varray : public array<T, N>{
	size_t n;

public:
	// (constructors)
	constexpr varray()noexcept:array<T, N>{}, n(0){}

	constexpr varray(std::initializer_list<T> init) noexcept
	:array<T, N>{}
	,n(init.size())
	{ std::copy(init.begin(), init.end(), this->begin()); }

	constexpr varray(const varray& other) noexcept
	:array<T, N>{}
	,n(other.n)
	{ std::copy(other.cbegin(), other.cend(), this->begin()); }

	// operator=
	constexpr varray& operator=(initializer_list<T> init) noexcept {
		n = init.size();
		std::copy(init.begin(), init.end(), this->begin());
		return *this;
	}

	constexpr varray& operator=(const varray& other) noexcept {
		n = other.n;
		std::copy(other.cbegin(), other.cend(), this->begin());
		return *this;
	}

public:
	// capacity
	constexpr typename varray::size_type size() const noexcept { return n; }
	constexpr bool empty() const noexcept { return !n; }
	consteval typename varray::size_type capacity() { return N; }

	// element access
	constexpr typename varray::reference back(){ return this->operator[](n-1); }
	constexpr typename varray::const_reference back() const { return this->operator[](n-1); }

	// iterators
	constexpr typename varray::iterator end() noexcept { return this->begin()+n; }
	constexpr typename varray::const_iterator cend() const noexcept { return this->cbegin()+n; }

	constexpr typename varray::reverse_iterator rbegin() noexcept { return this->rend()-n; }
	constexpr typename varray::const_reverse_iterator crbegin() const noexcept { return this->crend()-n; }

	// modifiers
	constexpr void clear() noexcept { n = 0; }
	constexpr void push_back(const T& val) noexcept { this->operator[](n++) = val; }
	constexpr void push_back(T&& val) noexcept { this->operator[](n++) = move(val); }
	constexpr void pop_back() noexcept { --n; }
	constexpr void resize(typename varray::size_type cnt) noexcept { n = cnt; }
	constexpr void swap(varray& other) noexcept {
		array<T, N>::swap(other);
		std::swap(n, other.n);
	}
};

priority_queue<uf8, varray<uf8, 1<<21>, greater<uf8>> pq;

int main(){
	qio_init();
	qio_is_load();

	uf4 T = [](){
		u8 x;
		qio_is_read_iu8(x);
		return x;
	}();

	while(T--){
		uf4 n;
		{
			u8 x;
			qio_is_read_iu8(x);
			n = x;
		}


		while(n--){
			u8 x;
			qio_is_read_iu8(x);

			pq.push(x);
		}

		uf8 r = 0;
		while(pq.size() != 1){
			uf8 a = pq.top(); pq.pop();
			uf8 b = pq.top(); pq.pop();
			uf8 c = a + b;
			pq.push(c);
			r += c;
			DEBUG cout<<"r: "<<r<<'\n';
		}

		qio_os_write_u8(r);
		qio_os_write_cstr("\n");
		pq.pop();
	}

	qio_flush();
	qio_close();
	return 0;
}
//; echo """
