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

uf4 mod(array<uf8, 13>& a, uf4 n){
	constexpr static uf4 d = 100'000'000;
	uf4 r = 0, dd = 1;
	for(uf2 i=0; i<13; ++i){
		(r += (a[i]%n) * (dd%n) % n) %= n;
		dd = (dd * d) % n;
	}
	return r;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	uf4 n;
	cin>>s>>n;

	array<uf8, 13> a{0, };

	s = string(s.rbegin(), s.rend());
	for(uf2 i=0; i*8<s.size(); ++i){
		string t = s.substr(i*8, 8);
		a[i] = stoul(string(t.rbegin(), t.rend()));
	}

	DEBUG for(auto x:a)
		cout<<x<<' ';
	DEBUG cout<<endl;

	for(uf2 i=2; i<n; ++i){
		if(!mod(a, i)){
			cout<<"BAD "<<i;
			return 0;
		}
	}

	cout<<"GOOD";
	return 0;
}
//; echo """
