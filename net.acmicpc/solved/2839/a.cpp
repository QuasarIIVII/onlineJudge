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

	array<pair<uf4, uf4>, 5001> a{
		make_pair(0, 0),
		make_pair(numeric_limits<uf4>::max(), 0),
		make_pair(numeric_limits<uf4>::max(), 0),
		make_pair(1, 0),
		make_pair(numeric_limits<uf4>::max(), 0),
	};

	for(uf4 i=5; i<a.size(); ++i){
		pair<uf4, uf4> r0 = a[i-3], r1 = a[i-5];
		if(r0.first == numeric_limits<uf4>::max()
		&& r1.first == numeric_limits<uf4>::max()){
			a[i] = {numeric_limits<uf4>::max(), 0};
			continue;
		}

		if(r0.first + r0.second < r1.first + r1.second)
			a[i] = {r0.first + 1, r0.second};
		else
			a[i] = {r1.first, r1.second + 1};
	}

	uf2 n;
	cin>>n;
	cout<<static_cast<if4>(a[n].first + a[n].second);
	return 0;
}
//; echo """
