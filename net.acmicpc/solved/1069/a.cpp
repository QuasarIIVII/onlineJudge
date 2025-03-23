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

static_assert(sizeof(unsigned long long)==sizeof(u8));
consteval u8 operator"" _u8(unsigned long long x){return static_cast<u8>(x);}
consteval u16 operator"" _u16(const char* x, size_t n){
	u16 r=0;
	for(size_t i=0; i<n; ++i)
		if(0x30<=x[i] && x[i]<=0x39)r = r*10 + x[i]-0x30;
	return r;
}

template<class T> requires is_integral_v<T> && is_unsigned_v<T>
constexpr T qSqrt(T n){
	if(n<2)return n;

	T x=n, y=x+1>>1;
	while(y<x){
		x=y;
		y= x+n / x >> 1;
	}

	return x;
}

constexpr u16 multiplier_mini="10'000'000'000'000'000"_u16;
constexpr u16 multiplier="100'000'000'000'000'000'000'000'000'000'000"_u16;

struct S0{if2 x, y;};

ostream& operator<<(ostream& os, u16 a){
	if(!a)return os<<'0';
	char s[64]={0,};
	uf1 i=63;
	for(;a;a/=10)s[--i]=static_cast<char>(a%10);
	*reinterpret_cast<u8*>(s+0x00) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x08) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x10) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x18) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x20) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x28) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x30) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x38) += 0x3030'3030'3030'3030_u8;
	s[63]=0;
	os<< s+i;
	return os;
}

struct divMultiplier_mini{
	const u16& a;
	divMultiplier_mini(const u16& a) noexcept :a(a) {}
};

ostream& operator<<(ostream& os, const divMultiplier_mini& a){
	u16 r=a.a%multiplier_mini;
	char s[24]={0,};
	for(uf1 i=23;7<i;r/=10)s[--i]=static_cast<char>(r%10);
	*reinterpret_cast<u8*>(s+0x00) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x08) += 0x3030'3030'3030'3030_u8;
	*reinterpret_cast<u8*>(s+0x10) += 0x0030'3030'3030'3030_u8;
	os<< a.a/multiplier_mini << '.' << s+7;
	return os;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	static_assert(multiplier_mini*multiplier_mini==multiplier);
	static_assert(sizeof(u16)==16);

	DEBUG cout<<divMultiplier_mini("123456789.1234567890123456"_u16)<<endl;

	S0 s;
	uf2 _d;
	u16 d;
	uf4 t;

	cin>>s.x>>s.y>>_d>>t;
	d=_d*multiplier_mini;

	u16 dist=qSqrt((s.x*s.x + s.y*s.y)*multiplier);

	DEBUG cout<<"dist : "<<divMultiplier_mini(dist)<<endl;

	DEBUG cout<<divMultiplier_mini(dist%d)<<endl;
	DEBUG cout<<divMultiplier_mini(d-dist%d)<<endl;

	u16 a;
	u16&& dist_div_d = dist/d;
	u16&& dist_mod_d = dist%d;
	DEBUG cout<<"div  : "<<divMultiplier_mini(dist_div_d*multiplier_mini)<<endl;
	DEBUG cout<<"mod  : "<<divMultiplier_mini(dist_mod_d)<<endl;
	
	if(_d<t){
		cout<<divMultiplier_mini(dist);
		return 0;
	}

	{
		u16 &&_a=(dist_mod_d + t*multiplier_mini*(dist_div_d)),
			&&_b=(d-dist_mod_d + t*multiplier_mini*(dist_div_d + 1));
		a = _a<_b ? _a : _b;
	}

	if(!dist_div_d){
		u16&& b=(t*multiplier_mini<<1);
		if(b<a)a=b;
	}else{
		u16 &&b=(t*multiplier_mini*(dist_div_d+1));
		if(b<a)a=b;
	}
	cout<<divMultiplier_mini(a);
	return 0;
}
