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

	array<bitset<100>, 100> a;
	uf2 n, m, k;
	cin>>n>>m>>k;

	const auto b = ~bitset<100>() >> (100-m);

	while(k--){
		uf2 p0, q0, p1, q1;
		cin>>q0>>p0>>q1>>p1;
		for(uf4 i=p1; i--!=p0;)
			a[i] |= b>>(q0+m-q1)<<q0;
	}

	DEBUG for(uf4 i=0; i<n; ++i)
		cout<<a[i]<<'\n';

	priority_queue<uf2, vector<uf2>, greater<uf2>> pq;
	for(uf2 i=n; i--;)for(uf2 j=m; j--;){
		if(a[i].test(j)) continue;
		uf2 r = 0;
		queue<pair<uf2, uf2>> qq;
		qq.emplace(i, j);

		for(;qq.size(); qq.pop()){
			auto [p, q] = qq.front();
			if(a[p].test(q)) continue;
			a[p].set(q);

			++r;
			const array<pair<uf2, uf2>, 4> nxs{
				make_pair(p+1u, q),
				make_pair(p-1u, q),
				make_pair(p, q+1u),
				make_pair(p, q-1u)
			};

			for(const auto &[np, nq] : nxs){
				if(n<=np || m<=nq) continue;
				if(a[np].test(nq)) continue;
				qq.emplace(np, nq);
			}
		}

		pq.emplace(r);
	}

	for(cout<<pq.size()<<'\n'; pq.size(); pq.pop())
		cout<<pq.top()<<' ';

	return 0;
}
AFESDJPOI
;
