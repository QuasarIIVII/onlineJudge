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
#include<numeric>
#include<cmath>
#include<cstring>

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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

array<uf4, 20> aa = {0,};

template<typename T> requires
	std::is_convertible_v<T, unsigned int>
	|| std::is_convertible_v<T, unsigned long>
	|| std::is_convertible_v<T, unsigned long long>
inline auto bsr(T x){
	if constexpr (std::is_convertible_v<T, unsigned int>)
		return (sizeof(unsigned int)*8-1)-__builtin_clz(x);
	else if constexpr (std::is_convertible_v<T, unsigned long>)
		return (sizeof(unsigned long)*8-1)-__builtin_clzl(x);
	else if constexpr (std::is_convertible_v<T, unsigned long long>)
		return (sizeof(unsigned long long)*8-1)-__builtin_clzll(x);
	else 0;
}

constexpr auto uf4_mx = numeric_limits<uf4>::max();

bool f(uf4 a, uf4 b, uf4 c){
	if(a==0 || b==0 || c==0) return true;

	auto sz = bsr(min({a, b, c}));
	for(; !aa[sz]; --sz)
		if(!sz) return false;

	--aa[sz];
	sz = 1<<sz;

	uf4 A = a-sz, B = b-sz, C = c-sz;
	if(!f(A, sz, sz)) return false;
	if(!f(sz, B, sz)) return false;
	if(!f(A, B, sz)) return false;
	if(!f(sz, sz, C)) return false;
	if(!f(A, sz, C)) return false;
	if(!f(sz, B, C)) return false;
	if(!f(A, B, C)) return false;
	return true;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 a, b, c, tot;

	{
		uf4 n, p, q;

		cin>>a>>b>>c>>n;

		for(; n-- && (cin>>p>>q, 1) ;aa[p]=q);
		tot = accumulate(aa.begin(), aa.end(), 0);
	}

	if(f(a, b, c))
		cout<<tot-accumulate(aa.begin(), aa.end(), 0);
	else
		cout<<-1;

	return 0;
}

