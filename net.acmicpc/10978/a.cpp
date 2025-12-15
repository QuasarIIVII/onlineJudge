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

	const auto a = []{
		array<uf8, 20> a{};
		array<array<uf8, 2>, 20> aa;
		aa.fill({numeric_limits<uf8>::max(), numeric_limits<uf8>::max()});
		aa[0][0] = aa[0][1] = 0;
		aa[1][0] = 1, aa[1][1] = 0;

		function<uf8(uf4 b, uf1)> f = [&aa, &f](uf4 b, uf1 d){
			uf8 &r = aa[d][b>>d & 1];

			if(r+1) return r;

			r = 0;
			for(uf1 i=aa.size(); i--;){
				if(i == d) continue;
				if(b>>i & 1) continue;
				r += f(b | 1u<<i, d-1);
			}

			DEBUG cout<<"f("<<bitset<20>(b)<<", "<<(uf4)d<<") = "<<r<<'\n';
			return r;
		};

		f(0, 19);

		for(uf1 i=a.size(); i--;){
			uf8 x = aa[i][0]+1 ? aa[i][0] : 0;
			uf8 y = aa[i][1]+1 ? aa[i][1] : 0;
			a[i] = x + y;
		}
		return a;
	}();

	DEBUG for(uf4 i=0; i<a.size(); ++i)
		cout<<i<<" = "<<a[i]<<'\n';

	uf4 T;
	cin>>T;
	while(T--){
		uf4 n;
		cin>>n;
		cout<<a[n-1]<<'\n';
	}

	return 0;
}
AFESDJPOI
;
