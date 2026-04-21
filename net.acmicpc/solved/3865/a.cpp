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

struct X{
	array<array<string, 10>, 100> to;
	array<u1, 100> t;
	array<string, 100> g;
	unordered_map<string, u4> gm;
	unordered_set<string> ps;
	array<u1, 100> v;

	static void p(const string &s, string &lhs, array<string, 10> &rhs, u1 &rc){
		lhs.clear();
		rc = 0;

		u4 i = 0;
		while(s[i] != ':') lhs += s[i++];

		++i;
		for(string cur;; ++i){
			if(s[i] == ',' || s[i] == '.'){
				rhs[rc++] = move(cur);
				if(s[i] == '.') break;
				cur.clear();
			}else cur += s[i];
		}
	}

	u4 f(u4 s){
		array<u1, 100> sp{};
		array<u4, 100> st{};

		v.fill(0);
		ps.clear();

		st[sp[0]++] = s;
		v[s] = 1;

		while(sp[0]){
			const u4 x = st[--sp[0]];
			for(u4 i=0; i<t[x]; ++i){
				const auto it = gm.find(to[x][i]);
				if(it == gm.end()) ps.insert(to[x][i]);
				else if(!v[it->second]){
					v[it->second] = 1;
					st[sp[0]++] = it->second;
				}
			}
		}

		return ps.size();
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	for(u4 n; cin>>n && n;){
		X x;
		string s;
		cin.ignore();

		for(u4 i=0; i<n; ++i){
			getline(cin, s);
			X::p(s, x.g[i], x.to[i], x.t[i]);
			x.gm.emplace(x.g[i], i);
		}

		cout<<x.f(0)<<'\n';
	}

	return 0;
}
AFESDJPOI
;
