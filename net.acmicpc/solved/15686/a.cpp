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

	u4 N, M;
	cin>>N>>M;

	array<array<u1, 2>, 100> a{};
	array<array<u1, 2>, 13> b{};
	u4 ch = 0, cc = 0;

	for(u4 r=0; r<N; ++r){
		for(u4 c=0, x; c<N; ++c){
			cin>>x;
			if(x&1)
				a[ch++] = {static_cast<u1>(r), static_cast<u1>(c)};
			else if(x&2)
				b[cc++] = {static_cast<u1>(r), static_cast<u1>(c)};
		}
	}

	constexpr auto diff = [](const u1 a, const u1 b)
	{ return a < b ? b - a : a - b; };

	array<array<u1, 13>, 100> dist{};
	for(u4 i=0; i<ch; ++i){
		for(u4 j=0; j<cc; ++j){
			dist[i][j] =
				diff(a[i][0], b[j][0]) +
				diff(a[i][1], b[j][1]);
		}
	}

	u4 r = -1u;
	const u4 x = 1u << cc;
	for(u4 m=0; m<x; ++m){
		if(static_cast<u4>(popcount(m)) != M) continue;

		u4 d = 0;
		for(u4 i=0; i<ch; ++i){
			u4 rr = -1u;
			for(u4 j=0; j<cc; ++j){
				if(m & (1u << j))
					rr = min<u4>(rr, dist[i][j]);
			}

			d += rr;
			if(r <= d) break;
		}

		r = min(r, d);
	}

	cout<<r;
	return 0;
}
AFESDJPOI
;
