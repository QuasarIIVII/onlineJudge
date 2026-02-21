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

	constexpr hash<string> h;

	map<size_t, u4> m0;
	map<size_t, list<pair<size_t, u4>>> m1;
	list<size_t> rts;

	{
		u4 n;
		cin>>n;
		while(n--){
			string s;
			u4 v;
			cin>>s>>v;
			size_t hh=h(s);
			m0.emplace(hh, v);
		}

		set<size_t> mt;
		cin>>n;
		while(n--){
			string s;
			u4 v;
			cin>>s>>v;

			list<pair<size_t, u4>> li;
			while(v--){
				string ss;
				u4 vv;
				cin>>ss>>vv;
				size_t hh=h(ss);
				li.emplace_back(hh, vv);
				mt.emplace(hh);
			}

			size_t hh=h(s);
			DEBUG cout<<"s: "<<s<<" hh: "<<hh<<endl;
			m1.emplace(hh, move(li));
		}

		for(const auto &[k, v] : m1){
			if(mt.contains(k)) continue;
			rts.emplace_back(k);
			break;
		}
	}

	const function<u8(const size_t)> f = [&](const size_t x){
		if(const auto it=m0.find(x); it!=m0.end())
			return u8(it->second);
		u8 r = 0;
		for(const auto &[k, v] : m1[x])
			r += v * f(k);
		return u8(r);
	};

	u8 r = 0;
	for(const auto &rt : rts)
		r += f(rt);

	cout<<r;

	return 0;
}
AFESDJPOI
;
