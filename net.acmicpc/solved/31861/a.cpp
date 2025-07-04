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

	constexpr uf4 M = 1'000'000'007;

	uf2 n, m;
	cin>>n>>m;

	auto a = []() constexpr {
		array<array<uf4, 26>, 2> a;
		for(uf2 i=26; i--;)
			a[0][i] = 1;
		return a;
	}();

	if(n){
		uf4 s = 26, ss;
		for(uf2 i=1; i<m; ++i){
			ss = 0;
			for(uf2 j=n-1; j--;){
				s += M - a[i&1^1][25-j];
				s %= M;
			}

			s += M;

			for(uf2 j=26; j--;){
				if(j-n+1u < 26u) s += M - a[i&1^1][j-n+1u];
				if(j+n < 26u) s += a[i&1^1][j+n];
				if(M <= s) s %= M;
				// DEBUG cout<<"j: "<<j<<" s: "<<s<<endl;
				// DEBUG cout<<j-n+1u<<' '<<j+n<<endl;
				a[i&1][j] = s;
				ss += s;
				if(M <= ss) ss %= M;
			}
			s = ss;
		}
		cout<<s%M;
	}else{
		uf8 r = 1, b=26;
		while(1){
			if(m&1){
				r*=b;
				if(M <= r) r%=M;
			}
			if(m>>=1){
				b*=b;
				if(M <= b) b%=M;
			}
			else break;
		}
		cout<<r;
	}
	return 0;
}
//; echo """
