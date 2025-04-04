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

array<array<if2, 1024>, 1024> a;

if2 f(uf4 x, uf4 y, uf2 n){
	if(n==1) return a[x][y];
	uf2 nn=n/2;
	array<if2, 4> b{
		f(x, y, nn),
		f(x, y+nn, nn),
		f(x+nn, y, nn),
		f(x+nn, y+nn, nn)
	};
	sort(b.begin(), b.end());
	DEBUG cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl;
	return b[2];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n;
	cin>>n;
	for(uf2 i=n; i--;)for(uf2 j=n; j--;)
		cin>>a[i][j];

	cout<<f(0, 0, n);
	return 0;
}

