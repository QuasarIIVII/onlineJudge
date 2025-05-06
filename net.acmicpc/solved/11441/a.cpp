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

i4 f(array<i4, 1<<18>& a, const uf4 idx){
	if(a[idx] != 0x7f7f7f7f) return a[idx];
	uf4 i = idx*2;
	return a[idx] = f(a, i) + f(a, i+1);
}

i4 g(const array<i4, 1<<18>& a, const uf4 p, const uf4 q, uf4 idx, uf4 s, uf4 sz){
	if(p <= s && s+sz <= q) return a[idx];
	if(q  <= s || s+sz <= p) return 0;
	uf4 i = idx*2;
	sz /= 2;
	return g(a, p, q, i, s, sz) + g(a, p, q, i+1, s+sz, sz);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<i4, 1<<18> a{0, };
	memset(a.data(), 0x7f, 4<<17);

	uf4 n;
	cin>>n;
	for(uf4 i=0; i<n; ++i)
		cin>>a[i+(1<<17)];

	f(a, 1);

	cin>>n;
	while(n--){
		uf4 p, q;
		cin>>p>>q;
		cout<<g(a, p-1, q, 1, 0, 1<<17)<<'\n';
	}
	return 0;
}
//; echo """
