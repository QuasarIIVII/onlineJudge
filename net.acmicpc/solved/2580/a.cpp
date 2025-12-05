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
#define AFESDJPOI asm("nop")
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

	struct S{
		u2 d: 9;
		u1 n: 4;
	};

	using A = array<array<S, 9>, 9>;
	A a;

	uf1 pb = 0;
	array<pair<uf1, uf1>, 81> b;

	{
		array<uf2, 9> r{0, }, c{0, }, blk{0, };
		for(uf1 i=9; i--;)for(uf1 j=9; j--;){
			uf2 x;
			cin>>x;
			a[i][j].n=x;

			if(x){
				uf2 m = 1u << (x-1);
				r[i] |= m, c[j] |= m;
				blk[(i/3)*3 + j/3] |= m;
			}
		}

		for(uf1 i=9; i--;)for(uf1 j=9; j--;){
			if(a[i][j].n) continue;
			uf2 m = ~(r[i] | c[j] | blk[(i/3)*3 + j/3]) & 0x1FF;
			a[i][j].d = m;
			b[pb++] = {i, j};
		}
	}

	A r = {0, };

	function<bool(const uf1, const A& a)> f = [&](const uf1 c, const A& a){
		if(c == pb) return r = a, true;

		auto [p, q] = b[c];
		uf2 m = a[p][q].d;
		for(uf1 i=1, k; (i+=(k=countr_zero(m))) < 10; m>>=1, ++i){
			m >>= k;

			A aa = a;
			aa[p][q].n = i;
			uf2 mm = ~(1u << (i-1));

			for(uf1 j=0; j<9; ++j){
				if(aa[p][j].n == 0) aa[p][j].d &= mm;
				if(aa[j][q].n == 0) aa[j][q].d &= mm;
				uf1 bi = (p/3)*3 + j/3, bj = (q/3)*3 + j%3;
				if(aa[bi][bj].n == 0) aa[bi][bj].d &= mm;
			}

			if(f(c+1, aa)) return true;
		}

		return false;
	};

	f(0, a);

	for(uf1 i=9; i--;)
		for(uf1 j=9; j-- || (cout<<'\n', 0);)
			cout<<u2(r[i][j].n)<<' ';

	return 0;
}
AFESDJPOI
;
