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

array<if8, 100> a, st{0,};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	constexpr hash<string> h;

	map<size_t, uf2> m;
	array<list<uf2>, 100> l;

	uf2 N, Q;
	if8 s, ss = 0;
	cin>>N>>s>>Q;

	while(N--){
		uf2 g, p;
		string str;
		cin>>g>>str>>p;

		m.emplace(h(str), N);
		a[N] = p;
		l[g-1].push_back(N);
	}

	while(Q--){
		uf2 q;
		cin>>q;
		switch(q){
		case 1:{
			string str;
			if8 c;
			cin>>str>>c;
			uf2 i = m[h(str)];

			if8 x = a[i]*c;
			if(s < x) break;
			s -= x, ss += x;
			st[i] += c;
			break;
		}
		case 2:{
			string str;
			if8 c;
			cin>>str>>c;
			uf2 i = m[h(str)];

			if(st[i] < c) c = st[i];
			if8 x = a[i]*c;
			s += x, ss -= x;
			st[i] -= c;
			break;
		}
		case 3:{
			string str;
			if8 c;
			cin>>str>>c;
			uf2 i = m[h(str)];

			a[i] += c;
			ss += c*st[i];
			break;
		}
		case 4:{
			uf2 g;
			if8 c;
			cin>>g>>c;

			for(auto i : l[g-1]){
				a[i] += c;
				ss += c*st[i];
			}
			break;
		}
		case 5:{
			uf2 g;
			if2 e;
			cin>>g>>e;

			for(auto i : l[g-1]){
				if8 o = a[i];
				(a[i] *= 100+e) /= 100;
				a[i] -= a[i] % 10;
				ss += (a[i]-o)*st[i];
			}
			break;
		}
		case 6:{
			cout<<s<<'\n';
			break;
		}
		case 7:{
			cout<<s + ss<<'\n';
			break;
		}
		}
	}
	return 0;
}
//; echo """
