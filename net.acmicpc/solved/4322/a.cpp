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
#include<limits>

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

template<uf8 a, size_t i, bool F>
consteval auto f(){
	if constexpr(!F){
		return array<uf8, i>{};
	}else{
		auto aa = f<a*10, i+1, a<=std::numeric_limits<uf8>::max()/10>();
		aa[i]=a;
		return aa;
	}
}

constexpr auto p10 = f<1, 0, true>();

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	while(1){
		string s;
		cin>>s;
		if(s=="0") break;

		uf8 P, Q = std::numeric_limits<uf8>::max();
		string ss0=s.substr(2, s.size()-6);
		string ss1{s[s.size()-4]};

		for(bool f=true; f; ){
			size_t l0 = ss0.size();
			size_t l1 = ss1.size();

			if(ss0.empty())
				ss0 = "0", f=false;

			DEBUG cout<<ss0<<' '<<p10[l0]<<'\t';
			DEBUG cout<<ss1<<' '<<p10[l0]*(p10[l1]-1)<<'\n';

			uf8 p = stoull(ss0)*(p10[l1]-1) + stoull(ss1);
			uf8 q = p10[l0]*(p10[l1]-1);

			for(uf8 d=2, r=max(p, q); d*d<=r; ++d)
				while(p%d==0 && q%d==0)
					p/=d, q/=d, r=max(p, q);

			if(q < Q)
				Q=q, P=p;

			ss1 = ss0.back() + ss1;
			ss0.pop_back();
		}

		cout<<P<<'/'<<Q<<'\n';
	}
	return 0;
}
//; echo """
