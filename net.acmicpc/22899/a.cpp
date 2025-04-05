//...; echo """
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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

template<class T, bool (*Cmp)(const T&, const T&)>
struct cmp{
	constexpr bool operator()(const T& a, const T& b) const{
		return Cmp(a, b);
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	using pq_t = priority_queue<
		uf4,
		vector<uf4>,
		less<uf4>
	>;

	map<
		uf4,
		pq_t,
		cmp<
			pq_t,
			[](const pq_t &a, const pq_t &b){
				return (a.size() > b.size());
			}
		>
	> a;

	array<uf4, 100'001> res{0,};
	priority_queue<
		pair<uf4, uf4>,
		vector<pair<uf4, uf4>>,
		cmp<pair<uf4, uf4>, [](const pair<uf4, uf4> &a, const pair<uf4, uf4> &b){
			return (a.second > b.second);
		}>
	> pq;

	uf4 n, k;
	cin>>n>>k;

	{
		array<uf4, 100'001> v;
		for(uf4 i=n; i--;){
			cin>>v[i];
		}
		for(uf4 i=n; i--;){
			uf4 x;
			cin>>x;
			pq.push({v[i], x});
		}
	}

	{
		for(uf4 i=k; i; pq.pop()){
			if(pq.empty()){
				res[n-1] = -1;
				break;
			}

			const auto& vpq = pq.top();
			if(n <= a[vpq.first].size()) continue;

			a[vpq.first].push(vpq.second);
			res[n-1] += vpq.second;
		}
	}

	for(uf4 l=n-1; l--; ){
		if(res[l+1] == -1){
			res[l] = -1;
			continue;
		}
	}

/*
	for(uf4 l=1; l<=n; ++l){
		memset(a, 0, sizeof(a));
		pq = _pq;

		uf8 s=0;
		bool f=true;
		for(uf4 i=k; i; pq.pop()){
			if(pq.empty()){
				f=false;
				cout<<"-1 ";
				break;
			}

			const auto& vpq = pq.top();
			if(l <= a[vpq.first]) continue;

			s += vpq.second;
			++a[vpq.first];

			--i;
		}

		if(f)
			cout<<s<<' ';
	}
*/
	return 0;
}

