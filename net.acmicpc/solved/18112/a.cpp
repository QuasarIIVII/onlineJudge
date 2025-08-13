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
#include<climits>
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

inline u2 f(u2 x){
	u2 y;
	asm(
		"bsr %1, %0"
		:"=g"(y)
		:"g"(x)
	);
	return y;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	string s0, s1;
	cin>>s0>>s1;

	uf2 n=0, m=0;

	for(const char c : s0)
		n = n<<1 | c-0x30;

	for(const char c : s1)
		m = m<<1 | c-0x30;

	array<uf2, 1024> a;
	a.fill(numeric_limits<uf2>::max());
	a[n] = 0;

	queue<uf2> q;
	q.push(n);

	vector<uf2> v;
	v.reserve(16);

	for(; q.size(); q.pop(), v.clear()){
		const uf2 cur = q.front();

		if(cur)
			for(uf2 i=f(cur); i--;) v.push_back(cur ^ uf2(1)<<i);
		v.push_back(cur-uf2(1));
		v.push_back(cur+uf2(1));

		const uf2 cv = a[cur] + 1;

		for(const uf2 nxt : v){
			if(1024 <= nxt) continue;
			if(a[nxt] <= cv) continue;

			a[nxt] = cv;
			q.push(nxt);
		}
	}

	cout<<a[m];
	return 0;
}
//; echo """
