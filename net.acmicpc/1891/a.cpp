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

constexpr array<array<if8, 2>, 4> d = {{
	{1, 1},
	{0, 1},
	{0, 0},
	{1, 0}
}};
constexpr array<char, 4> c = {'3', '2', '4', '1'};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n;
	array<if8, 2> dp, p = {0, 0};
	string s;

	cin>>n>>s>>dp[0]>>dp[1];
	for(uf2 i=0; i<n; ++i){
		p[0]<<=1, p[1]<<=1;
		auto a = s[i]-0x31;
		p[0]|=d[a][0], p[1]|=d[a][1];
	}

	DEBUG cout<<p[0]<<' '<<p[1]<<endl;
	p[0] += dp[0], p[1] += dp[1];
	DEBUG cout<<p[0]<<' '<<p[1]<<endl;

	if(p[0] < 0 || static_cast<if8>(1)<<n <= p[0] || p[1] < 0 || static_cast<if8>(1)<<n <= p[1]){
		cout<<"-1";
		return 0;
	}


	s = string("");
	p[0]<<=1;
	for(uf2 i=n; i--; )
		s += c[(p[0] >> i & 2) | (p[1] >> i & 1)];

	cout<<s;
	return 0;
}

