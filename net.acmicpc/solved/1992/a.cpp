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

array<bitset<64>, 64> b;

struct C{
	uf1 a;
	array<C*, 4> p;

	C(uf1 x, uf1 y, uf1 sz):p{nullptr, nullptr, nullptr, nullptr}{
		DEBUG cout<<static_cast<int>(x)<<' '<<static_cast<int>(y)<<' '<<static_cast<int>(sz)<<endl;
		/*
		 * 0 1
		 * 2 3
		 */
		constexpr static array<uf1, 4> dx{0xff, 0, 0xff, 0}, dy{0, 0, 0xff, 0xff};
		if(sz == 1){
			a = b[y][x];
			return;
		}

		uf1 tsz = sz/2, f0=0, f1=1;
		for(uf1 i=4; i--; ){
			p[i] = new C(x+(tsz&dx[i]), y+(tsz&dy[i]), tsz);
			f0 |= p[i]->a;
			f1 &= p[i]->a;
		}

		if(f0 == 0xff) a = 0xff;
		else if(!f0) a = 0;
		else if(f1) a = 1;
		else a = 0xff;
	}

	~C(){
		for(uf1 i=4; i--; )
			delete p[i];
	}

	void f(){
		if(a == 0xff){
			cout<<'(';
			for(uf1 i=0; i<4; ++i)
				p[i]->f();
			cout<<')';
		}else if(a){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n;
	cin>>n;
	for(uf2 i=0; i<n; i++){
		string s;
		cin>>s;
		b[i] = bitset<64>(s);
	}

	C c(0, 0, n);
	c.f();
	return 0;
}

