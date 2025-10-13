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

constexpr inline bool f(const uf8 n){
	constexpr array<uf8, 4> a{2, 3, 7, 61};
	const uf8 nn = n-1;
	uf8 d = nn, s = 0;
	for(; !(d&1); ++s, d>>=1);

	for(const uf8 aa : a){
		if(n-2 < aa) break;

		uf8 x = 1;
		for(uf8 y = d, b = aa; y; (b*=b)%=n, y>>=1)
			if(y&1) (x*=b)%=n;

		for(uf8 ss = s; ss--;){
			uf8 y = x*x%n;
			if(y==1 && x!=1 && x!=nn)
				return false;

			x = y;
		}

		if(x != 1) return false;
	}

	return true;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	auto [a, ap] = [] consteval {
		uf8 p = 0;
		array<uf8, 1000> a;

		for(uf8 i=1; i<10; ++i){
			if(i != 1 && f(i)) a[p++] = i;

			uf8 j = i*10 + i;
			if(f(j)) a[p++] = j;
		}

		for(uf8 i=1, j; i<100; ++i){
			if(!(j = i%10)) continue;
			j = j*10 + i/10%10;
			j = j*100 + i;
			if(f(j)) a[p++] = j;

			j = i%10;
			j = j*100 + i;
			if(f(j)) a[p++] = j;
		}

		for(uf8 i=1, j, k; i<1000; ++i){
			k = i/10;
			if(!(j = i%10)) continue;
			j = j*10 + k%10, k/=10;
			j = j*10 + k;
			j = j*1000 + i;
			if(f(j)) a[p++] = j;

			j = i%10;
			j = j*10 + i/10%10;
			j = j*1000 + i;
			if(f(j)) a[p++] = j;
		}

		for(uf8 i=1, j, k; i<10'000; ++i){
			k = i/10;
			if(!(j = i%10)) continue;
			j = j*10 + k%10, k/=10;
			j = j*10 + k%10, k/=10;
			j = j*10 + k;
			j = j*10'000 + i;
			if(f(j)) a[p++] = j;

			k = i/10;
			j = i%10;
			j = j*10 + k%10, k/=10;
			j = j*10 + k%10;
			j = j*10'000 + i;
			if(f(j)) a[p++] = j;
		}

		sort(a.begin(), a.begin()+p);
		return make_pair(a, p);
	}();

	uf8 p, q;
	cin>>p>>q;
	const auto e = a.begin() + ap;
	for(auto i = lower_bound(a.begin(), e, p); i!=e && *i<=q || (cout<<"-1", 0);)
		cout<<*i++<<'\n';
	return 0;
}
//; echo """
