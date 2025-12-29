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

	constexpr array<uf1, 10> c{6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
	constexpr static auto e = []{
		array<uf8, 16> e;
		e[0] = 1;
		for(uf1 i=1; i<e.size(); ++i)
			e[i] = e[i-1]*10;
		return e;
	}();

	string s;
	cin>>s;
	uf8 n = stoull(s);

	auto f = [&](const uf8 x){
		uf8 r = e[s.size()] + x - n;
		if(e[s.size()] < r) r -= e[s.size()];
		return r;
	};

	auto g = [&](uf8 x){
		uf8 r = 0;
		for(uf1 i=s.size(); i--; x/=10)
			r += c[x%10];
		return r;
	};

	queue<uf8> q;
	array<pair<uf8, uf8>, 15*7+1> a;
	a.fill({
		numeric_limits<uf8>::max(),
		numeric_limits<uf8>::max()
	});

	q.emplace(n);
	a[g(n)] = {e[s.size()], n};

	for(; q.size(); q.pop()){
		const uf8 x = q.front();

		for(uf1 i=s.size(); i--;){
			uf8 xx = x - (x/e[i]%10)*e[i];
			for(uf1 j=10; j--; xx+=e[i]){
				if(xx == x) continue;

				const uf8 d = f(xx);
				const uf8 v = g(xx);

				if(a[v].first <= d) continue;
				a[v] = {d, xx};
				q.emplace(xx);
			}
		}
	}

	cout<<a[g(n)].first;

	return 0;
}
AFESDJPOI
;
