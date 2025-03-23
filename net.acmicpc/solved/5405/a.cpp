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

using p2=array<uf4, 2>;
struct S{
	p2 p;
	uf2 ro;
};
constexpr array<array<S, 4>, 4> dd = {
	array<S, 4>{S{.p={0,0}, .ro=3}, S{.p={0,1}, .ro=0}, S{.p={1,1}, .ro=0}, S{.p={1,0}, .ro=1}}, // U
	array<S, 4>{S{.p={1,1}, .ro=2}, S{.p={0,1}, .ro=1}, S{.p={0,0}, .ro=1}, S{.p={1,0}, .ro=0}}, // R
	array<S, 4>{S{.p={1,1}, .ro=1}, S{.p={1,0}, .ro=2}, S{.p={0,0}, .ro=2}, S{.p={0,1}, .ro=3}}, // D
	array<S, 4>{S{.p={0,0}, .ro=0}, S{.p={1,0}, .ro=3}, S{.p={1,1}, .ro=3}, S{.p={0,1}, .ro=2}}  // L
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 N;
	for(cin>>N; N--; ){
		p2 p = {0, 0}, q = {0, 0};
		uf4 n, rp, rq;
		uf2 rop = 3, roq = 3;

		cin>>n>>rp>>rq;
		--rp, --rq;
		for(uf4 i=n; i--; ){
			p[0]<<=1, p[1]<<=1;
			q[0]<<=1, q[1]<<=1;
			auto t = rp >> i*2 & 0x3;

			p[0] |= dd[rop][t].p[0];
			p[1] |= dd[rop][t].p[1];
			rop = dd[rop][t].ro;

			t = rq >> i*2 & 0x3;
			q[0] |= dd[roq][t].p[0];
			q[1] |= dd[roq][t].p[1];
			roq = dd[roq][t].ro;
		}

		DEBUG cout<<p[0]<<' '<<p[1]<<endl;
		DEBUG cout<<q[0]<<' '<<q[1]<<endl;

		auto tx = static_cast<uf8>(p[0])-q[0];
		tx*=tx;
		auto ty = static_cast<uf8>(p[1])-q[1];
		ty*=ty;
		cout<<llroundl(sqrtl((tx+ty)*100))<<'\n';
	}
	return 0;
}

