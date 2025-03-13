#include<cstdio>

int a[4] = {1,1,2,3};
char b[5];

int scanInt(){
	long long rax;
	asm(
	"xor %%eax, %%eax\n"
	"xor %%edi, %%edi\n"
	"mov $4, %%edx\n"
	"syscall\n"
	"mov %%rax, %0\n"
	: "=r"(rax)
	: "S"(b)
	: "rax", "rcx", "rdi", "rdx", "r8", "r9", "r10", "r11", "memory"
	);

	printf("%lld\n",rax);

	[[assume(0<=rax && rax<5)]];
	switch(rax){
	case 0: return 0;
	case 1: return b[0] - 0x30;
	case 2: return (b[0] - 0x30) * 10 + b[1] - 0x30;
	case 3: return (b[0] - 0x30) * 100 + (b[1] - 0x30) * 10 + b[2] - 0x30;
	case 4: return (b[0] - 0x30) * 1000 + (b[1] - 0x30) * 100 + (b[2] - 0x30) * 10 + b[3] - 0x30;
	default: return 0;
	}
}

void printInt(int n){
	/*
	if(n>9999){
	}else if(n>999){
	}else if(n>99){
	}else if(n>9){
	}else{
		asm(
		"mov r8d, 10"
		"xor ecx, ecx\n"

		"xor edx, edx\n"
		"div r8\n"
		"lea rsi, [rdx + 0x30]\n"
		"mov [rdi], sil\n"
		:
		:"a"(n), "D"(b)
		);
	}

	asm(
	"mov eax, 1\n"
	"lea rdx, [rdi + 1]\n"
	"mov edi, 1\n"
	"sub rdx, rsi\n"
	"syscall\n"
	:
	:"S"(b)
	);
	*/
}

int main(){
	scanInt();
//	int n = scanInt();
//	for(int i=4;i<=n;++i)
//		a[i&3] = ( a[i-1&3] + a[i-2&3] ) % 10007;
//	printf("%d",a[n&3]);
}
