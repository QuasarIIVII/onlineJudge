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
//; echo """

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

template<class T, class F = std::function<T(const T&, const T&)>>
class ST{
private:
	size_t n;
	T id;
	F op;
	std::vector<T> tree;

public:
	ST(const std::vector<T>& init, F op, const T id)
	:id(id), op(op)
	{
		n=1;
		for(size_t e=init.size(); n<e; n<<=1);

		tree.assign(2*n, id);
		build(init);
	}

private:
	void build(const std::vector<T>& init){
		const size_t sz = init.size();

		for(size_t i=sz; i--; )
			tree[n+i] = init[i];

		for(size_t i=n-1; i>=1; --i){
			tree[i] = op(tree[2*i], tree[2*i+1]);
		}
	}

public:
	void update(size_t idx, const T& val){
		idx += n;
		tree[idx] = val;

		for(idx>>=1; idx; idx>>=1)
			tree[idx] = op(tree[2*idx], tree[2*idx+1]);
	}

	T query(size_t l, size_t r) const {
		T rl = id, rr = id;
		l+=n, r+=n;

		while(l<r){
			if(l&1) rl = op(rl, tree[l++]);
			if(r&1) rr = op(tree[--r], rr);

			l>>=1, r>>=1;
		}

		return op(rl, rr);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	auto f = [](const auto& a, const auto& b){return make_pair(min(a.first, b.first), max(a.second, b.second));};

	uf4 n, N;
	cin>>N;
	n = N;

	vector<pair<uf4, uf4>> v;
	v.reserve(n);

	for(uf4 i=n; i--; ){
		uf4 x;
		cin>>x;
		v.emplace_back(x, x);
	}

	ST<pair<uf4, uf4>, decltype(f)> s(v, f, make_pair(numeric_limits<uf4>::max(), 0));

	uf4 p=0;
	array<uf4, 1'000> a;

	for(uf4 i=2, m=1; i<=n; ++i){
		while(!(n%i)){
			n/=i;
			if(n==1) goto lb0;
			m*=i;
			a[p++] = m;
			a[p++] = N/m;
		}
	}
lb0:
	a[p++] = 1;

	for(uf4 i=p; i--; ){
		const uf4 sz = a[i];
		const auto [l, r] = s.query(0, sz);
		const uf4 t = l+r;

		DEBUG cout<<"sz: "<<sz<<", l: "<<l<<", r: "<<r<<'\n';
		DEBUG cout<<a[i]<<' ';

		uf4 j;
		for(j=sz; j<N; j+=sz){
			const auto [ll, rr] = s.query(j, j+sz);
			if(t != ll+rr) break;
		}
		DEBUG cout<<j<<'\n';
		if(N<=j){
			cout<<"1";
			return 0;
		}
	}

	cout<<"0";

	return 0;
}
//; echo """
