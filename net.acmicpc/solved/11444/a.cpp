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

	constexpr auto f = [](const array<uf8, 4> a, const array<uf8, 4> b) constexpr {
		array<uf8, 4> r{
			a[0]*b[0] + a[1]*b[2], a[0]*b[1] + a[1]*b[3],
			a[2]*b[0] + a[3]*b[2], a[2]*b[1] + a[3]*b[3]
		};
		for(auto& e : r) e %= 1'000'000'007;
		return r;
	};

	constexpr auto a = [&] consteval {
		array<array<uf8, 4>, 64> a;
		a[0] = {1, 1, 1, 0};
		for(uf4 i=1; i<a.size(); ++i)
			a[i] = f(a[i-1], a[i-1]);
		return a;
	}();

	array<uf8, 4> r{1, 0, 0, 1};

	uf8 n;
	cin>>n;

	for(uf4 i=0; n; ++i, n>>=1)
		if(n&1) r = f(r, a[i]);

	cout<<r[1];
	return 0;
}
//; echo """
