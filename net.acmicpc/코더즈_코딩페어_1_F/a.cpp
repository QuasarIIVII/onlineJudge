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

	ST(const array<T, _N> &arr, const T &id, const F &f)
	: id(id), f(f){
		a.fill(id);
		size_t i = N;
		for(const T &v : arr) a[i++] = v;
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

	T q(size_t p) const {
		return a[p + N];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n, q;

	constexpr auto init = []{
		array<pair<uf2, uf2>, 1'000> init{};
		for(uf2 i=init.size(); i--;)
			init[i] = {0, i+1};
		return init;
	}();

	constexpr auto f = [](const pair<uf2, uf2> &a, const pair<uf2, uf2> &b) -> pair<uf2, uf2>{
		return a.first == b.first
			? a.second < b.second ? a : b
			: a.first > b.first ? a : b;
	};

	array<ST<pair<uf2, uf2>, 1'000, decltype(f)>, 4> st{{
		{init, {0u, 2000u}, f},
		{init, {0u, 2000u}, f},
		{init, {0u, 2000u}, f},
		{init, {0u, 2000u}, f},
	}};

	cin>>n>>q;
	while(q--){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char c;
		cin>>c;
		if(c=='1'){
			uf2 x, y;
			cin>>x>>y;
			--x, --y;
			DEBUG cout<<"1 "<<x<<' '<<y<<'\n';
			const array<pair<uf2, uf2>, 5> nxs{
				make_pair(x, y),
				make_pair(x, y+1u),
				make_pair(x, y-1u),
				make_pair(x+1u, y),
				make_pair(x-1u, y),
			};

			for(const auto &nx : nxs){
				if(3 < nx.first || n <= nx.second) continue;
				DEBUG cout<<"  nx: "<<nx.first<<' '<<nx.second<<'\n';
				const auto &cur = st[nx.first].q(nx.second);
				st[nx.first].x(nx.second, {cur.first + 1u, cur.second});
			}
		}else{
			uf2 x;
			cin>>x;
			--x;
			DEBUG cout<<"2 "<<x<<'\n';
			cout<<st[x].q(0, n).second<<'\n';
		}
	}

	uf4 u=0, v=0, r=0;
	for(uf2 i=4; i--;){
		if(auto [a, b] = st[i].q(0, n); r <= a)
			r = a, u = i+1, v = b;
	}
	cout<<u<<' '<<v;
	return 0;
}
AFESDJPOI
;
