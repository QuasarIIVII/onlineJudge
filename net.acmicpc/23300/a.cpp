//; echo ""
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

	uf2 n, Q;
	cin>>n>>Q;

	array<uf2, 2000> sta, stb;
	uf2 pa=0, pb=0;
	uf2 cur=-1;

	while(Q--){
		string s;
		cin>>s;

		switch(s[0]){
		default: __builtin_unreachable();
		case 'B':
			if(!pa) break;
			stb[pb++] = cur;
			cur = sta[--pa];
			break;
		case 'F':
			if(!pb) break;
			sta[pa++] = cur;
			cur = stb[--pb];
			break;
		case 'A':
			pb = 0;
			if(cur != uf2(-1))
				sta[pa++] = cur;
			cin>>cur;
			break;
		case 'C':{
			if(!pa) break;
			const uf2 tpa = pa;

			pa = 1;
			for(uf2 i=1; i<tpa; ++i){
				if(sta[i] != sta[pa-1])
					sta[pa++] = sta[i];
			}
			break;
		}
		}
	}

	cout<<cur<<'\n';
	if(pa){
		for(uf2 i=pa; i--;)cout<<sta[i]<<' ';
		cout<<'\n';
	}
	else cout<<"-1\n";
	if(pb){
		for(uf2 i=0; i<pb; ++i)cout<<stb[i]<<' ';
		cout<<'\n';
	}
	else cout<<"-1\n";
	return 0;
}
//; echo """
