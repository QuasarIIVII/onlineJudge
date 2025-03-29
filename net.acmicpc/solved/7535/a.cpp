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

class CQ{
	uf4 p, q;
	array<uf2, 2048*2048> data;

public:
	CQ():p(0), q(0){}

	void push(uf4 x){
		data[q++]=x;
		q &= 2048*2048-1;
	}
	uf4 pop(){
		uf4 ret=data[p++];
		p &= 2048*2048-1;
		return ret;
	}
	uf4 front(){
		return data[p];
	}
	bool empty(){
		return p==q;
	}
	void clear(){
		p=q=0;
	}
};

array<array<uf1, 2048>, 2001> a;
CQ q;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 N;
	cin>>N;

	for(uf4 J=1; J<=N; ++J){
		uf4 n, m;
		cin>>n>>m;

		q.clear();
		memset(a.data(), 0, sizeof(a));

		for(uf4 i=m; i--;){
			uf4 x, y;
			cin>>x>>y;
			a[x][y]=a[y][x]=1;
		}

		bool flag=true;
		for(uf4 I=n; I && flag; --I){
			if(a[0][I]) continue;

			a[0][I]=1;
			q.push(I);
			DEBUG cout<<"Run\t"<<I<<"\n";

			while(!q.empty()){
				uf4 x=q.pop();
				DEBUG cout<<"V\t"<<x<<"\n";

				for(uf4 i=1; i<n; i++){
					DEBUG cout<<"VV\t"<<i<<"\n";
					if(!a[x][i]) continue;

					if(!a[0][i]){
						a[0][i] = a[0][x] == 1 ? 2 : 1;
						q.push(i);
					}else if(a[0][i] == a[0][x]){
						cout<<"Scenario #"<<J<<":\nSuspicious bugs found!\n";
						flag=false;
						q.clear();
						break;
					}
				}
			}
		}
		if(flag)
			cout<<"Scenario #"<<J<<":\nNo suspicious bugs found!\n";
		if(J<N)
			cout<<"\n";
	}
	return 0;
}

