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

	auto b = []{
		auto a = []{
			bitset<100'002> a;
			a.set(1);
			for(uf4 i=2; i<a.size(); ++i){
				if(a.test(i)) continue;
				for(uf4 j=i*2; j<a.size(); j+=i)
					a.set(j);
			}
			return a;
		}();

		DEBUG{
			for(uf4 i=0; i<100; ++i)
				if(!a.test(i)) cout<<i<<' ';
			cout<<'\n';
		}

		array<uf4, 100'001> b;
		b[0] = 0;
		b[1] = 1;
		for(uf4 i=2; i<b.size(); ++i){
			if(a.test(i+1)){
				b[i] = b[i-1];
				continue;
			}

			uf4 p = i, q = 0, d = 1;
			while(1){
				q += p%10 * d, d *= 10;
				p /= 10;
				if(!p) break;
				if(a.test(p*q+1)) break;
			}
			if(!p) b[i] = b[i-1] + 1;
			else b[i] = b[i-1];
		}

		return b;
	}();

	uf4 T;
	for(cin>>T; T--;){
		uf4 n;
		cin>>n;
		cout<<b[n]<<'\n';
	}
	return 0;
}
AFESDJPOI
;
