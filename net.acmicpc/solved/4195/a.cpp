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
#define AFESDJPOI asm("")
//$(pwd); cat <<AFESDJPOI

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

	u4 T;
	ostringstream oss;
	for(cin>>T; T--;){
		u4 n, ps = 0;

		array<char[32], 200'000> s;
		unordered_map<string_view, u4> m;
		array<u4, 200'000> um, umsz{};

		for(cin>>n; n--;){
			char ts0[32], ts1[32];
			u4 p, q;
			cin>>ts0>>ts1;

			if(auto it = m.find(ts0); it==m.end()){
				memcpy(s[ps], ts0, sizeof(decltype(s)::value_type));
				m.emplace(s[ps], p = ps);
				++ps;
			} else p = it->second;
			if(auto it = m.find(ts1); it==m.end()){
				memcpy(s[ps], ts1, sizeof(decltype(s)::value_type));
				m.emplace(s[ps], q = ps);
				++ps;
			} else q = it->second;

			if(!umsz[p]) umsz[um[p] = p] = 1;
			if(!umsz[q]) umsz[um[q] = q] = 1;

			u4 rp, rq, sp = 0;
			array<u4*, 200'000> st;

			for(rp = p; rp!=um[rp]; rp=um[rp]) st[sp++] = um.data()+rp;
			while(sp) *st[--sp] = rp;

			for(rq = q; rq!=um[rq]; rq=um[rq]) st[sp++] = um.data()+rq;
			while(sp) *st[--sp] = rq;

			if(rp!=rq){
				um[rq] = rp;
				umsz[rp] += umsz[rq];
			}

			oss<<umsz[rp]<<'\n';
		}
	}

	cout<<oss.str();
	return 0;
}
AFESDJPOI
;
