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

	uf4 T;
	cin>>T;
	while(T--){
		uf4 n;
		cin>>n;

		vector<uf4> a(n);
		for(auto& v : a) cin>>v;
		sort(a.begin(), a.end());

		DEBUG for(uf4 i=0; i<n || (cout<<endl, 0); ++i)
			cout<<a[i]<<" ";

		uf4 m;
		cin>>m;

		uf4 mn = numeric_limits<uf4>::max();
		using It=vector<uf4>::iterator;
		const function<uf4(const uf4, const It, const uf4)> f
		= [&](const uf4 x, const It e, const uf4 c) -> uf4 {
			if(a.begin() == e) return 1u;

			It it = upper_bound(a.begin(), e, x);
			if(it == a.begin()) return 1u;
			--it;
			DEBUG cout<<"x: "<<x<<", i: "<<it-a.begin()<<", a[it]: "<<*it<<", c: "<<c<<'\n';
			if(*it == x){
				mn = min(mn, c+1);
				return 0u;
			}

			for(const uf4 v = x - *it; it != a.begin(); --it)
				f(v, it, c+1);
			return 1u;
		};

		f(m, a.end(), 0);
		if(mn == numeric_limits<uf4>::max()) cout<<"Not possible\n";
		else cout<<mn<<'\n';
	}
	return 0;
}
AFESDJPOI
;
