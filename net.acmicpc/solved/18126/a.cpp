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

	u2 n;
	cin>>n;

	array<vector<pair<u2, u4>>, 5000> e;
	for(u2 i=n; --i;){
		u2 u, v;
		u4 w;
		cin>>u>>v>>w;
		--u, --v;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	array<u8, 5000> d;
	memset(d.data(), 0xff, sizeof(d));

	u2 sp = 0;
	array<u2, 8192> st;
	st[sp++] = 0;
	d[0] = 0;

	u8 r = 0;
	while(sp){
		const u2 u = st[--sp];
		r = max(r, d[u]);
		for(const auto &[v, w] : e[u]){
			if(d[v] != numeric_limits<u8>::max()) continue;
			d[v] = d[u] + w;
			st[sp++] = v;
		}
	}

	cout<<r;

	return 0;
}
AFESDJPOI
;
