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
	array<char[128], 100> a;
	array<array<u2, 128>, 100> d;
	memset(d.data(), 0xff, sizeof(d));

	u2 p=0, q=1;
	array<pair<u1, u1>, 16384> Q;

	for(u1 i=n; i--;){
		cin>>a[i];
		for(u1 j=m; j--;)
			if(a[i][j]=='K')
				Q[0] = {i, j}, d[i][j] = 0;
	}

	for(; p!=q; ++p){
		const auto &[i, j] = Q[p];
		DEBUG cout<<+i<<' '<<+j<<' '<<d[i][j]<<'\n';

		const array<pair<u1, u1>, 8> nxts = {
			pair{i-2u, j-1u}, pair{i-2u, j+1u},
			pair{i+2u, j-1u}, pair{i+2u, j+1u},
			pair{i-1u, j-2u}, pair{i-1u, j+2u},
			pair{i+1u, j-2u}, pair{i+1u, j+2u},
		};
		for(const auto &[ii, jj] : nxts){
			if(n<=ii || m<=jj || a[ii][jj]&0x01) continue;
			if(a[ii][jj]=='X'){
				cout<<d[i][j]+1;
				return 0;
			}
			d[ii][jj] = d[i][j]+1;
			a[ii][jj] = 'K';
			Q[q++] = {ii, jj};
		}
	}

	cout<<"-1";

	return 0;
}
AFESDJPOI
;

// . 0010 1110
// X 0101 0100
//
// # 0010 0011
// K 0100 1011
