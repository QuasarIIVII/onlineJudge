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

	u4 n, m;
	array<array<u1, 64>, 50> a;
	memset(a.data(), 0xff, sizeof(a));
	struct S{ u4 x, y; };
	u4 qp = 0, qq = 0;
	array<S, 2500> q;

	cin>>n>>m;
	for(u4 i=n; i--;)for(u4 j=m; j--;){
		u2 x;
		cin>>x;
		if(x){
			DEBUG cout<<i<<' '<<j<<'\n';
			q[qq++] = {i, j};
			a[i][j] = 0;
		}
	}

	u1 mx = 0;
	while(qp!=qq){
		const auto &[x, y] = q[qp++];

		const array<S, 8> d{
			S{x-1u, y-1u}, S{x-1u, y}, S{x-1u, y+1u},
			S{x, y-1u}, S{x, y+1u},
			S{x+1u, y-1u}, S{x+1u, y}, S{x+1u, y+1u},
		};

		for(const auto &[nx, ny] : d){
			if(n<=nx || m<=ny) continue;
			if(a[nx][ny] != 0xff) continue;
			DEBUG cout<<nx<<' '<<ny<<' '<<+a[x][y]<<'\n';
			mx = max(mx, a[nx][ny] = a[x][y] + 1u);
			q[qq++] = {nx, ny};
		}
	}

	cout<<+mx;
	return 0;
}
AFESDJPOI
;
