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

	u8 n;
	cin>>n;
	cin.ignore();
	u4 x;
	cin>>x;

	if(x!=5 && x!=0){
		cout<<"-1";
		return 0;
	}

	n = n*2 + (x?1:0);

	const u8 rr = (n+17) / 18;
	const u8 r = rr<=8 ? 0 : rr-8;
	const u8 e = n - r*18;

	array<u4, 9*7*2+18*2> d;
	memset(d.data(), 0xff, sizeof(d));
	d[0] = 0;

	u4 p=0, q=0;
	array<u4, 1024> Q;
	Q[q++] = 0;

	while(p!=q){
		const u4 v = Q[p];
		++p &= 0x3ff;

		if(v==e)
			return cout<<r+d[e], 0;

		const array<u4, 4> nxts
		= { v+18u, v+14u, v+9u, v-4u };
		for(const u4 nxt : nxts){
			if(d.size()<=nxt || d[nxt]!=-1u)
				continue;

			d[Q[q] = nxt] = d[v]+1;
			++q &= 0x3ff;
		}
	}
	return 0;
}
AFESDJPOI
;
