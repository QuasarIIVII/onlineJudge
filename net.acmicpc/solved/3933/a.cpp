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
#define AFESDJPOI asm("")
//$(pwd); cat <<AFESDJPOI

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

	auto a = []{
		array<array<uf4, 1<<15>, 5> a{};
		volatile uf4 _1 = 1;
		a[0][0] = _1;
		for(uf4 i=1; i*i<a[0].size(); ++i){
			const uf4 ii=i*i;
			for(uf4 j=ii; j<a[0].size(); ++j)for(uf1 k=a.size(); --k;)
				a[k][j] += a[k-1][j-ii];
		}

		for(uf4 i=a[0].size(); --i;)
			for(uf4 j=a.size(); --j;)
				a[0][i] += a[j][i];
		return a[0];
	}();

	
	for(uf4 n;;){
		cin>>n;
		if(!n) break;
		cout<<a[n]<<'\n';
	}
	return 0;
}
AFESDJPOI
;
