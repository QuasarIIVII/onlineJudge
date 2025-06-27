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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 T;
	cin>>T;

	for(uf4 I=0; I<T; ++I){
		const auto [n, m] = [](){
			uf4 n, m;
			cin>>n>>m;
			return make_pair(n, m);
		}();

		const auto mp = [&](){
			array<array<bool, 20>, 20> a;
			for(uf4 i=n; i--;){
				string s;
				cin>>s;
				for(uf4 j=m; j--;)
					a[i][j] = s[j]=='O';
			}
			return a;
		}();

		array<array<bool, 20>, 20> a{false, };
		queue<array<uf4, 2>> q;

		if(!mp[n-1][0])
			goto lb0;

		a[n-1][0] = true;
		q.push({n-1, 0});

		for(; q.size(); q.pop()){
			const auto& cur = q.front();
			const array<array<uf4, 2>, 4> nxts = {
				array<uf4, 2>{cur[0]-1u, cur[1]},
				array<uf4, 2>{cur[0]+1u, cur[1]},
				array<uf4, 2>{cur[0], cur[1]-1u},
				array<uf4, 2>{cur[0], cur[1]+1u},
			};

			for(const auto& nxt : nxts){
				if(n<=nxt[0] || m<=nxt[1] || a[nxt[0]][nxt[1]] || !mp[nxt[0]][nxt[1]])
					continue;
				a[nxt[0]][nxt[1]] = true;
				q.push(nxt);
			}
		}

		lb0:
		const string s = [&](){
			string s, t = "+---";
			s.reserve(m*4+4);

			for(uf4 i=m; i;){
				if(i&1) s += t;
				if(i>>=1) t += t;
			}
			s += "+\n";
			return s;
		}();

		cout<<"Case: "<<I+1<<'\n';
		for(uf4 i=n; i--; ){
			cout<<s;
			for(uf4 j=0; j<m; ++j){
				if(!mp[i][j])
					cout<<"| X ";
				else if(a[i][j])
					cout<<"| M ";
				else
					cout<<"|   ";
			}
			cout<<"|\n";
		}
		cout<<s<<(a[0][m-1] ? "Minions can cross the room \n" : "Minions cannot cross the room \n");
	}

	return 0;
}
//; echo """
