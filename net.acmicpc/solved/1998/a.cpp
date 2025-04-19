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
#include<variant>

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

// array<unordered_map<size_t, bool>, 8> m;
unordered_map<size_t, bool> m;

class C{
private:
	using ssss=array<size_t, 5>;
	constexpr static hash<string> hh{};

	uf1 a;
	bool z;
	array<C*, 4> c;
	size_t h;

public:
	C(array<bitset<128>,128> &b, uf2 x, uf2 y, uf2 sz)
	:z(false)
	,c{nullptr,nullptr,nullptr,nullptr}
	{
		if(sz==1){
			a=b[x][y];
			h=hh(string(
				reinterpret_cast<char*>(ssss{
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					a,
					0
				}.data()),
				sizeof(ssss)
			));
//			DEBUG cout<<"h: "<<h<<endl;
			return;
		}

		uf2 s = sz>>1;
		array<C*, 4> cc{
			new C(b, x, y, s),
			new C(b, x, y+s, s),
			new C(b, x+s, y, s),
			new C(b, x+s, y+s, s)
		};

		uf1 p=0, q=1;
		for(auto &aa:cc){
			p|=aa->a;
			q&=aa->a;
		}

		DEBUG cout<<static_cast<int>(p)<<" "<<static_cast<int>(q)<<" "<<x<<" "<<y<<" "<<sz<<endl;

		if(p==255){
			a=-1;
			c=cc;

			h=hh(string(
				reinterpret_cast<char*>(ssss{
					cc[0]->h,
					cc[1]->h,
					cc[2]->h,
					cc[3]->h,
					0
				}.data()),
				sizeof(ssss)
			));
		}else if(q){
			a=1;

			h=hh(string(
				reinterpret_cast<char*>(ssss{
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					a,
					0
				}.data()),
				sizeof(ssss)
			));
		}else if(!p){
			a=0;

			h=hh(string(
				reinterpret_cast<char*>(ssss{
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					numeric_limits<size_t>::max(),
					a,
					0
				}.data()),
				sizeof(ssss)
			));
		}else{
			a=-1;
			c=cc;

			h=hh(string(
				reinterpret_cast<char*>(ssss{
					cc[0]->h,
					cc[1]->h,
					cc[2]->h,
					cc[3]->h,
					0
				}.data()),
				sizeof(ssss)
			));
		}

//		DEBUG cout<<"h: "<<h<<endl;

		if(a==255){
			if(m.contains(h))
				z=true;
			else
				m.emplace(h, 0);
		}
	}
	~C(){
		for(auto &i:c)
			delete i;
	}
	uf2 f(){
		if(a==255){
			DEBUG cout<<"{";
			uf2 s=0;
			for(auto &aa:c)
				s+=aa->f();
			DEBUG cout<<'}'<<static_cast<if2>(a)<<' '<<s+1<<endl;
			return s+1;
		}
		DEBUG cout<<static_cast<if2>(a)<<" 1"<<endl;
		return 1;
	}
	uf2 g(){
		if(a<2) return 1;
		if(z) return 0;

		uf2 s=0;
		for(auto &aa:c)
			s+=aa->g();
		return s+1;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 n,m;
	cin>>n>>m;

	array<bitset<128>, 128> b;

	for(uf4 i=0; i<n; ++i){
		string s;
		cin>>s;
		b[i] = bitset<128>(string(s.rbegin(), s.rend()));
	}
	n = m<n ? n : m;
	for(m=1; m<n; m<<=1);

	DEBUG cout<<m<<endl;

	C c(b, 0, 0, m);
	cout<<c.f()<<' '<<c.g();
	return 0;
}

