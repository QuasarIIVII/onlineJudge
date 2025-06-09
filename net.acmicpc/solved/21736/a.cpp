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

	array<array<char, 600>, 600> a;
	uf2 h, w;
	cin>>h>>w;

	queue<array<uf4, 2>> q;

	for(uf4 i=0; i<h; ++i){
		string s;
		cin>>s;
		for(uf4 j=0; j<w; ++j){
			if((a[i][j]=s[j]) != 'I')
				continue;
			q.push({i, j});
		}
	}

	uf4 c = 0;

	for(; q.size(); q.pop()){
		auto& n = q.front();

		for(auto& m : array<array<uf4, 2>, 4>{{
			{n[0]-1, n[1]},
			{n[0]+1, n[1]},
			{n[0], n[1]-1},
			{n[0], n[1]+1},
		}}){
			if(h <= m[0] || w <= m[1])
				continue;

			switch(a[m[0]][m[1]]){
			case 'X': case 'I':
				continue;

			case 'P':
				++c;
			case 'O':
				a[m[0]][m[1]] = 'I';
				q.push(m);
				break;
			}
		}
	}

	c ? cout<<c : cout<<"TT";
	return 0;
}
//; echo """
