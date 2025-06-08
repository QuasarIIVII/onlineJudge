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

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 T;
	cin>>T;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	while(T--){
		string s;
		getline(cin, s);
		size_t sc = s.find_first_of(',');
		DEBUG cout<<s.substr(0, sc)<<' '<<s.substr(sc+1)<<'\n';
		cout<<s.substr(0, sc)<<" -";
		int n = stoi(s.substr(sc+1));
		array<int, 4> a;

		a[0] = n%60, n /= 60;
		a[1] = n%24, n /= 24;
		a[2] = n%365, n /= 365;
		a[3] = n;

		if(a[3])cout<<' '<<a[3]<<" year(s)";
		if(a[2])cout<<' '<<a[2]<<" day(s)";
		if(a[1])cout<<' '<<a[1]<<" hour(s)";
		if(a[0])cout<<' '<<a[0]<<" minute(s)";
		cout<<'\n';
	}
	return 0;
}
//; echo """
