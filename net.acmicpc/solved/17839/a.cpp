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

	u4 n;
	cin>>n;

	constexpr hash<string> h;
	unordered_map<size_t, string> m0;
	unordered_map<size_t, vector<size_t>> me;

	for(u4 i=n; i--;){
		char sa[16], sb[16], st[4];
		cin>>sa>>st>>sb;
		const size_t ha=h(sa), hb=h(sb);
		if(!m0.contains(ha)) m0.emplace(ha, sa);
		if(!m0.contains(hb)) m0.emplace(hb, sb);
		me[ha].emplace_back(hb);
	}

	unordered_set<size_t> v;
	queue<size_t> q;
	q.emplace(h("Baba"));
	for(; q.size(); q.pop()){
		const size_t x = q.front();
		for(const size_t y : me[x]){
			if(v.emplace(y).second)
				q.emplace(y);
		}
	}

	u4 pa=0;
	array<string_view, 100'000> a;
	for(const auto& vv : v)
		a[pa++] = m0[vv];

	sort(a.begin(), a.begin()+pa);
	for(u4 i=0; i<pa; i++)
		cout<<a[i]<<'\n';

	return 0;
}
AFESDJPOI
;
