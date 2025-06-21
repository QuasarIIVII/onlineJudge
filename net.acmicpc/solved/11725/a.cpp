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

	array<list<uf4>, 100'000> a;

	uf4 n;
	cin>>n;

	for(uf4 i=n-1; i--; ){
		uf4 x, y;
		cin>>x>>y;
		--x, --y;
		a[x].emplace_back(y);
		a[y].emplace_back(x);
	}

	array<uf4, 100'000> r;
	array<bool, 100'000> v{false, };
	queue<pair<uf4, uf4>> q;

	v[0] = true;
	q.emplace(0, 0);

	for(; q.size(); q.pop()){
		const auto& cur = q.front();

		r[cur.first] = cur.second;

		for(const auto& aa : a[cur.first]){
			if(v[aa]) continue;
			v[aa] = true;
			q.emplace(aa, cur.first);
		}
	}


	for(uf4 i=1; i<n; ++i)
		cout<<r[i]+1<<'\n';

	return 0;
}
//; echo """
