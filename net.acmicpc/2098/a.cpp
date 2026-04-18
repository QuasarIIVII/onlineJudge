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

	auto a = []() consteval {
		struct S{u4 x, s;};
		array<array<S, 65536>, 16> a;
		decltype(a)::value_type aa;
		aa.fill({numeric_limits<u4>::max(), 0});
		a.fill(aa);
		for(u4 i=16; i--;) a[i][1u<<i] = {0, i};
		return a;
	}();

	array<array<u4, 16>, 16> d;
	u2 n;
	cin>>n;

	for(u4 i=0; i<n; ++i)for(u4 j=0; j<n; ++j)
		cin>>d[i][j];

	const u2 n1 = (1u<<n)-1;
	struct S{u2 a, b;};
	u4 qp = 0, qq = 0;
	array<S, 0x4'0000> Q;
	for(u2 i=n; i--;) Q[qq++] = {i, 1u<<i};

	while(qq!=qp){
		const auto [i, p] = Q[qp];
		++qp &= 0x3'ffff;
		const u8 w = a[i][p].x;
		const u4 as = a[i][p].s;

		if(p == n1){
			const u8 nw = w + d[i][as];
			auto &aw = a[as][0];

			if(!d[i][as]) continue;
			if(nw < aw.x){
				DEBUG cout<<i<<' '<<bitset<8>(p)<<' '<<as<<' '<<bitset<8>(0)<<' '<<aw.x<<' '<<nw<<endl;
				aw = {nw, as};
			}
			continue;
		}

		for(u2 j=n; j--;){
			const u2 q = p|(1u<<j);
			if(p==q || !d[i][j]) continue;
			const u8 nw = w + d[i][j];
			auto &aw = a[j][q];
			if(nw < aw.x){
				DEBUG cout<<i<<' '<<bitset<8>(p)<<' '<<j<<' '<<bitset<8>(q)<<' '<<aw.x<<' '<<nw<<endl;
				aw = {nw, as};
				Q[qq] = {j, q};
				++qq &= 0x3'ffff;
			}
		}
	}

	u4 r = numeric_limits<u4>::max();
	for(u2 i=n; i--;) r = min(r, a[i][0].x);

	cout<<r;

	return 0;
}
AFESDJPOI
;
