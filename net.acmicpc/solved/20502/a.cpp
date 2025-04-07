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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<bitset<128>, 100> key{bitset<128>(0)};
	array<uf4, 100> rnk;

	uf4 n,m;
	cin>>n>>m;

	for(uf4 i=0; i<n; ++i)
		cin>>rnk[i];

	for(uf4 i=0; i<n; ++i){
		uf4 mi;
		cin>>mi;
		for(uf4 j=mi; j--;){
			uf4 x;
			cin>>x;
			key[i].set(x);
			DEBUG cout<<key[i].to_string()<<endl;
		}
	}

	uf4 Q;
	cin>>Q;
	struct S{
		uf4 n;
		uf4 r;

		S(uf4 n, uf4 r):n(n),r(r){}
	};

	for(vector<S> v; Q--;){
		v.clear();

		uf4 x;
		cin>>x;

		for(uf4 i=n; i--;){
			if(key[i].test(x))
				v.emplace_back(i, rnk[i]);
		}

		if(v.empty()){
			cout<<"-1\n";
			continue;
		}

		sort(v.begin(), v.end(), [](const S& a, const S& b){
			return a.r < b.r;
		});

		for(auto& i : v){
			cout<<i.n+1<<" ";
		}
		cout<<"\n";

	}

	return 0;
}

