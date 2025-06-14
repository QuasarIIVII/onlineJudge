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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n, m;
	array<array<uf2, 100>, 100> a;

	cin>>n>>m;

	[[assume(n < 100 && m < 100)]];

	for(uf1 i=n; i--;)for(uf1 j=m; j--;)
		cin>>a[i][j];

	uf2 C = 0;
	for(uf1 I=n; I--;)for(uf1 J=m; J--;){
		using tpl = tuple<uf1, uf1, uf2>;
		const auto& _cmp = [](const tpl& a, const tpl& b){return get<2>(a) > get<2>(b);};
		priority_queue<tpl, vector<tpl>, decltype(_cmp)> pq(_cmp);
		array<array<bool, 100>, 100> b{false, };
		uf2 c = 0, x = 0;

		b[I][J] = true;
		pq.emplace(I, J, a[I][J]);

		while(pq.size()){
			const auto top = pq.top();
			pq.pop();

			if(get<2>(top) <= x) continue;
			x = get<2>(top);
			++c;

			const array<array<uf1, 2>, 4> nxts{
				array<uf1, 2>{static_cast<uf1>(get<0>(top)+1u), get<1>(top)},
				array<uf1, 2>{static_cast<uf1>(get<0>(top)-1u), get<1>(top)},
				array<uf1, 2>{get<0>(top), static_cast<uf1>(get<1>(top)+1u)},
				array<uf1, 2>{get<0>(top), static_cast<uf1>(get<1>(top)-1u)},
			};

			for(const auto& nxt : nxts){
				if(n <= nxt[0] || m <= nxt[1]) continue;

				const auto& _a = a[nxt[0]][nxt[1]];
				auto& _b = b[nxt[0]][nxt[1]];

				// DEBUG cout<<"{"<<+n<<", "<<+m<<")\ta: "<<_a<<endl;

				if(_b || _a <= x) continue;

				_b = true;
				pq.emplace(nxt[0], nxt[1], _a);
			}
		}

		DEBUG cout<<"("<<+I<<", "<<+J<<")\tc: "<<c<<"\tC: "<<C<<endl;

		C = max(c, C);
	}

	cout<<C;

	return 0;
}
//; echo """
