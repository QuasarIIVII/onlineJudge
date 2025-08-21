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

	uf2 _;

	uf4 pbw=0, pfw=0;
	if4 cur = numeric_limits<if4>::max();
	array<if4, 2001> bw, fw;

	uf2 Q;
	cin>>_>>Q;
	string s;

	while(Q--){
		cin>>s;

		switch(s[0]){
		case 'B':
			if(!pbw) break;
			fw[pfw++] = cur;
			cur = bw[--pbw];
			break;
		case 'F':
			if(!pfw) break;
			bw[pbw++] = cur;
			cur = fw[--pfw];
			break;
		case 'A':
			pfw = 0;
			if(cur != numeric_limits<if4>::max())
				bw[pbw++] = cur;
			cin>>cur;
			break;
		case 'C':{
			if(pbw < 2) break;

			uf2 tsz = pbw;

			pbw = 1;
			for(uf2 i = 1; i<tsz; ++i){
				if(bw[pbw-1] == bw[i])
					continue;
				bw[pbw++] = bw[i];
			}
			break;
		}
		}
	}

	cout<<cur<<'\n';
	if(pbw) while(pbw-- || (cout<<'\n', 0)) cout<<bw[pbw]<<' ';
	else cout<<"-1\n";
	// if(pfw) for(uf2 i=0; i<pfw || (cout<<'\n', 0); ++i) cout<<fw[i]<<' ';
	if(pfw) while(pfw-- || (cout<<'\n', 0)) cout<<fw[pfw]<<' ';
	else cout<<"-1\n";
}
//; echo """
