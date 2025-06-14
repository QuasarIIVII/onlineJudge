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

	uf4 n, m;
	auto a = []() constexpr {
		array<bitset<2000>, 2000> a;
		for(uf2 i=a.size(); i--;)
			a[i].set(i);
		return a;
	}();

	cin>>n>>m;

	for(uf4 i=m; i--;){
		uf4 u, v;
		cin>>u>>v;
		--u, --v;
		a[u].set(v);
		a[v].set(u);
	}

	const auto b = []() constexpr {
		bitset<2000> b;
		uf4 n;
		cin>>n;
		while(n--){
			uf4 x;
			cin>>x;
			b.set(x-1);
		}
		return b;
	}();

	bitset<2000> r;

	uf4 c = 0;
	ostringstream oss;

	for(uf4 i=n; i--;){
		if((a[i] | b) != b) continue;
		r |= a[i];
		++c;
		oss<<i+1<<' ';
	}

	r == b
	? cout<<c<<'\n'<<oss.str()
	: cout<<"-1";

	return 0;
}
//; echo """
