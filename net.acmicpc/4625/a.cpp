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

	while(1){
		u4 n, m;
		cin>>n;
		if(!n) break;

		array<u4, 12> a;
		u4 mx = 0;
		for(u4 i=n; i--;){
			cin>>a[i];
			mx = max(mx, a[i]);
		}
		cin>>m;

		const u4 r = (mx+49)/50;
		priority_queue<u4> pq;
		{
			const u4 t = r*50;
			DEBUG cout<<r<<' '<<t<<endl;
			for(u4 i=n; i--;) pq.emplace(t - a[i] + 100'000);
		}

		u4 l = 100'000;
		while(m){
			array<u4, 4> t;
			t[0] = m;
			{
				u4 mn = 999'999;
				for(u4 i=4; --i; pq.pop()) mn = min(mn, t[i] = pq.top());
				if(mn <= l) l = mn-1;
				for(u4 i=4; --i;) t[i] -= l;
			}

			DEBUG{
				cout<<m<<' '<<l<<' ';
				for(u4 i=4; --i;) cout<<t[i]<<' ';
				cout<<endl;
			}

			const auto mn = *min_element(t.begin(), t.end());
			m -= mn;
			for(u4 i=4; --i;)
				pq.emplace(t[i] - mn + l);
		}

		cout<<r + (100'049-l)/50<<'\n';
	}
	return 0;
}
AFESDJPOI
;

// 50 50 50 50 50 +
// 0 0 0 50 50
//
// 100 100 50 50 50 +
// 50 50 0 50 50
//
// 50 50 50 50 0
// 0 0 0 50 0
//
// 100 50 50 50 50 +
// 50 0 0 50 50 
//
// 50 50 50 0 0
// 0 0 0 0 0
//
// 50 50 50 50 50 +
// 25 25 25 50 50
// 25 25 0 25 25
// 25 0 0 0 0
