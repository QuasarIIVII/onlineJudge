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

	constexpr auto m = [] consteval {
		array<uf4, 128> m;
		for(uf4 i=10; i--;) m[i+0x30] = i;
		for(uf4 i=26; i--;) m[i+0x41] = m[i+0x61] = i+10;
		return m;
	}();

	uf4 T;
	cin>>T;
	for(uf4 t=1; t<=T; ++t){
		uf4 b;
		string s0, s1;
		cin>>b>>s0>>s1;

		array<uf1, 17> a0;
		for(uf4 i=s0.size(); i--;)
			a0[i] = m[s0[s0.size()-1-i]];

		uf4 n1 = 0;
		for(const char c : s1)
			n1 = n1*b + m[c];

		uf4 n0 = 0;

		for(uf4 i=s0.size(); i--;)
			n0 = (n0*b + a0[i]) % n1;

		DEBUG cout<<"n0: "<<n0<<'\n';

		array<uf4, 100'001> v{0, };
		for(uf4 c = 1;;++c){
			if(v[n0]){
				cout<<"Scenario #"<<t<<":\n"<<c-v[n0]<<"\n\n";
				break;
			}
			if(!n0){
				cout<<"Scenario #"<<t<<":\n0\n\n";
				break;
			}

			v[n0] = c;
			n0 = n0*b % n1;
		}
	}
	return 0;
}
//; echo """
