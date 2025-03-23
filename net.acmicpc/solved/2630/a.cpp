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

array<array<bool, 128>, 128> a;

// bit scan forward
inline auto bfs(u4 x){
	return __builtin_ctz(x);
}

inline array<u4, 2> operator+(const array<u4, 2>& a, const array<u4, 2>& b){
	return {a[0]+b[0], a[1]+b[1]};
}

array<u4, 2> f(u4 p, u4 q, u4 sz){
	static constexpr array<u4, 2> a0{1, 0}, a1{0, 1};

	sz >>= 1;
	if(!sz) return a[p][q] ? array<u4, 2>{0, 1} : array<u4, 2>{1, 0};

	array<array<u4, 2>, 4> r{
		f(p, q, sz),
		f(p + sz, q, sz),
		f(p, q + sz, sz),
		f(p + sz, q + sz, sz)
	};

	u1 f = 3;
	for(uf4 i=4; i--;){
		if(r[i] != a0) f &= ~1;
		if(r[i] != a1) f &= ~2;
		DEBUG cout<<r[i][0]<<' '<<r[i][1]<<endl;
	}

	if(f){
		if(f == 1) return a0;
		if(f == 2) return a1;
	}

	return r[0] + r[1] + r[2] + r[3];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	u4 n;
	cin>>n;
	for(u4 i=n; i--;) for(u4 j=n; j--;){
		char c;
		cin>>c;
		a[i][j] = c == '1';
	}

	array<u4, 2> r = f(0, 0, n);

	cout<<r[0]<<'\n'<<r[1];
	return 0;
}

