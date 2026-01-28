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
	array<string, 1000> a;
	array<array<array<u4, 4>, 1000>, 1000> d{};

	for(u2 i=0; i<n; ++i) cin>>a[i];

	const function<u4(const u2, const u2, const u1)> f
	= [&](const u2 x, const u2 y, const u1 di) -> u4 {
		DEBUG cout<<"f "<<x<<" "<<y<<" "<<+di<<endl;
		/*
		 * a[x][y] == '/' 2f
		 * 0 > 3
		 * 1 > 2
		 * 2 > 1
		 * 3 > 0
		 * xor 11
		 * a[x][y] == '\' 5c
		 * 0 > 1
		 * 1 > 0
		 * 2 > 3
		 * 3 > 2
		 * xor 01
		 */

		if(d[x][y][di] & 0xff'ffffu) return d[x][y][di];
		if(d[x][y][di]>>24) return d[x][y][di]=0u;

		constexpr array<pair<u2, u2>, 4> dd{
			pair{-1, 0}, pair{0, -1},
			pair{1, 0}, pair{0, 1},
		};

		const u1 ndi = di ^ (a[x][y]&0x02u|1u);
		const u2 nx = x + dd[ndi].first;
		const u2 ny = y + dd[ndi].second;

		if(n<=nx || m<=ny) return d[x][y][di]=1u;
		d[x][y][di] |= 0x0100'0000u;
		const u4 ret = f(nx, ny, ndi);
		return d[x][y][di] = ret ? ret + 1u : 0u;
	};

	u4 r = 0;
	for(u2 i=n; i--;){
		r = max(r, f(i, 0, 3));
		r = max(r, f(i, m-1, 1));
	}
	for(u2 j=m; j--;){
		r = max(r, f(0, j, 2));
		r = max(r, f(n-1, j, 0));
	}

	if(r) cout<<r;
	else cout<<"-1";

	return 0;
}
AFESDJPOI
;
