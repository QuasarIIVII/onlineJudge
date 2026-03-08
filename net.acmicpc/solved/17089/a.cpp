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

	u4 n, m;
	cin>>n>>m;

	array<u2, 4000> ne{};
	array<array<u8, 64>, 4000> e{};

	for(u4 i=m; i--;){
		u4 p, q;
		cin>>p>>q;
		--p, --q;
		e[p][q>>6] |= u8(1)<<(q&63);
		e[q][p>>6] |= u8(1)<<(p&63);
		++ne[p], ++ne[q];
	}

	u4 r = numeric_limits<u4>::max();
	for(u4 i=n; i--;){
		if(ne[i]<2) continue;
		for(u4 j=i; j--;){
			if(ne[j]<2) continue;
			if(!(e[i][j>>6]>>(j&63) & 1)) continue;
			for(u4 k=63; k--;){
				u8 t = e[i][k] & e[j][k];
				for(u4 l=0, tt; (l+=(tt=countr_zero(t)))<64; ++l, t>>=(tt+1)){
					DEBUG cout<<i<<' '<<j<<' '<<(k<<6|l)<<' ';
					DEBUG cout<<ne[i]+ne[j]+ne[k<<6|l]-6u<<endl;
					r = min(r, ne[i]+ne[j]+ne[k<<6|l]-6u);
				}
			}
		}
	}

	cout<<static_cast<i4>(r);

	return 0;
}
AFESDJPOI
;
