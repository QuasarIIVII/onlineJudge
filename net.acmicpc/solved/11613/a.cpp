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

	constexpr array<string_view, 7> a{
		"xxxxx....xxxxxxxxxxxx...xxxxxxxxxxxxxxxxxxxxxxxxxx.....",
		"x...x....x....x....xx...xx....x........xx...xx...x..x..",
		"x...x....x....x....xx...xx....x........xx...xx...x..x..",
		"x...x....xxxxxxxxxxxxxxxxxxxxxxxxxx....xxxxxxxxxxxxxxxx",
		"x...x....xx........x....x....xx...x....xx...x....x..x..",
		"x...x....xx........x....x....xx...x....xx...x....x..x..",
		"xxxxx....xxxxxxxxxxx....xxxxxxxxxxx....xxxxxxxxxxx....."
	};

	array<string, 7> b;
	for(uf1 i=0; i<7; ++i) cin>>b[i];

	uf4 n = 0, m = 0;

	for(uf1 i=0; i<b[0].size(); i+=6){
		array<string_view, 7> c;
		for(uf1 j=0; j<7; ++j)
			c[j] = string_view(b[j].begin()+i, b[j].begin()+i+5);

		for(uf1 j=0; j<11; ++j){
			uf1 k;
			for(k=0; k<7; ++k)
				if(c[k] != a[k].substr(j*5, 5)) break;

			if(k==7){
				if(j==10) swap(n, m);
				else n = n*10 + j;
				break;
			}
		}
	}

	uf1 p = 0;
	array<uf1, 11> d;
	for(n+=m; n; n/=10) d[p++] = n%10;

	for(uf1 i=0; i<7; ++i)
		for(uf1 j=p; j--;)
			cout<<a[i].substr(d[j]*5, 5)<<(j?'.':'\n');

	return 0;
}
//; echo """
