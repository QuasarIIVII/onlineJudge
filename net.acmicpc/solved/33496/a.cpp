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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	unordered_map<if4, uf1> m;
	m.reserve(400'000);

	uf4 n;
	cin>>n;

	while(n--){
		if4 x, y;
		cin>>x>>y;
		m[x-y]|=1;
		m[x+y]|=2;
	}

	DEBUG cout<<m.size()<<'\n';
	DEBUG for(auto& [k, v]: m){
		cout<<k<<' '<<static_cast<uf2>(v)<<'\n';
	}

	vector<pair<if4, uf1>> v;
	v.reserve(m.size());

	for(auto& [k, x]: m){
		v.emplace_back(k, x);
	}

	sort(v.begin(), v.end(), [](auto& a, auto& b){
		return a.first<b.first;
	});

	uf4 a = 0, r = 0;
	for(auto& [x, y]: v){
		if(y&2) r+=a;
		if(y&1) ++a;
	}

	cout<<r+m.size()<<'\n';
	return 0;
}
//; echo """
