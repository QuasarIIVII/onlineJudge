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
#define DEBUG_MACRO(x) 0
#define DEBUG_MACRO_ELSE(x) x
#else
#define DEBUG_MACRO(x) x
#define DEBUG_MACRO_ELSE(x) 0
#endif

#define DEBUG if constexpr(debug)

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 n, k;
	cin>>n>>k;

	priority_queue<pair<uf4, uf4>, vector<pair<uf4, uf4>>, greater<>> dpq;
	array<priority_queue<uf4, vector<uf4>, greater<>>, 100'000> dpqs;

	{
		array<uf4, 100'000> a;
		for(uf4 i=n; i--;) cin>>a[i];
		for(uf4 i=n; i--;){
			uf4 x;
			cin>>x;
			dpqs[a[i]-1].emplace(x);
		}
	}

	for(uf4 i=n; i--;){
		if(dpqs[i].empty()) continue;
		dpq.emplace(dpqs[i].top(), i);
	}

	array<priority_queue<uf4>, 100'000> rpqs;

	DEBUG cout<<"max limit"<<endl;
	uf8 r = 0;
	for(uf4 i=k; i--;){
		auto [v, p] = dpq.top();
		dpq.pop();
		dpqs[p].pop();

		r += v;
		rpqs[p].emplace(v);
		DEBUG cout<<p<<' '<<v<<' '<<r<<'\n';

		if(dpqs[p].size())
			dpq.emplace(dpqs[p].top(), p);
	}

	array<uf4, 100'000> sza;
	set<pair<uf4, uf4>> szs;

	DEBUG cout<<"init szs"<<endl;
	for(uf4 i=n; i--;){
		if(sza[i] = rpqs[i].size())
			DEBUG_MACRO(cout<<i<<' '<<sza[i]<<'\n'),
			szs.emplace(sza[i], i);
	}

	uf4 sp = 0;
	array<uf8, 100'000> st;
	st[sp++] = r;

	uf4 i;
	for(i=n; --i;){
		uf4 c = 0;
		DEBUG cout<<"step "<<i<<' '<<r<<'\n';
		for(decltype(szs.end()) it; szs.size() && i < (it=prev(szs.end()))->first; ++c){
			auto [v, p] = *it;
			szs.erase(it);
			DEBUG cout<<"remove "<<p<<' '<<v<<' '<<rpqs[p].top()<<'\n';

			r -= rpqs[p].top();
			rpqs[p].pop();

			if(v = rpqs[p].size())
				szs.emplace(v, p);
			sza[p] = v;
		}

		while(c--){
			if(dpq.empty()) goto ret;

			auto [v, p] = dpq.top();
			dpq.pop();
			dpqs[p].pop();

			DEBUG cout<<"try add "<<p<<' '<<v<<'\n';

			if(i <= sza[p]){
				if(dpq.size()) continue;
				else goto ret;
			}

			DEBUG cout<<": accept"<<'\n';

			r += v;
			rpqs[p].emplace(v);

			if(dpqs[p].size())
				dpq.emplace(dpqs[p].top(), p);

			if(sza[p]) szs.erase({sza[p], p});
			if(++sza[p]) szs.emplace(sza[p], p);
		}

		st[sp++] = r;
		DEBUG cout<<endl;
	}
ret:
	DEBUG cout<<"ret\n"<<i<<' '<<sp<<'\n';
	while(i--) cout<<"-1 ";
	while(sp--) cout<<st[sp]<<' ';

	return 0;
}
AFESDJPOI
;
