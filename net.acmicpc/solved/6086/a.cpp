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

	uf2 n;
	cin>>n;

	array<array<if4, 52>, 52> a{};
	constexpr auto m = [] consteval {
		array<uf1, 0x61+26> m;
		for(uf1 i=0x41; i<=0x5A; ++i) m[i] = i - 0x41;
		for(uf1 i=0x61; i<=0x7A; ++i) m[i] = i - 0x61 + 26;
		return m;
	}();

	while(n--){
		char c0, c1;
		uf4 w;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin>>c0;
		cin.ignore(numeric_limits<streamsize>::max(), ' ');
		cin>>c1>>w;

		DEBUG cout<<c0<<' '<<c1<<' '<<w<<'\n';
		uf1 i0 = m[c0], i1 = m[c1];
		a[i0][i1] += w;
		a[i1][i0] += w;
	}

	function<bool(uf1, uf1, array<uf1, 52>&, bitset<52>&)> f
	= [&a, &f](uf1 s, uf1 e, array<uf1, 52> &p, bitset<52> &v){
		v.set(s);

		for(uf1 i=52; i--;){
			if(a[s][i]<=0 || v.test(i)) continue;
			p[i] = s;
			if(i==e || f(i, e, p, v)) return true;
		}

		return false;
	};

	uf4 mx = 0;
	bitset<52> v;
	for(array<uf1, 52> p; f(0, 25, p, v); v.reset()){
		if4 w = numeric_limits<if4>::max();
		for(uf1 i=25; i; i=p[i])
			w = min(w, a[p[i]][i]);

		for(uf1 i=25; i; i=p[i]){
			a[p[i]][i] -= w;
			a[i][p[i]] += w;
		}

		mx += w;
	}

	cout<<mx;

	return 0;
}
AFESDJPOI
;
