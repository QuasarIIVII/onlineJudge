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

	struct S{
		u2 d: 9;
		u1 n: 4;
	};

	using A = array<array<S, 9>, 9>;
	A a;

	using T = tuple<u1, u1, u1>;
	priority_queue<T, vector<T>, greater<T>> q;

	{
		array<uf2, 9> r{0, }, c{0, }, b{0, };
		for(uf1 i=9; i--;)for(uf1 j=9; j--;){
			uf2 x;
			cin>>x;
			a[i][j].n=x;

			if(x){
				uf2 m = 1u << (x-1);
				r[i] |= m, c[j] |= m;
				b[(i/3)*3 + j/3] |= m;
			}
		}

		for(uf1 i=9; i--;)for(uf1 j=9; j--;){
			if(a[i][j].n) continue;
			uf2 m = ~(r[i] | c[j] | b[(i/3)*3 + j/3]) & 0x1FF;
			a[i][j].d = m;
			q.emplace(popcount(m), i, j);
			DEBUG cout<<"init ("<<u2(i)<<", "<<u2(j)<<") to "<<u2(popcount(m))<<'\n';
		}
	}

	A r = {0, };

	function<bool(const A&)> f = [&q, &f, &r](const A &a){
		u1 c, x, y;
		c=x=y=0xff;
		while(q.size()){
			tie(c, x, y) = q.top();
			q.pop();
			DEBUG cout<<"pop ("<<u2(x)<<", "<<u2(y)<<") with count "<<u2(c)<<'\n';
			if(!a[x][y].n) goto lb0;
		}

		if(q.empty()){
			r = a;
			return true;
		}

	lb0:
		uf2 m = a[x][y].d;
		cout<<"at ("<<u2(x)<<", "<<u2(y)<<") try options "<<bitset<9>(m)<<'\n';
		for(uf1 i=1; i<10; ++i, m>>=1){
			if(!(m&1)) continue;
			A aa = a;
			aa[x][y].n = i;

			DEBUG cout<<"try "<<u2(i)<<" at ("<<u2(x)<<", "<<u2(y)<<")\n";
			DEBUG for(uf1 ii=9; ii-- || (cout<<'\n', 0);)
				for(uf1 jj=9; jj-- || (cout<<'\n', 0);)
					cout<<u2(aa[ii][jj].n)<<' ';

			uf2 mm = ~(1u << (i-1));
			for(uf1 j=9; j--;){
				if(!aa[x][j].n){
					uf2 old = aa[x][j].d;
					aa[x][j].d &= mm;
					if(old != aa[x][j].d){
						q.emplace(popcount(aa[x][j].d), x, j);
						DEBUG cout<<"update ("<<u2(x)<<", "<<u2(j)<<") to "<<u2(aa[x][j].d)<<'\n';
					}
				}
				if(!aa[j][y].n){
					uf2 old = aa[j][y].d;
					aa[j][y].d &= mm;
					if(old != aa[j][y].d){
						q.emplace(popcount(aa[j][y].d), j, y);
						DEBUG cout<<"update ("<<u2(j)<<", "<<u2(y)<<") to "<<u2(aa[j][y].d)<<'\n';
					}
				}
				uf1 bx = (x/3)*3 + j/3, by = (j%3)*3 + y/3;
				if(!aa[bx][by].n){
					uf2 old = aa[bx][by].d;
					aa[bx][by].d &= mm;
					if(old != aa[bx][by].d){
						q.emplace(popcount(aa[bx][by].d), bx, by);
						DEBUG cout<<"update ("<<u2(bx)<<", "<<u2(by)<<") to "<<u2(aa[bx][by].d)<<'\n';
					}
				}
			}

			DEBUG for(uf1 ii=9; ii-- || (cout<<'\n', 0);)
				for(uf1 jj=9; jj-- || (cout<<'\n', 0);)
					cout<<u2(aa[ii][jj].n)<<' ';

			if(f(aa)) return true;
		}

		cout<<"false at ("<<u2(x)<<", "<<u2(y)<<")\n";
		return false;
	};

	while(!f(a)) cout<<"======== retry ========\n";

	for(uf1 i=9; i--;)
		for(uf1 j=9; j-- || (cout<<'\n', 0);)
			cout<<u2(r[i][j].n)<<' ';

	return 0;
}
//; echo """



