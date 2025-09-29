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

	array<uf1, 6> a;

	a.fill(0);
	for(uf1 i=4; i--;){
		array<uf2, 6> b;
		cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
		for(uf1 j=6; j--;)
			a[j] = a[j]<<1 | b[j];
	}

	uf4 p = (a[0]*10 + a[1])*3600 + (a[2]*10 + a[3])*60 + (a[4]*10 + a[5]);

	a.fill(0);
	for(uf1 i=4; i--;){
		array<uf2, 6> b;
		cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
		for(uf1 j=6; j--;)
			a[j] = a[j]<<1 | b[j];
	}

	p += (a[0]*10 + a[1])*3600 + (a[2]*10 + a[3])*60 + (a[4]*10 + a[5]);

	uf4 q = p%60;
	p /= 60;
	a[0] = q%10, a[1] = q/10;

	q = p%60;
	p /= 60;
	a[2] = q%10, a[3] = q/10;

	q = p%24;
	a[4] = q%10, a[5] = q/10;

	for(uf1 i=4; i--;){
		for(uf1 j=6; j--;)
			cout<<(a[j]>>i&1)<<' ';
		cout<<'\n';
	}

	return 0;
}
//; echo """
