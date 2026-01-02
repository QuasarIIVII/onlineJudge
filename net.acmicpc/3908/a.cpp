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

	constexpr auto p = [] consteval {
		bitset<1121> b;
		b.set(0), b.set(1);

		uf4 c = 0;
		for(uf4 i=2; i<b.size(); ++i){
			if(b.test(i)) continue;
			++c;
			for(uf4 j=i*2; j<b.size(); j+=i)
				b.set(j);
		}

		array<uf4, 187> p;
		for(uf4 i=0, j=0; i<b.size(); ++i)
			if(!b.test(i)) p[j++] = i;
		return p;
	}();

	DEBUG for(const auto &e : p)
		cout<<e<<' ';


	uf4 T;
	cin>>T;
	while(T--){
		uf4 n, k;
		cin>>n>>k;
	}
	return 0;
}
AFESDJPOI
;
