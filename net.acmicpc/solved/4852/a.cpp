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

	for(uf4 T=0; ; ++T){
		string s0, s1;
		constexpr hash<string> h;
		array<size_t, 200> a;
		unordered_map<size_t, tuple<uf1, string, size_t>> m;
		uf1 sz = 0;

		while(true){
			cin>>s0;
			if(s0[0]=='#'){
				if(!sz) return 0;
				break;
			}
			cin>>s1;

			size_t h0=h(s0), h1=h(s1);
			m.emplace(h0, tuple{sz, s0, h1});
			a[sz++]=h0;
		}

		cout<<"Party number "<<T+1<<'\n';

		bitset<200> b;
		for(uf4 i=0; i<sz; ++i){
			if(b.test(i)) continue;
			for(size_t j=a[i]; ;){
				const auto &[idx, s, hh]=m[j];
				if(b.test(idx)){
					cout<<s<<".\n";
					DEBUG cout<<flush;
					break;
				}
				cout<<s<<" to ";
				b.set(idx);
				j=hh;
			}
		}

		cout<<'\n';
	}
	return 0;
}
//; echo """
