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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

constexpr array<uf8, 8> p10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};
uf8 p10_12 = p10[6] * p10[6];

inline u8 fastdiv10(u8& a){
	constexpr u8 rdx = 0xccccccccccccccdull;
	u8 r_t0;
	asm volatile(
		"mulxq %[t_lo], %[t_lo], %[t_hi]" "\n"
		"shrdq $63, %[t_hi], %[t_lo]"
	:[t_hi]"=r"(r_t0), [t_lo]"+g"(a)
	:"d"(rdx)
	:
	);
	return a;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf8 mn, mx, k, m, s=0;
	cin>>mn>>mx>>k>>m;
	mn = mn < p10[k-1] ? p10[k-1] : mn;
	DEBUG cout<<mn<<' '<<mx<<' '<<k<<' '<<m<<'\n';

	for(uf8 i=p10[k-1]; i<p10[k]; ++i){
		uf8 t;
		for(t=i; t<=mx; t=t*p10[k]+i);

		for(; p10[k-1]<=fastdiv10(t) && mn<=t;)
			if(!(t%m) && t<=mx)
				++s;
	}

	cout<<s;
	return 0;
}

