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

	uf2 T;
	cin>>T;

	for(uf2 t=0; t++ < T;){
		uf2 n, m;
		cin>>n>>m;

		array<bitset<10>, 10> a;
		for(uf2 i=n; i--;)for(uf2 j=m; j--;){
			string s;
			s.reserve(16);
			cin>>s;
			s[0]=='1' ? a[i].set(j) : 0;
		}

		array<bitset<10>, 10> b;
		for(uf2 i=n; i--;){
			if(a[i].count() != m) continue;
			for(uf2 j=m; j--;) b[i].set(j);
		}

		for(uf2 j=m; j--;){
			uf2 cnt=0;
			for(uf2 i=n; i--;)
				if(a[i].test(j)) ++cnt;

			if(cnt != n) continue;

			for(uf2 i=n; i--;) b[i].set(j);
		}

		for(uf2 i=n; i--;){
			if(a[i] != b[i]){
				cout<<"Case #"<<t<<": NO\n";
				goto lb0;
			}
		}

		cout<<"Case #"<<t<<": YES\n";
	lb0:
	}
	return 0;
}
//; echo """
