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
#include<optional>

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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

bool f(array<uf4, 0x80>& a, array<uf4, 0x80>& b){
	for(uf1 i=0x61; i<0x61+26; ++i)
		if(a[i] != b[i])
			return false;

	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 T;
	cin>>T;
	while(T--){
		string s0,s1;
		cin>>s0>>s1;

		array<uf4, 0x80> s0c{0, }, s1c{0, };
		for(uf4 i=s1.size(); i--;){
			++s1c[s1[i]];
			++s0c[s0[i]];
		}

		if(f(s0c, s1c)){
			cout<<"YES\n";
			continue;
		}

		uf4 ie = s0.size()-s1.size();
		for(uf4 i=0; i<ie; ++i){
			--s0c[s0[i]];
			++s0c[s0[i+s1.size()]];

			if(f(s0c, s1c)){
				cout<<"YES\n";
				goto l0e;
			}
		}

		cout<<"NO\n";
		l0e:
		;
	}

	return 0;
}
//; echo """
