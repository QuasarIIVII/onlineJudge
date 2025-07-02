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

	auto a = [](){
		volatile int z = 0;
		array<pair<uf4, uf4>, 100'001> a;
		a.fill(make_pair(0, 1));
		a[100'000]=make_pair(0, z);
		return a;
	}();

	uf4 N, Q;

	cin>>N>>Q;

	while(Q--){
		uf4 p, q, x, t;
		cin>>p>>q>>x;
		--p, --q;

		if(a[t=p].first){
			do{t+=a[t].second;}while(a[t].first);
			a[p].second = t-p;
		}

		for(uf4 i=t; i<=q; i=t){
			if(!a[i].first) a[i].first = x;
			for(t=i; a[t].first; t+=a[t].second);
			a[i].second = t-i;
		}
	}

	for(uf4 i=0; i<N; ++i)
		cout<<a[i].first<<' ';
	return 0;
}
//; echo """
