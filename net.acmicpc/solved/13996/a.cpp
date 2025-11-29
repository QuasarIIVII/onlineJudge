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

constexpr size_t h(const string_view s){
	size_t r = 0;
	for(char c : s)
		r = rotl(r, 13) | rotr(static_cast<unsigned char>(c), 7);
	return r;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	string s;
	// true: x <= n, n >= x
	// false: x >= n, n <= x
	pair<uf2, bool> p(0, false);
	bitset<65536> b;
	constexpr bitset<65536> c = [] consteval {
		bitset<65536> c;
		return ~c;
	}();
	bitset<65536> bb = c;

	void *lbx = &&lb0;

	while(cin>>s){
		switch(h(s)){
		case h("x"):
			p.second = true;
			break;
		case h("<="):
			break;
		case h(">="):
			p.second = !p.second;
			break;
		case h("&&"):
			if(p.second)
				bb &= c >> (65535-p.first);
			else
				bb &= c << p.first;
			p = {0, false};
			break;
	lb2:
		case h("||"):
			if(p.second)
				b |= bb & c >> (65535-p.first);
			else
				b |= bb & c << p.first;
			p = {0, false};
			bb = c;
			goto *lbx;
		default:
			p.first = stoi(s) + 32768;
		}
	lb0:
	}

	lbx = &&lb1;
	goto lb2;
lb1:
	
	if(b.none()){
		cout<<"false";
		return 0;
	}
	if(b.all()){
		cout<<"true";
		return 0;
	}

	bool f = false;
	for(if4 i=0, j; i<65536;){
		for(j=i; j<65536 && b.test(j); ++j);
		if(i==j){
			++i;
			continue;
		}

		if(f) cout<<" ||\n";
		f = true;

		if(!i)
			cout<<"x <= "<<j-32769;
		else if(j==65536)
			cout<<"x >= "<<i-32768;
		else
			cout<<"x >= "<<i-32768<<" && x <= "<<j-32769;

		i = j;
	}
	return 0;
}
//; echo """
