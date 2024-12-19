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
#include<climits>

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

constexpr array<uf4, 11> pow10 = []() constexpr{
	array<uf4, 11> p = {1};
	for(uf4 i=1; i<p.size()-1; ++i)
		p[i] = p[i-1]*10;
	p[p.size()-1]=UINT_FAST32_MAX;
	return p;
}();

constexpr inline uf4 l10(uf4 n){
	uf4 r=0;
	for(;pow10[r+1]<=n;++r);
	return r;
}

inline uf4 f(uf4 n){
	const uf4 d = l10(n);
	if(n/pow10[d] < 5) return 0;
	else return pow10[d+1];
}

inline uf4 g(uf4 n){
	uf4 d = l10(n);
	for(uf4 i=0, m; i <= d; ++i){
		m=n/pow10[i]%10;
		(n/=pow10[i+1])*=pow10[i+1];
		if(4 < m) n+=pow10[i+1];
	}
	return n;
}

bitset<pow10[9]+1> b;
map<uf4, list<uf4>> m;
array<uf4, pow10[5]> o;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 T, mx=0;
	cin>>T;

	for(uf4 t=T;t--;){
		uf4 n;
		cin>>n;

		b.set(n);
		m[n].push_back(t);
		if(mx<n)mx=n;
	}

	uf4 c=0;
	for(uf4 i=2;i<=mx;++i){
		if(f(i) != g(i)) ++c;
		if(b[i]){
			const auto& l = m[i];
			for(const auto a : l)
				o[a] = c;
		}
	}

	for(uf4 t=T;t--;)
		cout<<o[t]<<'\n';

	return 0;
}
