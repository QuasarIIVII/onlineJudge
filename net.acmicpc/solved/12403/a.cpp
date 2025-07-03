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

	auto a = []() constexpr {
		array<vector<uf2>, 10001> a;
		for(auto& v : a)
			v.reserve(5);
		return a;
	}();

	for(uf2 i=12; i<100; ++i){
		const uf2 j = i%10*10 + i/10;
		if(j <= i) continue;
		a[i].push_back(j);
		DEBUG cout<<i<<" -> "<<j<<"\n";
	}

	for(uf2 i=100; i<1000; ++i){
		uf2 j = i;
		while(1){
			j = j%10*100 + j/10;
			if(i == j) break;
			if(j <= i) continue;
			a[i].push_back(j);
		}
		sort(a[i].begin(), a[i].end());
	}

	for(uf2 i=1000; i<10000; ++i){
		uf2 j = i;
		while(1){
			j = j%10*1000 + j/10;
			if(i == j) break;
			if(j <= i) continue;
			a[i].push_back(j);
		}
		sort(a[i].begin(), a[i].end());
	}

	uf2 T;
	cin>>T;

	for(uf2 t=1; t<=T; ++t){
		uf2 p, q;
		cin>>p>>q;

		uf2 r = 0;
		for(uf2 i=p; i<=q; ++i){
			if(a[i].empty()) continue;
			const auto& it = upper_bound(a[i].begin(), a[i].end(), q);
			r += distance(a[i].begin(), it);
		}
		cout<<"Case #"<<t<<": "<<r<<'\n';
	}

	return 0;
}
//; echo """
