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

constexpr array<array<uf2, 3>, 3> add{{
	{0, 1, 2},
	{1, 1, 2},
	{2, 2, 2}
}}, mul{{
	{0, 0, 0},
	{0, 1, 1},
	{0, 1, 2}
}};

/*
 * a = {0, 1, 2, P, Q, R}
 * S -> (S)
 * S -> -S
 * S -> S+S
 * S -> S*S
 * S -> a
 */

class a{
private:
	uf8 v;
	a *l, *r;
	/*
	 * 0x00: S (start / non-terminal)
	 * 0x10: (S)
	 * 0x11: -S
	 * 0x12: S+S
	 * 0x13: S*S
	 * 0x20: 0 (terminal)
	 * 0x21: 1 (terminal)
	 * 0x22: 2 (terminal)
	 * 0x30: P (terminal)
	 * 0x31: Q (terminal)
	 * 0x32: R (terminal)
	 */

	struct S{
		char c;
		a* p;
	};

	size_t parse(list<S> &ls){
	}

public:
	a(): v(0), l(nullptr), r(nullptr){}
	size_t parse(const char *s, const size_t *e){
		list<S> ls;
		for(;s<e;++s){
			ls.push_back({*s, nullptr});
		}
		parse(ls);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 0;
}
