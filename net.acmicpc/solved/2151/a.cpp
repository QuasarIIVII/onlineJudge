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

	auto a = []() consteval {
		array<array<array<uf2, 4>, 50>, 50> a;
		decltype(a)::value_type aa;
		aa.fill({
			numeric_limits<uf2>::max(),
			numeric_limits<uf2>::max(),
			numeric_limits<uf2>::max(),
			numeric_limits<uf2>::max()
		});
		a.fill(aa);
		return a;
	}();

	uf2 n;

	cin>>n;

	array<uf1, 2> E{0, 0};
	queue<array<uf1, 3>> q;

	const auto m = [&](){
		array<array<uf1, 50>, 50> m;
		for(uf1 i=n, f=1; i--;){
			string s;
			cin>>s;

			for(uf1 j=n; j--;){
				switch(s[j]){
				case '#':
					if(f){
						a[i][j] = {0, 0, 0, 0};
						q.push({i, j, 0});
						q.push({i, j, 1});
						q.push({i, j, 2});
						q.push({i, j, 3});
						f=0;
					}else E = {i, j};
				case '.':
					m[i][j] = 0;
					break;
				case '!':
					m[i][j] = 1;
					break;
				case '*':
					m[i][j] = 2;
					break;
				}
			}
		}
		return m;
	}();

	for(vector<array<uf1, 3>> nxts; q.size(); q.pop()){
		const auto& cur = q.front();

		if(m[cur[0]][cur[1]]){
			nxts = cur[2] & 1
			? initializer_list{
				array<uf1, 3>{static_cast<uf1>(cur[0]+1u), cur[1], 0},
				array<uf1, 3>{static_cast<uf1>(cur[0]-1u), cur[1], 2},
				cur[2]==1
				? array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]+1u), 1}
				: array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]-1u), 3},
			}
			: initializer_list{
				array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]+1u), 1},
				array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]-1u), 3},
				cur[2]==0
				? array<uf1, 3>{static_cast<uf1>(cur[0]+1u), cur[1], 0}
				: array<uf1, 3>{static_cast<uf1>(cur[0]-1u), cur[1], 2},
			};
		}else{
			switch(cur[2]){
			case 0: nxts = {array<uf1, 3>{static_cast<uf1>(cur[0]+1u), cur[1], 0}}; break;
			case 2: nxts = {array<uf1, 3>{static_cast<uf1>(cur[0]-1u), cur[1], 2}}; break;
			case 1: nxts = {array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]+1u), 1}}; break;
			case 3: nxts = {array<uf1, 3>{cur[0], static_cast<uf1>(cur[1]-1u), 3}}; break;
			}
		}

		for(const auto& nxt : nxts){
			if(n <= nxt[0] || n <= nxt[1])
				continue;

			switch(m[nxt[0]][nxt[1]] | +((cur[2]&1) != (nxt[2]&1))*4){
			case 2: case 6: continue;
			case 0:
				if(a[nxt[0]][nxt[1]][nxt[2]] <= a[cur[0]][cur[1]][cur[2]])
					continue;
				a[nxt[0]][nxt[1]][nxt[2]] = a[cur[0]][cur[1]][cur[2]];
				q.push(nxt);
				break;
			case 0|4:
				if(a[nxt[0]][nxt[1]][nxt[2]] <= a[cur[0]][cur[1]][cur[2]]+1)
					continue;
				a[nxt[0]][nxt[1]][nxt[2]] = a[cur[0]][cur[1]][cur[2]]+1;
				q.push(nxt);
				break;
			case 1:
				if(a[nxt[0]][nxt[1]][nxt[2]] <= a[cur[0]][cur[1]][cur[2]]
				|| a[nxt[0]][nxt[1]][nxt[2]+2&3] <= a[cur[0]][cur[1]][cur[2]])
					continue;
				a[nxt[0]][nxt[1]][nxt[2]] = a[cur[0]][cur[1]][cur[2]];
				q.push(nxt);
				break;
			case 1|4:
				if(a[nxt[0]][nxt[1]][nxt[2]] <= a[cur[0]][cur[1]][cur[2]]+1)
					continue;
				a[nxt[0]][nxt[1]][nxt[2]] = a[cur[0]][cur[1]][cur[2]]+1;
				q.push(nxt);
				break;
			}
		}
	}

	const auto& t = a[E[0]][E[1]];
	cout<<*min_element(t.begin(), t.end());
	return 0;
}
//; echo """
/*

7
*******
!#*.!!*
.*#.!!!
.****..
!....!.
.****..
!....!!

3
#!.
!!.
*#.

2
#.
!#

*/
