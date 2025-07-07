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

	uf4 n, m, r=0;
	cin>>n>>m;
	n*=24;

	priority_queue<pair<uf1, uf1>> pq;

	{
		array<uf1, 200'000> a;

		for(uf4 i=m; i--;){
			uf2 x;
			cin>>x;
			a[i] = 100-x;
			r+=x;
		}

		for(uf4 i=m; i--;){
			uf2 x;
			cin>>x;
			pq.emplace(x, a[i]);
		}
	}

	while(n){
		const auto& top = pq.top();
		if(!top.first && !top.second) break;
		const uf4 x = min(static_cast<uf4>(top.second / top.first), n);
		uf4 y = top.first*x;
		DEBUG cout<<(uf2)top.first<<' '<<(uf2)top.second<<'\t'<<x<<' '<<y<<endl;
		r+=y;
		n-=x;
		y = top.second - y;
		pq.pop();
		pq.emplace(y, y);
	}

	cout<<r;;
	return 0;
}
//; echo """
