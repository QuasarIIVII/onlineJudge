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

	uf4 n;
	array<unordered_map<uf4, uf4>, 2501> a;
	array<uf4, 2501> r;
	r[1] = 1;
	a[1].emplace(1, 1);

	auto f = [](uf4& x){
		constexpr uf4 m = 1'000'000'007;
		if(x < m) return;
		x -= m;
		if(x < m) return;
		x -= m;
		return;
	};

	for(uf4 i=2; i<a.size(); ++i){
		uf4 tr=0;
		for(const auto& [p, q]:a[i-1]){
			a[i][p] += q;
			f(a[i][p]);
			a[i][p+1] += q;
			f(a[i][p+1]);

			tr += 2*q;
			f(tr);
		}
		r[i] = tr;
	}

	uf4 T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n&1){
			cout<<"0\n";
			continue;
		}

		cout<<r[n/2]<<'\n';
	}

	return 0;
}
//; echo """
