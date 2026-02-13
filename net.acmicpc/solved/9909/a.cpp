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
#include<stdfloat>
#include<cmath>
#include<cstring>
#define AFESDJPOI asm("")
//$(pwd); cat <<AFESDJPOI

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
										using f4=float32_t;	using f8=float64_t;	using f16=float128_t;
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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	u2 n, m;
	cin>>n>>m;

	array<u4, 32>  a{}, b{};
	for(u2 i=n+1; --i;){
		char s[32];
		cin>>s;
		for(u2 j=n; j--;)
			a[i] = (a[i]<<1) + s[j]-0x30;
		a[i] <<= 1;
	}

	for(u2 i=n+1; --i;){
		char s[32];
		cin>>s;
		for(u2 j=n; j--;)
			b[i] = (b[i]<<1) + s[j]-0x30;
		b[i] <<= 1;
	}

	DEBUG{
		for(u2 i=n+1; --i;)
			cout<<bitset<32>(a[i])<<'\n';
		cout<<'\n';
		for(u2 i=n+1; --i;)
			cout<<bitset<32>(b[i])<<'\n';
	}

	u1 r = 0;
	for(u1 i=63; i--;){
		array<array<u4, 32>, 2> aa = {a, a};
		for(u1 j=m; j--;){
			const auto &c = aa[j&1];
			auto &nx = aa[j&1^1];
			for(u1 p=n+1; nx[--p]=0, p;)for(u1 q=n; q--;){
				const u4 cnt = popcount(c[p]>>q&7) + (c[p-1]>>q+1&1) + (c[p+1]>>q+1&1);
				nx[p] |= (i>>cnt&1u)<<q+1;
			}
			DEBUG{
				cout<<"rule "<<+i<<" step "<<+j<<'\n';
				for(u2 k=n+1; --k;)
					cout<<bitset<32>(nx[k])<<'\n';
			}
		}
		if(aa[1] == b) r = i;
	}
	cout<<+r;

	return 0;
}
AFESDJPOI
;
