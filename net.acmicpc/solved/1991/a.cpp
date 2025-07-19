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

void f0(const array<pair<uf1, uf1>, 27>& a, uf1 p){
	cout<<char(p+0x40u);
	if(a[p].first) f0(a, a[p].first);
	if(a[p].second) f0(a, a[p].second);
}
void f1(const array<pair<uf1, uf1>, 27>& a, uf1 p){
	if(a[p].first) f1(a, a[p].first);
	cout<<char(p+0x40u);
	if(a[p].second) f1(a, a[p].second);
}
void f2(const array<pair<uf1, uf1>, 27>& a, uf1 p){
	if(a[p].first) f2(a, a[p].first);
	if(a[p].second) f2(a, a[p].second);
	cout<<char(p+0x40u);
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	array<pair<uf1, uf1>, 27> a;
	constexpr auto m = []() consteval {
		array<uf1, 128> m{0, };
		for(uf1 i='Z'+1; i--!=0x41u;)
			m[i] = i-0x40u;
		m['.'] = 0;
		return m;
	}();

	uf2 n;
	cin>>n;

	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for(uf2 i=n; i--;){
		string s;
		getline(cin, s);
		a[m[s[0]]] = {m[s[2]], m[s[4]]};
	}

	f0(a, 1);
	cout<<'\n';
	f1(a, 1);
	cout<<'\n';
	f2(a, 1);

	return 0;
}
//; echo """
