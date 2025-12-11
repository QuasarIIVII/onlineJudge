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

	constexpr auto e = [] consteval {
		array<uf8, 12> e;
		e[0] = 1;
		for(uf1 i=1; i<e.size(); ++i)
			e[i] = e[i-1] * 10;
		return e;
	}();

	uf2 n;
	cin>>n;
	auto a = [] consteval {
		struct S{
			uf1 d: 7;
			uf1 f: 1;
		};
		array<pair<uf8, S>, 10> a;
		for(uf1 i=0; i<10; ++i)
			a[i] = {0, {i, 0}};
		return a;
	}();

	for(;n--;){
		string s;
		cin>>s;
		for(uf1 i=s.size(); i--;)
			a[s[i]-0x41].first += e[s.size()-1 - i];
		a[s[0]-0x41].second.f = 1;
	}

	DEBUG for(uf1 i=0; i<10; ++i)
		cout<<char(0x41 + i)<<": "<<a[i].first<<'\n';

	sort(a.rbegin(), a.rend(), [](auto &a, auto &b){
		return a.first < b.first;
	});

	uf8 r=0;
	uf1 c=0;
	{
		uf8 mn = numeric_limits<uf8>::max();
		for(uf1 i=10; i--;){
			if(a[i].second.f || mn <= a[i].first)
				continue;
			mn = a[i].first;
			c = i;
		}
	}

	for(uf1 i=10, d=1; i--;){
		uf1 v = i==c ? 0 : d++;
		DEBUG cout<<a[i].first<<" * "<<uf2(v)<<'\n';
		r += a[i].first * v;
	}
	cout<<r;
	return 0;
}
AFESDJPOI
;
