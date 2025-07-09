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
#include<iomanip>
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

if8 gcd(if8 a, if8 b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n;
	string ss;

	cin>>n>>ss;

	const auto a = [&](){
		array<if8, 26> a;
		for(uf2 i=0; i<n; ++i)
			cin>>a[i];
		return a;
	}();

	stack<pair<if8, if8>> s;
	for(const char& c : ss){
		if(0x40 < c && c < 0x5B)
			s.emplace(a[c - 0x41], 1);
		else switch(c){
			case '+': {
				auto [a0, a1] = s.top(); s.pop();
				auto [b0, b1] = s.top(); s.pop();
				DEBUG cout<<" + "<<a0<<'/'<<a1<<' '<<b0<<'/'<<b1<<'\n';
				const if8 g = gcd(a1, b1);
				const if8 lcm = a1 / g * b1;
				s.push({
					a0 * (lcm / a1) + b0 * (lcm / b1),
					lcm
				});
				break;
			}
			case '-': {
				auto [b0, b1] = s.top(); s.pop();
				auto [a0, a1] = s.top(); s.pop();
				DEBUG cout<<" - "<<a0<<'/'<<a1<<' '<<b0<<'/'<<b1<<'\n';
				const if8 g = gcd(a1, b1);
				const if8 lcm = a1 / g * b1;
				s.push({
					a0 * (lcm / a1) - b0 * (lcm / b1),
					lcm
				});
				break;
			}
			case '*': {
				auto [a0, a1] = s.top(); s.pop();
				auto [b0, b1] = s.top(); s.pop();
				DEBUG cout<<" * "<<a0<<'/'<<a1<<' '<<b0<<'/'<<b1<<'\n';
				s.push({
					a0 * b0,
					a1 * b1
				});
				break;
			}
			case '/': {
				auto [b0, b1] = s.top(); s.pop();
				auto [a0, a1] = s.top(); s.pop();
				DEBUG cout<<" / "<<a0<<'/'<<a1<<' '<<b0<<'/'<<b1<<'\n';
				s.push({
					a0 * b1,
					a1 * b0
				});
				break;
			}
		}
	}
	auto [a0, a1] = s.top();
	s.pop();
	cout<<setprecision(2)<<fixed<<static_cast<double>(a0) / a1;
	return 0;
}
//; echo """
