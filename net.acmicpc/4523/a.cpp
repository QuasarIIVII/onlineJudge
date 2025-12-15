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

template<class T, size_t _N, class F>
requires is_invocable_r_v<T, F, T, T> && (0 < _N)
class ST{
	constexpr static size_t N = 1z << (numeric_limits<size_t>::digits - countl_zero(_N-1));
	const T id;
	array<T, N*2> a;
	const F f;

public:
	ST(const initializer_list<T> &il, const T &id, const F &f)
	: id(id), f(f){
		a.fill(id);
		size_t i = N;
		for(const T &v : il) a[i++] = v;
		for(size_t i=N; --i;)
			a[i] = f(a[i*2], a[i*2 + 1]);
	}

	void x(size_t p, const T &v){
		p += N;
		for(a[p] = v; p>>=1;)
			a[p] = f(a[p*2], a[p*2 + 1]);
	}

	T q(size_t l, size_t r) const {
		T rl = id, rr = id;
		for(l += N, r += N; l<r; l>>=1, r>>=1){
			if(l & 1) rl = f(rl, a[l++]);
			if(r & 1) rr = f(a[--r], rr);
		}
		return f(rl, rr);
	}
};

using TK = variant<uf1, if1, double>;
uf1 tkz(
	string_view sv,
	array<TK, 80> &tks,
	priority_queue<pair<uf1, uf1>> &ops
){
	uf1 p = 0;
	tks[p++] = uf1(0);

	bool qn = false;
	u16 n = 0;
	uf1 ne = 0;

	const auto jt = [&](){
		array<function<void(char c)>, 128> jt{}, _jt;
		jt.fill([&](char c){
			constexpr auto e10 = [] consteval {
				array<f8, 32> e10{};
				f8 a = 1;
				for(uf1 i=0; i<e10.size(); ++i, a*=10)
					e10[i] = 1/a;
				return e10;
			}();

			if(qn){
				tks[p++] = ne ? n * e10[ne-1] : n;
				n = 0, ne = 0;
				qn = false;
			}
			_jt[c](c);
		});

		for(uf1 c=10; c--;){
			jt[c+0x30] = [&qn, &n, &ne](char c){
				if(ne) ++ne;
				n = n*10 + c-0x30;
				qn = true;
			};
		}

		for(uf1 c=26; c--;)
			_jt[c+0x41] = [&p, &tks, &ops](char c){ tks[p++] = uf1(c-0x41); };

		_jt[0x2E /* . */] = [&ne](char c){ ne = 1; };
		_jt[0x2A /* * */] = [&p, &tks, &ops](char c){
			ops.push({1, p});
			tks[p++] = uf1(0x20);
		};
		_jt[0x2B /* + */] = [&p, &tks, &ops](char c){
			ops.push({0, p});
			tks[p++] = uf1(0x30);
		};
		_jt[0x2D /* - */] = [&p, &tks, &ops](char c){};
		_jt[0x28 /* ( */] = [&p, &tks, &ops](char c){};
		_jt[0x29 /* ) */] = [&p, &tks, &ops](char c){};
		_jt[0x5B /* [ */] = [&p, &tks, &ops](char c){};
		_jt[0x5D /* ] */] = [&p, &tks, &ops](char c){};
		_jt[0x20] = [](char c){};
		return jt;
	}();

	for(char c : sv){
		jt[c](c);
	}

	return p;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	DEBUG{
		constexpr auto f = [](uf4 a, uf4 b) { return a + b; };
		ST<uf4, 10, decltype(f)> st({1,2,3,4,5}, 0, f);
	}

	uf2 T;
	cin>>T;
	while(T--){
		DEBUG cout<<"TC #"<<T<<endl;
		uf4 n, m;
		cin>>n>>m;

		array<array<f8, 100>, 26> a;

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(n--){
			char s, t;
			cin>>s;
			s -= 0x41;
			cin.ignore(numeric_limits<streamsize>::max(), ' ');
			cin>>t;

			DEBUG cout<<"s: "<<(char)(s+0x41)<<" t: "<<t<<endl;

			if(t == '='){
				string expr;
				getline(cin, expr);
				DEBUG cout<<expr<<'\n';
			}else{
				uf2 x;
				for(uf4 i=0; i<m; ++i)
					cin>>x, a[s][i] = x;
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		}
		DEBUG cout<<endl;
	}
	return 0;
}
AFESDJPOI
;
