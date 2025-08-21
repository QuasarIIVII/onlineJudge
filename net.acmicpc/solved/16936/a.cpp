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

	uf2 n;
	unordered_set<uf8> s;
	unordered_map<uf8, pair<uf8, uf8>> m;

	cin>>n;
	s.reserve(n);
	m.reserve(n);

	for(uf2 i=n; i--;){
		uf8 x;
		cin>>x;
		s.emplace(x);
		m.emplace(x, make_pair(0, 0));
	}

	for(const auto& a : s){
		{
			if(a%3) goto lb0;
			uf8 b = a/3;
			if(!s.contains(b)) goto lb0;

			m[a].first = b;
		}
	lb0:
		{
			uf8 b = a*2;
			if(!s.contains(b)) continue;

			m[a].second = b;
		}
	}

	array<uf8, 100> r;

	const function<bool(uf8, uf2)> f = [&](uf8 x, uf2 cnt) -> bool {
		if(!cnt){
			r[cnt] = x;
			return true;
		}

		if(m[x].first && f(m[x].first, cnt-1)){
			r[cnt] = x;
			return true;
		}

		if(m[x].second && f(m[x].second, cnt-1)){
			r[cnt] = x;
			return true;
		}

		return false;
	};

	for(const auto& a : s){
		if(f(a, n-1))
			break;
	}

	for(uf2 i=n; i--;)
		cout<<r[i]<<" ";

	return 0;
}
//; echo """
