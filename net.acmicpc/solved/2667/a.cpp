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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n;
	cin>>n;

	array<array<uf1, 25>, 25> a;

	for(uf1 i=n; i--;){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		for(uf1 j=n; j--;){
			char c;
			cin>>c;
			a[i][j] = c-0x30;
		}
	}

	array<uf2, 25*25/2 + 4> r;
	uf2 p=0;

	const function<uf2(uf1, uf1)> f = [&](uf1 x, uf1 y){
		if(!a[x][y]) return uf2(0);
		a[x][y] = 0;

		const array<pair<uf1, uf1>, 4> nxts{
			pair{x+1u, y},
			pair{x-1u, y},
			pair{x, y+1u},
			pair{x, y-1u},
		};

		uf2 r = 1;
		for(const auto& nxt : nxts){
			if(n <= nxt.first || n<=nxt.second)
				continue;
			r += f(nxt.first, nxt.second);
		}

		return r;
	};

	for(uf1 i=n; i--;)for(uf1 j=n; j--;){
		if(uf2 tr = f(i, j); tr)
			r[p++] = tr;
	}

	sort(r.begin(), r.begin()+p);

	cout<<p<<'\n';
	for(uf2 i=0; i<p; ++i)
		cout<<static_cast<uf2>(r[i])<<'\n';
	return 0;
}
//; echo """
