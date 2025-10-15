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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n, m;
	cin>>n>>m;

	uf1 pa = 0, pb0 = 0, pb1 = 0;
	array<uf1, 15> a, b0, b1;

	for(uf2 i=0; i<n; ++i){
		string s;
		cin>>s;
		if(s[0] == '1')
			a[pa++] = i;
	}

	{
		uf1 *_pb0 = &pb0, *_pb1 = &pb1;
		auto *_b0 = &b0, *_b1 = &b1;
		for(uf2 i=0; m--;){
			uf2 x;
			cin>>x;
			while(x--)
				_b0->operator[]((*_pb0)++) = i++;
			swap(_b0, _b1);
			swap(_pb0, _pb1);
		}
	}

	DEBUG{
		for(uf1 i=0; i<pa || (cout<<endl, 0); ++i) cout<<uf2(a[i])<<' ';
		for(uf1 i=0; i<pb0 || (cout<<endl, 0); ++i) cout<<uf2(b0[i])<<' ';
		for(uf1 i=0; i<pb1 || (cout<<endl, 0); ++i) cout<<uf2(b1[i])<<' ';
	}

	constexpr auto f = [](const array<uf1, 15> &a, const array<uf1, 15> &b, uf1 n){
		constexpr auto diff = [](uf1 a, uf1 b){ return a>b ? a-b : b-a; };
		uf1 r = 0;
		for(uf1 i=0; i<n; ++i) r += diff(a[i], b[i]);
		return r;
	};

	uf1 r0 = -1, r1 = -1;
	if(pa == pb0) r0 = f(a, b0, pa);
	if(pa == pb1) r1 = f(a, b1, pa);
	cout<<static_cast<uf2>(min(r0, r1));

	return 0;
}
//; echo """
