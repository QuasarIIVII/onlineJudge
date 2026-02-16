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
	u2 n, m;
	cin>>n>>m;

	using P = pair<u2, u2>;

	array<char[1024], 1000> a;
	array<array<u1, 1024>, 1000> d{};
	array<P, 1'000'000> st;
	for(u2 i=n; i--;) cin>>a[i];

	u4 r = 0;
	for(u2 i=n; i--;)for(u2 j=m; j--;){
		u4 sp = 0;

		DEBUG cout<<"start: "<<i<<' '<<j<<'\n';

		for(P p = {i, j}, q;; p = q){
			constexpr array<P, 8> dd{
				make_pair(0, 0), make_pair(0, 0),
				make_pair(0, 0), /*S*/make_pair(-1, 0),
				make_pair(0, 0), /*E*/make_pair(0, 1),
				/*N*/make_pair(1, 0), /*W*/make_pair(0, -1),
			};

			const auto &[x, y] = st[sp++] = p;
			DEBUG cout<<"visit: "<<x<<' '<<y<<' '<<a[x][y]<<(a[x][y]&7)<<'\n';
			if(d[x][y]) break;
			d[x][y] = 1;

			const auto &[dx, dy] = dd[a[x][y]&7];
			q = {x+dx, y+dy};

			if(n <= q.first || m <= q.second) break;
		}

		if(const auto &[x, y] = st[sp-1]; d[x][y]==1) ++r;

		while(sp--){
			const auto &[x, y] = st[sp];
			d[x][y] = 2;
		}

		DEBUG for(u2 p=n; p--; cout<<endl)for(u2 q=0; q<m; ++q)
			cout<<+d[p][q];
	}

	cout<<r;
	return 0;
}
AFESDJPOI
;

// N 4e 0100 1110 6
// S 53 0101 0011 3
// E 45 0100 0101 5
// W 57 0101 0111 7
