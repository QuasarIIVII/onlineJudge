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
#include<stdfloat>
#include<quadmath.h>
#include<cstdlib>

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
										using f4=float;		using f8=double;	using f16=__float128;
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

constexpr f16 pi = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214Q;

f16 sinf16(f16 x){
	u8 q=static_cast<u8>(x/pi);
	x-=q*pi;
	if(x<0)
		x+=pi;

	const f16 xx=x*x;
	f16 s=0, a=x, b=1;
	for(uf4 i=0; i<64; a*=xx, ++i, b*=(2*i)*(2*i+1)){
		if(i&1)
			s-=a/b;
		else
			s+=a/b;
	}
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 a, b, c;
	cin>>a>>b>>c;

	f16 p=0, q=1<<17;
	for(; q; q/=2){
		f16 m=p+q;
		f16 x=a*m + b*sinf16(m);
		if(x<=c)
			p+=q;
	}

	char buf[128];
	strfromf128(buf, sizeof(buf), "%.6f", p);
	cout<<buf;

	return 0;
}
//; echo """
