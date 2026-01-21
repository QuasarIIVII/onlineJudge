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

	uf4 pin = 0;
	array<char, 100'000*21+64> in;
	in[syscall(0, 0, in.data(), in.size())] = 0;

	while(in[pin++]&0x30);

	array<array<list<u4>, 26>, 26> b{};

	while(in[pin]){
		const u4 ss = pin;
		const char s = in[pin] - 0x61;
		while(in[pin++]&0x60);
		in[pin-1] = 0;
		const char e = in[pin-2] - 0x61;

		b[s][e].emplace_back(ss);
	}

	DEBUG for(uf4 i=0; i<26; ++i)for(uf4 j=0; j<26; ++j){
		if(!b[i][j].size()) continue;
		cout<<char(i+0x61)<<char(j+0x61)<<": "<<b[i][j].size()<<'\n';
		for(const u4& p:b[i][j]) cout<<(in.data()+p)<<' ';
		cout<<'\n';
	}
	return 0;
}
AFESDJPOI
;
