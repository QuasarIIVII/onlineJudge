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

	string s0, s1;
	cin>>s0>>s1;

	constexpr auto m = []() constexpr{
		array<uf1, 128> m;
		m['W'] = 8;
		m['S'] = 2;
		m['A'] = 4;
		m['D'] = 6;
		for(uf1 i=0x31; i<0x3a; ++i)
			m[i] = i-0x30;
		return m;
	}();
	constexpr auto rm = []() constexpr{
		array<uf1, 10> rm{0,};
		rm[8] = 2;
		rm[2] = 8;
		rm[4] = 6;
		rm[6] = 4;
		rm[7] = 3;
		rm[3] = 7;
		rm[1] = 9;
		rm[9] = 1;
		return rm;
	}();

	array<uf1, 11> a;
	array<uf1, 20000> b;

	s0+="---";

	uf1 p=0;
	for(uf1 i=0; i<s0.size()-3; ++p){
		switch(s0[i]){
		case 'W':case 'S':case 'A':case 'D':
			a[p] = m[s0[i]];
			if(s0[i+1] == '!'){
				a[p] = rm[a[p]];
				i+=2;
				break;
			}
			++i;
			break;

		case 'R':
			a[p] = s0[i+1] == 'U' ? 9 : 3;
			if(s0[i+2] == '!'){
				a[p] = rm[a[p]];
				i+=3;
				break;
			}
			i+=2;
			break;

		case 'L':
			a[p] = s0[i+1] == 'U' ? 7 : 1;
			if(s0[i+2] == '!'){
				a[p] = rm[a[p]];
				i+=3;
				break;
			}
			i+=2;
			break;
		}
	}

	for(uf2 i=0; i<s1.size(); ++i)
		b[i] = m[s1[i]];

	DEBUG{
		for(uf1 i=0; i<p; ++i)
			cout<<static_cast<uf2>(a[i])<<' ';
		cout<<endl;

		for(uf2 i=0; i<s1.size(); ++i)
			cout<<static_cast<uf2>(b[i])<<' ';
		cout<<endl;
	}

	uf2 x=0, y=0;
	for(; y<s1.size(); ++y){
		if(a[x] == b[y])
			x = x == p ? 0 : x+1;
		else x = 0;
	}
	cout<<(x == p ? "Yes" : "No");

	return 0;
}
//; echo """
