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
	u4 k, r = 0;
	cin>>n>>k;
	array<u4, 100'001> a{};

	set<u4> b;
	b.emplace(0);

	while(n--){
		u4 w; u2 v;
		cin>>w>>v;

		DEBUG cout<<"w="<<w<<" v="<<v<<endl;

		u4 p = 0;
		array<u4, 100'000> bb;

		for(auto it = b.rbegin(); it != b.rend(); ++it){
			const u4 &cw = *it;
			if(k < cw+w) continue;
			const u4 tw = cw + w;

			DEBUG cout<<"*it="<<*it;

			if(!a[tw]) bb[p++] = tw;
			a[tw] = max(a[tw], a[cw] + v);
			r = max(r, a[tw]);
			DEBUG cout<<" a[tw="<<tw<<"]="<<a[tw]<<endl;
		}

		while(p--) b.emplace(bb[p]);
	}

	cout<<r;
	return 0;
}
AFESDJPOI
;
