//; echo """
#include<iostream>
#include<iomanip>
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
//; echo """

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

	using T = tuple<string, uf4, uf4>;
	auto cmp = [](const T &a, const T &b){
		if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
		if(get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
		return get<0>(a) > get<0>(b);
	};
	priority_queue<T, vector<T>, decltype(cmp)> pq(cmp);

	for(;;){
		string s;
		uf4 a;
		f8 b;
		if(!(cin>>s>>a>>b)) break;
		pq.emplace(s, static_cast<uf4>((b + numeric_limits<f8>::epsilon())*100)*a, a);
	}

	for(; pq.size(); pq.pop()){
		const auto &p = pq.top();
		cout<<'$'<<get<1>(p)/100<<'.'<<setw(2)<<setfill('0')<<get<1>(p)%100<<" - "<<get<0>(p)<<'/'<<get<2>(p)<<'\n';
	}
	return 0;
}
//; echo """
