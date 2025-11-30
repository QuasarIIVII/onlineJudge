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

	uf4 n, k;
	cin>>n>>k;

	queue<uf2> q;
	map<uf2, uf4> m0, m1;

	uf4 s0, s1;
	uf8 r;
	{
		array<uf2, 5000> a;
		for(uf2 i=k; i--;){
			cin>>a[i];
			q.push(a[i]);
		}
		sort(a.begin(), a.begin()+k);

		if(k&1){
			for(uf2 i=k/2; i--;){
				++m0[a[i]];
				++m1[a[k/2 + i+1]];
			}
			++m0[a[k/2]];
			s0 = k/2 + 1, s1 = k/2;
		}else{
			for(uf2 i=k/2; i--;){
				++m0[a[i]];
				++m1[a[k/2 + i]];
			}
			s0 = s1 = k/2;
		}

		r = prev(m0.end())->first;
	}

	DEBUG{
		for(const auto& [x, c]: m0) cout<<x<<':'<<c<<' ';
		cout<<'\n';
		for(const auto& [x, c]: m1) cout<<x<<':'<<c<<' ';
		cout<<'\n';
	}

	for(uf4 i=n-k; i--; q.pop()){
		uf2 x = q.front();
		if(const auto it = m0.find(x); it != m0.end()){
			--s0;
			if(!--it->second) m0.erase(it);
		}else{{
			--s1;
			const auto it = m1.find(x);
			if(!--it->second) m1.erase(it);
		}}

		if(s0 < s1){
			const auto it = m1.begin();
			++m0[it->first];
			if(!--it->second) m1.erase(it);
			++s0, --s1;
		}else if(s1+1 < s0){
			const auto it = prev(m0.end());
			++m1[it->first];
			if(!--it->second) m0.erase(it);
			--s0, ++s1;
		}

		cin>>x;
		q.push(x);

		++m0[x];
		++s0;
		if(s1+1 < s0){
			const auto it = prev(m0.end());
			++m1[it->first];
			if(!--it->second) m0.erase(it);
			--s0, ++s1;
		}

		if(s1 && m1.begin()->first < prev(m0.end())->first){
			const auto it0 = prev(m0.end());
			const auto it1 = m1.begin();

			++m0[it1->first];
			if(!--it1->second) m1.erase(it1);

			++m1[it0->first];
			if(!--it0->second) m0.erase(it0);
		}

		DEBUG{
			for(const auto& [x, c]: m0) cout<<x<<':'<<c<<' ';
			cout<<'\n';
			for(const auto& [x, c]: m1) cout<<x<<':'<<c<<' ';
			cout<<'\n';
		}

		DEBUG cout<<prev(m0.end())->first<<'\n';
		r += prev(m0.end())->first;
	}

	cout<<r<<'\n';
	return 0;
}
//; echo """
