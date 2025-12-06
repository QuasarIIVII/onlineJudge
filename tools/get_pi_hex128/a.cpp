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
#include<iomanip>
#include<quadmath.h>
#define AFESDJPOI asm("nop")
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

constexpr f16 pi = bit_cast<f16>(static_cast<u16>(0x4000921fb54442d1ull)<<64 | 0x8469898cc51701b8ull);

f16 sinf16(f16 x){
	u8 q=static_cast<u8>(x/2/pi);
	x-=q*2*pi;

	const f16 xx=x*x;
	f16 s=0, a=x, b=1;
	for(uf8 i=0; i < 1<<20; a*=xx, ++i, b*=(2*i)*(2*i+1)){
		if(a/b == 0
		|| ( b == numeric_limits<f16>::infinity()
		&& a == numeric_limits<f16>::infinity())
		) break;
		if(i&1)
			s-=a/b;
		else
			s+=a/b;
	}
	return s;
}

string str(f16 x, size_t n){
	ostringstream oss;
	signbit(x) ? oss<<'-', x = -x : 0;
	oss<<static_cast<u8>(x)<<'.';
	x -= static_cast<u8>(x);

	for(size_t i=n; i--;){
		x *= 10;
		oss<<static_cast<u8>(x);
		x -= static_cast<u8>(x);
	}
	return oss.str();
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	DEBUG for(uf4 i=32; i--;){
		f16 x = 2*pi*i / 16;
		cout.precision(36);
		cout<<str(sinf16(x), 36)<<'\n'<<sin(f8(x))<<"\n\n";
	}

	auto f = [](f16 n){
		u16 x = bit_cast<u16>(n);
		cout<<hex<<setw(16)<<setfill('0')<<static_cast<u8>(x>>64);
		cout<<hex<<setw(16)<<setfill('0')<<static_cast<u8>(x & 0xffff'ffff'ffff'ffffull);
		cout<<endl;
	};

	f(pi);
	cout<<str(sinq(pi), 36)<<endl;
	array<char, 128> buf;
	quadmath_snprintf(buf.data(), buf.size(), "%.36Qf", acosq(-1));
	cout<<buf.data()<<endl;
	f(acosq(-1));
	// 4000921fb54442d18469898cc51701b8
	//  0.000000000000000000000000000000000086
	// -0.000000000000000000000000000000000033

	return 0;
}
AFESDJPOI
;

// -0.382683432365089004623115442882408388
// -0.3826834323650897717284599840303988667613445624856270414338006356275460339
// -0.382683432365089771728459984030404034
// ...382683432365089771728459984030398841
