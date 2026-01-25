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

	uf2 n, m, k;
	cin>>n>>m>>k;

	array<char[512], 500> a;
	array<array<array<u8, 4>, 512>, 500> d;
	array<array<u1, 512>, 500> v{};
	memset(d.data(), 0xff, sizeof(d));

	using T = tuple<u2, u2, u1>;
	using TQ = tuple<u8, u2, u2, u1>;
	priority_queue<TQ, vector<TQ>, greater<TQ>> Q;

	for(uf2 i=0; i<n; ++i){
		cin>>a[i];
		for(uf2 j=m; j--;){
			if((a[i][j]&0xf0) != 0x30)
				continue;
			d[i][j][a[i][j]&0x0f] = 0;
			Q.emplace(0, i, j, a[i][j]&0x0f);
		}
	}

	const auto f = [&](T &params, const uf8 c){
		auto &[p, q, di] = params;

		while(a[p][q] == 'T'){
			const u1 vv = 1u << di;
			if(v[p][q] & vv
			&& d[p][q][di] <= c)
				return 1;
			v[p][q] |= vv;
			d[p][q][di] = c;

			const array<T, 4> nxts{
				tuple{p, q-1u, 1},
				tuple{p+1u, q, 2},
				tuple{p, q+1u, 3},
				tuple{p-1u, q, 0},
			};
			params = nxts[di];
			if(n <= get<0>(params)
			|| m <= get<1>(params))
				return 1;
		}

		return 0;
	};

	while(Q.size()){
		auto cur = Q.top();
		Q.pop();
		auto &[_, p, q, di] = cur;
		DEBUG cout<<p<<' '<<q<<' '<<+di<<' '<<d[p][q][di]<<'\n';

		// if(v[p][q] & (1u << di)) continue;
		// v[p][q] |= (1u << di);

		if(a[p][q] == 'S'){
			cout<<d[p][q][di];
			return 0;
		}

		const auto g = [&](auto nxts){
			for(auto &nxt : nxts){
				auto &[np, nq, ndi] = nxt;
				DEBUG cout<<"  "<<np<<' '<<nq<<' '<<+ndi<<'\n';
				if(n<=np || m<=nq) continue;
				if(f(nxt, d[p][q][di])) continue;
				if(v[np][nq] & (1u << ndi)
				&& d[np][nq][ndi] <= d[p][q][di]+1) continue;

				v[np][nq] |= (1u << ndi);
				d[np][nq][ndi] = d[p][q][di] + 1;
				DEBUG cout<<"  pushed\n";
				DEBUG cout<<"  "<<np<<' '<<nq<<' '<<+ndi<<'\n';
				Q.emplace(d[np][nq][ndi], np, nq, ndi);
			}
		};

		if(di & 1){
			array<T, 2> nxts{
				tuple{p-1u, q, di},
				tuple{p+1u, q, di},
			};
			g(nxts);
		}else{
			array<T, 2> nxts{
				tuple{p, q-1u, di},
				tuple{p, q+1u, di},
			};
			g(nxts);
		}

		{
			const T nxt{p, q, (di+1)&3};
			DEBUG cout<<"  "<<p<<' '<<q<<' '<<+(di+1&3)<<'\n';
			if(v[p][q] & (1u << get<2>(nxt))
			&& d[p][q][get<2>(nxt)] <= d[p][q][di]+k) continue;

			v[p][q] |= (1u << get<2>(nxt));
			d[p][q][get<2>(nxt)] = d[p][q][di] + k;
			DEBUG cout<<"  pushed\n";
			Q.emplace(d[p][q][get<2>(nxt)], p, q, get<2>(nxt));
		}
	}

	cout<<"-1";

	return 0;
}
AFESDJPOI
;
