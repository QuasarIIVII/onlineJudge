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

inline bool _cmp(const pair<uf4, uf4>& a, const pair<uf4, uf4>& b){
	return a.second > b.second;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 n;
	array<bool, 100'001> a{0, };

	priority_queue<
		pair<uf4, uf4>,
		vector<pair<uf4, uf4>>,
		cmp<
			pair<uf4, uf4>,
			_cmp
		>
	> pq;

	cin>>n;
	for(uf4 i=n+1; --i; ){
		uf4 x;
		cin>>x;
		pq.emplace(i, x);
	}

	DEBUG{
		const auto& [i, x] = pq.top();
		cout<<i<<' '<<x<<'\n';
	}

	a[0]=true;
	a[n+1]=true;

	uf4 mx=0, r=1, prev;

	for(; pq.size(); ){
		for(prev = pq.top().second; pq.size() && pq.top().second == prev; pq.pop()){
			const auto& [i, x] = pq.top();

			if(a[i-1] && a[i+1])
				--r;
			else if(!a[i-1] && !a[i+1])
				++r;

			a[i]=true;
		}

		if(mx < r)
			mx = r;
	}

	cout<<mx;

	return 0;
}
//; echo """
