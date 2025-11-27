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
#include<stdfloat>
#include<cmath>
#include<cstring>
//; echo """

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

	array<uf4, 1000> a;
	array<uf2, 1000> aa;
	array<list<pair<uf2, uf4>>, 1000> b;

	uf2 n; uf4 m;
	cin>>n>>m;

	while(m--){
		uf2 p, q;
		uf4 x;
		cin>>p>>q>>x;
		b[p-1].emplace_back(q-1, x);
	}

	uf2 s, e;
	cin>>s>>e;
	--s; --e;

	a.fill(numeric_limits<uf4>::max());
	a[s]=0; aa[s]=s;

	priority_queue<pair<uf4, uf2>, vector<pair<uf4, uf2>>, greater<>> pq;
	pq.emplace(0, s);

	while(pq.size()){
		auto [x, p] = pq.top();
		pq.pop();

		if(a[p] < x) continue;

		for(auto [q, y] : b[p]){
			if(a[q] <= a[p] + y) continue;
			a[q] = a[p] + y;
			aa[q] = p;
			pq.emplace(a[q], q);
		}
	}

	cout<<a[e]<<"\n";

	stack<uf2> r;
	for(uf2 p=e; p!=s; p=aa[p]) r.push(p);
	cout<<r.size()+1<<"\n"<<s+1<<" ";
	while(r.size()){
		cout<<r.top()+1<<" ";
		r.pop();
	}
	return 0;
}
//; echo """
