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

	array<uf8, 51> a{0, };
	array<uf8, 51> b{0, };
	a[0] = 1;
	b[0] = 1;

	uf2 n;
	uf8 x;
	cin>>n>>x;
	--x;

	const function<uf8(uf2, uf8)> f = [&](uf2 lv, uf8 h){
		DEBUG cout<<lv<<' '<<h<<endl;
		if(a[lv])
			return h+b[lv] < x ? a[lv] : 0;

		uf8 r = 0;
		r += f(lv-1, h+1);
		if(h + 1 + b[lv-1] < x) ++r;
		r += f(lv-1, h+2+b[lv-1]);
		b[lv] = b[lv-1]*2 + 3;
		return a[lv] = r;
	};

	cout<<f(n, 0);
	return 0;
}
//; echo """
