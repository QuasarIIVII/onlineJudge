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

	u2 T;
	constexpr hash<string_view> h;

	for(cin>>T; T--;){
		u2 n;
		cin>>n;

		array<tuple<string, string, u4>, 1000> d;
		auto sd = [&]{
			array<decltype(d)::iterator, 1000> sd;
			for(u2 i=d.size(); i--;)
				sd[i]=d.begin()+i;
			return sd;
		}();
		u2 tdp = 0;
		decltype(sd) td;
		map<size_t, pair<u2, u2>> m;

		for(u2 i=n; i--;){
			auto &[st, ss, x] = d[i];
			u2 a, b;
			cin>>st>>ss>>a>>b;
			x = a<<16 | 0xffff-b;

			const size_t idx = h(ss);
			if(const auto it = m.find(idx); it!=m.end())
				++it->second.first;
			else
				m.emplace(idx, pair<u2, u2>{1u, 0u});
		}

		sort(sd.begin(), sd.begin()+n, [](const auto &a, const auto &b){
			return get<2>(*a) > get<2>(*b);
		});

		for(auto &v : m)
			v.second.first = v.second.first+1 >> 1;

		u4 rx = numeric_limits<u4>::max();
		string_view res;

		u2 i=0, e, c=0;
		for(e = min(10, +n); i<e; ++i){
			auto &[st, ss, x] = *sd[i];
			auto &[k, v] = m[h(ss)];
			if(k <= v || 3 < v){
				td[tdp++] = sd[i];
				continue;
			}

			++v, ++c;
			if(x < rx){
				rx = x;
				res = st;
				DEBUG cout<<res<<' '<<(rx>>16)<<' '<<(0xffff-(rx&0x0FFF))<<'\n';
			}
		}
		for(e = min(20, +n); i<e; ++i){
			auto &[st, ss, x] = *sd[i];
			auto &[k, v] = m[h(ss)];
			if(k <= v || 2 < v){
				td[tdp++] = sd[i];
				continue;
			}

			++v, ++c;
			if(x < rx){
				rx = x;
				res = st;
				DEBUG cout<<res<<' '<<(rx>>16)<<' '<<(0xffff-(rx&0x0FFF))<<'\n';
			}
		}
		for(e = min(30, +n); i<e; ++i){
			auto &[st, ss, x] = *sd[i];
			auto &[k, v] = m[h(ss)];
			if(k <= v || 1 < v){
				td[tdp++] = sd[i];
				continue;
			}

			++v, ++c;
			if(x < rx){
				rx = x;
				res = st;
				DEBUG cout<<res<<' '<<(rx>>16)<<' '<<(0xffff-(rx&0x0FFF))<<'\n';
			}
		}
		for(e = n; i<e; ++i){
			if(c >= 60) break;
			auto &[st, ss, x] = *sd[i];
			auto &[k, v] = m[h(ss)];
			if(v){
				td[tdp++] = sd[i];
				continue;
			}

			++v, ++c;
			if(x < rx){
				rx = x;
				res = st;
				DEBUG cout<<res<<' '<<(rx>>16)<<' '<<(0xffff-(rx&0x0FFF))<<'\n';
			}
		}

		u2 idx = min(60-c, +tdp);
		if(idx){
			auto &[st, ss, x] = *td[idx-1];
			if(x < rx){
				rx = x;
				res = st;
			}
		}
		cout<<res<<'\n';
		DEBUG cout<<(rx>>16)<<' '<<(0xffff-(rx&0x0FFF))<<'\n';
	}
	return 0;
}
AFESDJPOI
;
