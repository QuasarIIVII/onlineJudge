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
#include<stdfloat>
#include<cmath>
#include<cstring>
//; echo """

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
	constexpr pair<i2, i2> z{0, 0};

	uf2 n;
	pair<i2, i2> p;
	cin>>n>>p.first>>p.second;

	array<tuple<pair<i2, i2>, i2, u2>, 1050> a;
	queue<tuple<uf2, u2, f8>> q;

	for(uf2 i=n; i--;){
		auto &aa = a[i];
		cin>>get<0>(aa).first>>get<0>(aa).second>>get<1>(aa);
		get<2>(aa) = a.size();
		if(get<0>(aa) == z) q.emplace(i, i, 10'000);
	}

	constexpr auto f = [](const pair<i2, i2> &a, const pair<i2, i2> &b){
		const if4 dx = a.first - b.first, dy = a.second - b.second;
		return dx*dx + dy*dy;
	};

	array<f8, 1050> b;
	for(; q.size(); q.pop()){
		const auto &[i, I, r] = q.front();
		auto &[ap, ar, v] = a[i];
		if(v != a.size()) continue;

		v = I;
		const f8 spd = r;
		b[i] = spd;

		if(ap == p) break;

		DEBUG cout<<ap.first<<' '<<ap.second<<' '<<ar<<' '<<spd<<endl;

		for(uf2 j=n; j--;){
			auto &[bp, br, vv] = a[j];
			if(vv != a.size()) continue;

			if(if4 d = ar+br; f(ap, bp) != d*d) continue;
			DEBUG cout<<"> "<<bp.first<<' '<<bp.second<<' '<<br<<endl;
			q.emplace(j, i, spd*ar/br);
		}
	}

	f8 r = 0;
	for(uf2 i=get<0>(q.front()); ; i = get<2>(a[i])){
		r += b[i];
		if(i == get<2>(a[i])) break;
	}

	cout<<static_cast<uf8>(r);

	return 0;
}
//; echo """
