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

class C{
	C *l, *r;
	u1 a;

public:
	C(): l(nullptr), r(nullptr), a(0) {}

	~C(){
		delete l;
		delete r;
	}

	pair<C*, C*> x(const u1 a){
		if((this->a = a) & 0xf0)
			return {l=new C(), r=new C()};
		else
			return {nullptr, nullptr};
	}

	i16 f() const {
		if(a & 0xf0){
			switch(a){
				case 0x2b: return l->f() + r->f();
				case 0x2d: return l->f() - r->f();
				case 0x2a: return l->f() * r->f();
			}
		}else return a;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n, m;
	cin>>n>>m;

	C c;

	queue<C*> q;
	q.emplace(&c);

	while(n--){
		string s;
		cin>>s;

		for(const char c : s){
			if(c & 0x10){
				const auto &[r0, r1] = q.front()->x(c & 0x0f);
				q.pop();
				if(r0) q.emplace(r0);
				if(r1) q.emplace(r1);
			}else if(c != '.'){
				const auto &[r0, r1] = q.front()->x(c);
				q.pop();
				if(r0) q.emplace(r0);
				if(r1) q.emplace(r1);
			}else continue;
		}
	}

	i16 r = c.f();
	bool neg = r < 0;
	if(neg) r = -r;
	array<char, 64> s;
	uf1 ps = s.size();
	s[--ps] = 0;
	do{ s[--ps] = static_cast<char>(r%10) + 0x30; }while(r /= 10);
	if(neg) s[--ps] = '-';
	cout<<s.data()+ps;
	return 0;
}
AFESDJPOI
;
