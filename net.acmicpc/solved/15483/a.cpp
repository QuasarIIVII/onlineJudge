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
	string s0, s1;
	cin>>s0>>s1;

	array<array<uf2, 1001>, 2> a;
	for(uf2 i=0; i<a[0].size(); ++i) a[0][i] = i;

	for(uf2 i=0; i<s0.size(); ++i){
		auto &cur = a[i&1^1];
		auto &prev = a[i&1];
		cur[0] = i+1;

		for(uf2 j=0; j<s1.size(); ++j){
			if(s0[i]==s1[j])
				cur[j+1] = prev[j];
			else
				cur[j+1] = min(min(prev[j], prev[j+1]), cur[j]) + 1;
		}

		DEBUG for(uf2 j=0; j<=s1.size() || (cout<<endl, 0); ++j)
			DEBUG cout<<cur[j]<<' ';
	}

	cout<<a[s0.size()&1][s1.size()];
	return 0;
}
//; echo """
