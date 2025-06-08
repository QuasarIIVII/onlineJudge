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

	uf4 x, y;
	cin>>x>>y;

	array<array<uf4, 2>, 1'000'001> a;
	queue<uf4> q;

	a.fill({numeric_limits<uf4>::max(), numeric_limits<uf4>::max()});

	a[x][0] = 0;
	q.push(x);

	while(q.size()){
		uf4 n, f;
		{
			uf4 _ = q.front();
			n = _&0x00ff'ffff;
			f = _>>24 & 1;
			q.pop();
		}

		//DEBUG cout<<"n: "<<n<<", a[n]: "<<a[n]<<endl;

		for(uf4 m : array<uf4, 2>{n+1, n*2}){
			if(1'000'000 < m || a[m][f] <= a[n][f]+1) continue;
			//DEBUG cout<<"\tm: "<<m<<", a[m]: "<<a[m]<<endl;

			a[m][f] = a[n][f] + 1;
			q.push(m | f<<24);
		}

		if(f) continue;

		const uf4 m = n*10;
		if(1'000'000 < m || a[m][1] <= a[n][0]+1) continue;
		//DEBUG cout<<"\tm: "<<mi<<", a[m]: "<<a[m]<<endl;
		a[m][1] = a[n][0] + 1;
		q.push(m | 1<<24);
	}

	DEBUG{
		cout<<a[y][0]<<endl;
		cout<<a[y][1]<<endl;
	}

	cout<<min(a[y][0], a[y][1]);
	return 0;
}
// 31537 742865
//; echo """
