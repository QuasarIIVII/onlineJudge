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

	uf4 N;
	cin>>N;
	vector<string> v(0);

	while(N--){
		uf4 r, c;
		cin>>r>>c;

		if(r<4 || c<4){
			cout<<"0\n";
			continue;
		}

		v.resize(r);
		for(auto& s : v)
			cin>>s;

		uf4 cnt = 0;
		for(uf4 i=r; i--;)for(uf4 j=c-3; j--;){
			if(v[i][j+0] == 'w'
			&& v[i][j+1] == 'o'
			&& v[i][j+2] == 'r'
			&& v[i][j+3] == 'd'
			) ++cnt;

			if(v[i][j+0] == 'd'
			&& v[i][j+1] == 'r'
			&& v[i][j+2] == 'o'
			&& v[i][j+3] == 'w'
			) ++cnt;
		}

		for(uf4 i=r-3; i--;)for(uf4 j=c; j--;){
			if(v[i+0][j] == 'w'
			&& v[i+1][j] == 'o'
			&& v[i+2][j] == 'r'
			&& v[i+3][j] == 'd'
			) ++cnt;

			if(v[i+0][j] == 'd'
			&& v[i+1][j] == 'r'
			&& v[i+2][j] == 'o'
			&& v[i+3][j] == 'w'
			) ++cnt;

			if(3<=j){
				if(v[i+0][j-0] == 'w'
				&& v[i+1][j-1] == 'o'
				&& v[i+2][j-2] == 'r'
				&& v[i+3][j-3] == 'd'
				) ++cnt;

				if(v[i+0][j-0] == 'd'
				&& v[i+1][j-1] == 'r'
				&& v[i+2][j-2] == 'o'
				&& v[i+3][j-3] == 'w'
				) ++cnt;
			}

			if(j+3<c){
				if(v[i+0][j+0] == 'w'
				&& v[i+1][j+1] == 'o'
				&& v[i+2][j+2] == 'r'
				&& v[i+3][j+3] == 'd'
				) ++cnt;

				if(v[i+0][j+0] == 'd'
				&& v[i+1][j+1] == 'r'
				&& v[i+2][j+2] == 'o'
				&& v[i+3][j+3] == 'w'
				) ++cnt;
			}
		}

		cout<<cnt<<'\n';
	}

	return 0;
}
//; echo """
