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

struct S{
	uf2 a;
	uf4 r;
	f8 s;
};

template<class T, bool (*_cmp)(const T&, const T&)>
struct cmp{
	bool operator()(const T& a, const T& b) const{
		return _cmp(a, b);
	}
};

inline bool _cmp(const S& a, const S& b){
	return a.s < b.s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 T;
	cin>>T;

	for(uf2 t=1; t<=T; ++t){
		uf4 n, m;
		cin>>n>>m;

		priority_queue<
			S,
			vector<S>,
			cmp<
				S,
				_cmp
			>
		> pq0, pq1;

		for(uf2 i=n; i--;){
			uf4 r, h;
			cin>>r>>h;

			f8 a0 = static_cast<uf8>(r)*h*2 * numbers::pi;
			f8 a1 = static_cast<uf8>(r)*(r+2*h) * numbers::pi;

			pq0.emplace(i, r, a0);
			pq1.emplace(i, r, a1);
		}

		bitset<1000> b;
		uf8 r = 0;
		f8 ret = 0;

		for(uf2 i=m; i;){
			const S& t0 = pq0.top();
			const S& t1 = pq1.top();

			const f8 s0 = t0.s;
			const f8 s1 = t1.s - r*r*numbers::pi;

			if(s0 < s1){
				if(b[t1.a]){
					pq1.pop();
					continue;
				}

				r = t1.r;
				ret += s1;

				b.set(t1.a);
				DEBUG cout<<t1.a<<' '<<t1.r<<' '<<t1.s<<'\n';
				pq1.pop();
			}else{
				if(b[t0.a]){
					pq0.pop();
					continue;
				}

				ret += s0;

				b.set(t0.a);
				DEBUG cout<<t0.a<<' '<<t0.r<<' '<<t0.s<<'\n';
				pq0.pop();
			}

			--i;
		}

		cout<<"Case #"<<t<<": "<<fixed<<setprecision(7)<<ret<<'\n';
		DEBUG cout<<endl;
	}
	return 0;
}

