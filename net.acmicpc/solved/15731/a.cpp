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

	constexpr uf8 mm = 1'000'000'007;

	array<array<uf8, 5001>, 2> a;
	a[0].fill(1), a[0][0] = 0;

	char c, x;
	uf4 *p = a[0].data(), *q = a[1].data();
	for(cin>>x; cin>>c; x=c, swap(p, q)){
		DEBUG cout<<x<<' '<<c<<'\n';

		if(x=='f'){
			for(uf4 i=a[0].size(); --i;)
				q[i] = p[i-1];
		}else{
			for(uf4 i=1; i<a[0].size(); ++i)
				q[i] = (mm + q[i-1] + p[a[0].size()-1] - p[i-1]) % mm;
		}

		DEBUG{
			constexpr uf4 n = 5;
			for(uf4 i=0; i<n || (cout<<endl, 0); ++i) cout<<q[i]<<' ';
		}
	}

	cout<<p[a[0].size()-1];
	return 0;
}
AFESDJPOI
;
