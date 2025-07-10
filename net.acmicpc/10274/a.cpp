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
//; echo """

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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf1 T = [](){
		uf2 x;
		cin>>x;
		return x;
	}();

	while(T--){
		uf4 n;
		cin>>n;
		const auto a = [n](){
			array<if2, 1'000'000> a;
			for(uf4 i=n; i--;)
				cin>>a[i];
			return a;
		}();

		if4 m;
		vector<pair<if4, uf4>> d(1'000'000, {numeric_limits<if4>::min(), 0});

		d[0] = {a[0], 0};
		m = max(d[0].first, 0);

		for(uf4 i=1; i<n; ++i){
			d[i] = 0 < d[i-1].first
			? make_pair<if2>(d[i-1].first + a[i], d[i-1].second)
			: make_pair(a[i], i);
			m = max(d[i].first, m);
		}

		if(d[n-1].second != 0){
			const if4 dp = d[n-1].first + a[0], dq = d[0].first;
			if(dp < dq) goto lb0;
			else if(dp != dq)
				d[0] = {dp, d[n-1].second};
			else{
				if(d[n-1].second < d[0].second)
					d[0] = {dp, d[n-1].second};
			}
			m = max(d[0].first, m);
		}

	lb0:
		for(uf4 i=1; i<n; ++i){
			if(d[i-1].second <= i) continue;

			const if4 dp = d[i-1].first + a[i], dq = d[i].first;
			if(dp < dq) continue;
			else if(dp != dq)
				d[i] = {dp, d[i-1].second};
			else if(d[i-1].second < d[i].second)
				d[0] = {dp, d[i-1].second};
			m = max(d[i].first, m);
		}
		cout<<m<<'\n';
	}
	return 0;
}
//; echo """
