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

array<array<u4,1001>,1003> a = []() {
	array<array<u4,1001>,1003> a = {0,};
	a[0][0]=1;

	volatile u4 x=0;
	x = a[0][0];
	a[0][0] = x;

	for(uf2 i=0;i<1000;++i)
		for(uf2 j=0;j<1000;++j)
			(a[i+1][j+1]+=a[i][j])%=1'000'000'009,
			(a[i+2][j+1]+=a[i][j])%=1'000'000'009,
			(a[i+3][j+1]+=a[i][j])%=1'000'000'009;

	for(uf2 i=0;i<=1000;i++)
		for(uf2 j=0;j<1000;j++)
			(a[i][j+1]+=a[i][j])%=1'000'000'009;

	return a;
}();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	u4 n, m;
	cin>>n;

	while(cin>>n>>m)
		cout<<a[n][m]<<'\n';
	return 0;
}
