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

class C{
	char c;
	C *l, *r;

public:
	template<class It0, class It1>
	requires is_base_of_v<forward_iterator_tag, typename It0::iterator_category>
	&& is_base_of_v<random_access_iterator_tag, typename It1::iterator_category>
	&& is_same_v<typename It0::value_type, char>
	&& is_same_v<typename It1::value_type, char>
	C(It0 i0s, It0 i0e, It1 i1s, It1 i1e, array<int8_t, 0x60> *_t=nullptr)
	:c(*i0s), l(nullptr), r(nullptr)
	{
		if(!_t){
			_t=new array<int8_t, 0x60>;
			memset(_t->data(), -1, sizeof(*_t));
			auto &t = *_t;
			int8_t i = 0;
			for(It1 it = i1s; it != i1e; ++it)
				t[*it] = i++;
		}
		auto &t = *_t;

		It1 i1m = i1s + t[c];
		DEBUG cout<<c<<' '<<static_cast<uf2>(t[c])<<' '<<i1s[t[c]]<<' '<<*i1m<<endl;
		auto f = [](It1 s, It1 e)->uf4{
			uf4 r = 0;
			for(; s!=e; ++s)
				r|=static_cast<uf4>(1)<<(*s-0x41);
			return r;
		};

		uf4 m0 = f(i1s, i1m), m1 = f(next(i1m), i1e);
		DEBUG cout<<m0<<' '<<m1<<endl;
		if(!m0 && !m1) return;

		It0 i0m = next(i0s);
		for(uf4 mm = 0; mm != m0; mm|=static_cast<uf4>(1)<<*i0m++-0x41);
		DEBUG cout<<*i0m<<endl;

		if(m0) l = new C(next(i0s), i0m, i1s, i1m);
		if(m1) r = new C(i0m, i0e, next(i1m), i1e);
	}

	void f(){
		if(l) l->f();
		if(r) r->f();
		cout<<c;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s0, s1;
	while(cin>>s0>>s1){
		C(s0.begin(), s0.end(), s1.begin(), s1.end()).f();
		cout<<'\n';
	}
	return 0;
}

