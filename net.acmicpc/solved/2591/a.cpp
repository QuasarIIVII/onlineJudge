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

	array<uf4, 41> a;

	char s[64];
	cin>>s;

	uf1 n;
	for(uf1 i=0; s[i] || (n=i, 0); ++i);

	for(uf1 i=64; i--;) s[i] -= 0x30;

	DEBUG cout<<"n: "<<(uf2)n<<endl;
	if(n < 2){
		cout<<"1";
		return 0;
	}

	a[0] = 1;
	a[1] = s[0]*10 + s[1] < 35 && s[1] ? 2 : 1;
	DEBUG cout<<(uf2)s[0]<<' '<<(uf2)s[1]<<endl;

	for(uf2 i=2; i<n; ++i){
		a[i] = s[i] ? a[i-1] : 0;
		if(s[i-1] && s[i-1]*10 + s[i] < 35)
			a[i] += a[i-2];
	}

	DEBUG for(uf2 i=0; i<n || (cout<<endl, 0); ++i)
		cout<<a[i]<<' ';

	cout<<a[n-1];
	return 0;
}
//; echo """
