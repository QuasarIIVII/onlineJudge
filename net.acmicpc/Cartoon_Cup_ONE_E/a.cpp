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

	uf4 n, m;
	string s0, s1;

	cin>>n>>s1>>s0;

	bool f = true;
	for(uf4 i = 0, e = max(s0.size(), s1.size()); i < e; ++i){
		const uf4 d0 = e - s0.size();
		const uf4 d1 = e - s1.size();
		const char c0 = i < d0 ? 0x30 : s0[i - d0];
		const char c1 = i < d1 ? 0x30 : (s1[i - d1] = s1[i - d1] == '?' ? 0x39 : s1[i - d1]);
		DEBUG cout<<"c0: "<<c0<<", c1: "<<c1<<"\n";

		if(f && c1 < c0){
			cout<<"-1";
			return 0;
		}
		if(c1 > c0) f = false;
	}

	cout<<s1;

	return 0;
}
AFESDJPOI
;
