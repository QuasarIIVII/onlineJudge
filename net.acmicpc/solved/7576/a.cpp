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

	uf2 n, m;
	cin>>m>>n;

	array<array<uf1, 1'000>, 1'000> a;
	array<queue<pair<uf2, uf2>>, 2> q;

	uf4 C = 0;
	for(uf2 i=n; i--;)for(uf2 j=m; j--;){
		if2 x;
		cin>>x;
		switch(x){
		case -1:
			a[i][j]=0;
			break;
		case 0:
			a[i][j]=1;
			++C;
			break;
		case 1:
			a[i][j]=2;
			q[0].emplace(i, j);
			break;
		default:
			__builtin_unreachable();
		}
	}

	if(!C){
		cout<<'0';
		return 0;
	}

	for(uf4 i=0;; ++i){
		auto &qa = q[i&1], &qb = q[i&1^1];

		if(qa.empty()){
			cout<<"-1";
			return 0;
		}

		for(; qa.size(); qa.pop()){
			const auto [p, q] = qa.front();
			const array<pair<uf2, uf2>, 4> nxt{
				make_pair(p+1u, q),
				make_pair(p-1u, q),
				make_pair(p, q+1u),
				make_pair(p, q-1u),
			};

			for(const auto [np, nq] : nxt){
				if(n<=np || m<=nq || a[np][nq]!=1) continue;
				a[np][nq]=2;
				--C;
				qb.emplace(np, nq);
			}

			if(!C){
				cout<<i+1;
				return 0;
			}
		}
	}

	return 0;
}
//; echo """
