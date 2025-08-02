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

	uf2 n, m;
	cin>>n>>m;

	array<string, 1'000> a;
	array<array<uf1, 1'000>, 1'000> d = {0,  };

	using A = const array<uf2, 2>;
	queue<pair<A, bool>> q;
	uf4 y = 0;

	for(uf2 i=n; i--;){
		cin>>a[i];
		for(uf2 j=m; j--;){
			switch(a[i][j]){
			case '@':
				q.emplace(A{i, j}, true);
				a[i][j] = '.';
				break;
			case '*':
				d[i][j] = 1;
				++y;
				break;
			case '#':
				d[i][j] = 2;
				++y;
				break;
			}
		}
	}

	const uf4 x = y;

	const auto f = [&](const uf2 x, const uf2 y){
		return x < n && y < m;
	};

	// auto g = [&](const uf2 x, const uf2 y){
	// 	return f(x, y) && a[x][y] != '|';
	// };

	for(; q.size(); q.pop()){
		const auto &cur = q.front();
		DEBUG cout<<cur.first[0]<<' '<<cur.first[1]<<' '<<cur.second<<endl;
		if(A nxt = {uf2(cur.first[0]+1u), cur.first[1]}; f(nxt[0], nxt[1])){
			switch(a[nxt[0]][nxt[1]]){
			case '.':
				break;
			case '|':
				goto lb0;
			case '*':case '#':
				if(!--d[nxt[0]][nxt[1]]){
					a[nxt[0]][nxt[1]] = '.';
					--y;
					q.emplace(nxt, false);
				}
				break;
			}

			if(A nxt = {uf2(cur.first[0]+2u), cur.first[1]}; cur.second && f(nxt[0], nxt[1])){
				switch(a[nxt[0]][nxt[1]]){
				case '.':
					break;
				case '|':
					goto lb0;
				case '*':case '#':
					if(!--d[nxt[0]][nxt[1]]){
						a[nxt[0]][nxt[1]] = '.';
						--y;
						q.emplace(nxt, false);
					}
					break;
				}
			}
			lb0:
		}
		if(A nxt = {uf2(cur.first[0]-1u), cur.first[1]}; f(nxt[0], nxt[1])){
			switch(a[nxt[0]][nxt[1]]){
			case '.':
				break;
			case '|':
				goto lb1;
			case '*':case '#':
				if(!--d[nxt[0]][nxt[1]]){
					a[nxt[0]][nxt[1]] = '.';
					--y;
					q.emplace(nxt, false);
				}
				break;
			}

			if(A nxt = {uf2(cur.first[0]-2u), cur.first[1]}; cur.second && f(nxt[0], nxt[1])){
				switch(a[nxt[0]][nxt[1]]){
				case '.':
					break;
				case '|':
					goto lb1;
				case '*':case '#':
					if(!--d[nxt[0]][nxt[1]]){
						a[nxt[0]][nxt[1]] = '.';
						--y;
						q.emplace(nxt, false);
					}
					break;
				}
			}
			lb1:
		}
		if(A nxt = {cur.first[0], uf2(cur.first[1]+1u)}; f(nxt[0], nxt[1])){
			switch(a[nxt[0]][nxt[1]]){
			case '.':
				break;
			case '|':
				goto lb2;
			case '*':case '#':
				if(!--d[nxt[0]][nxt[1]]){
					a[nxt[0]][nxt[1]] = '.';
					--y;
					q.emplace(nxt, false);
				}
				break;
			}

			if(A nxt = {cur.first[0], uf2(cur.first[1]+2u)}; cur.second && f(nxt[0], nxt[1])){
				switch(a[nxt[0]][nxt[1]]){
				case '.':
					break;
				case '|':
					goto lb2;
				case '*':case '#':
					if(!--d[nxt[0]][nxt[1]]){
						a[nxt[0]][nxt[1]] = '.';
						--y;
						q.emplace(nxt, false);
					}
					break;
				}
			}
			lb2:
		}
		if(A nxt = {cur.first[0], uf2(cur.first[1]-1u)}; f(nxt[0], nxt[1])){
			switch(a[nxt[0]][nxt[1]]){
			case '.':
				break;
			case '|':
				goto lb3;
			case '*':case '#':
				if(!--d[nxt[0]][nxt[1]]){
					a[nxt[0]][nxt[1]] = '.';
					--y;
					q.emplace(nxt, false);
				}
				break;
			}

			if(A nxt = {cur.first[0], uf2(cur.first[1]-2u)}; cur.second && f(nxt[0], nxt[1])){
				switch(a[nxt[0]][nxt[1]]){
				case '.':
					break;
				case '|':
					goto lb3;
				case '*':case '#':
					if(!--d[nxt[0]][nxt[1]]){
						a[nxt[0]][nxt[1]] = '.';
						--y;
						q.emplace(nxt, false);
					}
					break;
				}
			}
			lb3:
		}
	}

	cout<<x-y<<' '<<y;
	return 0;
}
//; echo """
