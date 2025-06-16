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
#include<iomanip>

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

f8 distsq(f8 ax, f8 ay, f8 bx, f8 by){
	return (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	f8 ax, ay, bx, by;
	array<array<f8, 2>, 1000> c;
	cin>>ax>>ay>>bx>>by;
	cout<<fixed<<setprecision(3);
	for(uf2 i=0; cin>>c[i][0]>>c[i][1]; ++i){
		if(distsq(ax, ay, c[i][0], c[i][1])*4 < distsq(c[i][0], c[i][1], bx, by)){
			cout<<"The gopher can escape through the hole at ("<<c[i][0]<<","<<c[i][1]<<").";
			return 0;
		}
	}
	cout<<"The gopher cannot escape.";
	return 0;
}
//; echo """
