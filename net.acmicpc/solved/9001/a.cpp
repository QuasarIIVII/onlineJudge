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
//; echo """

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

inline bool f(const array<uf2, 4> &a, const array<uf2, 4> &b){
	return a[0] < b[2] && b[0] < a[2] && a[1] < b[3] && b[1] < a[3];
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 T;
	cin>>T;

	while(T--){
		const uf1 n = []{;
			uf2 n;
			cin>>n;
			return n;
		}();

		const auto a = [&]{
			array<array<uf2, 4>, 200> a;
			for(uf4 i=n; i--;){
				cin>>a[i][0]>>a[i][1]>>a[i][2]>>a[i][3];
				// l b r t
				++a[i][2];
				++a[i][3];
			}
			return a;
		}();

		const auto b = [&]{
			array<list<uf1>, 200> b;
			for(uf1 i=n; i--;)for(uf1 j=i; j--;)
				if(f(a[i], a[j])) b[i].push_back(j), b[j].push_back(i);
			return b;
		}();

		auto c = [] consteval {
			array<uf1, 200> c;
			for(size_t i = c.size(); i--;)
				c[i] = i;
			return c;
		}();

		function<uf1(const uf1)> g0 = [&](const uf1 i)->uf1{
			if(i == c[i]) return i;
			const uf1 r = g0(c[i]);
			c[i] = r;
			return r;
		};

		bitset<200> v;

		function<void(const uf1)> g1 = [&](const uf1 i){
			v.set(i);

			const uf1 p = g0(i);
			for(const uf1 j : b[i]){
				if(v.test(j)) continue;
				const uf1 q = g0(j);
				c[q] = p;
				g1(j);
			}
		};

		for(uf4 i=n; i--;){
			if(v.test(i)) continue;

			g1(i);
		}

		DEBUG for(uf1 i=n; i-- || (cout<<endl, 0);)
			cout<<(uf2)(n-c[i])<<' ';

		uf1 r = 0;
		for(uf4 i=n; i--;)
			if(i == c[i]) ++r;

		cout<<static_cast<uf2>(r)<<'\n';
	}

	return 0;
}
//; echo """
