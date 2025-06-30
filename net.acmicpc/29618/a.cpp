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

template<class T, size_t N, class Cmp = less<T>, class Hash = hash<T>>
class PQ{
private:
	unordered_map<T, typename vector<T>::iterator, Hash> m;
	vector<T> d;
	Cmp cmp;
	const T id;

public:
	PQ():d(), cmp(), id(T()){
		size_t i=1;
		for(; i<N+1; i<<=1);
		d.reserve(i+1);
		d.push_back(id);
		m.emplace(id, d.begin());
	}
	PQ(const T& id, const Cmp& cmp = Cmp()):d(), cmp(cmp), id(id){
		size_t i=1;
		for(; i<N+1; i<<=1);
		d.reserve(i+1);
		d.push_back(id);
		m.emplace(id, d.begin());
	}

	void swap(size_t a, size_t b){
		std::swap(d[a], d[b]);
		std::swap(m[d[a]], m[d[b]]);
	}

	const T& top(){
		return d[1];
	}

	size_t find(const T& val){
		return m[val] - d.begin();
	}

	void p(){
		for(auto a : d) cout<<a<<' ';
		cout<<endl;
	}

	void push(const T& val){
		d.push_back(val);
		// cout<<"d.size(): "<<d.size()<<endl;
		m.emplace(val, d.end()-1);

		for(size_t i = d.size()-1; i>>=1; ){
			for(size_t j : {i*2, i*2+1}){
				if(d.size()<=j) continue;
				if(cmp(d[i], d[j])) swap(i, j);
			}
		}
	}

	void pop(const T& val){
		size_t s, e, r;
		const size_t E=d.size();
		r = s = e = m[val] - d.begin();
		m[val] = d.begin();
		// cout<<"r: "<<val<<':'<<r<<' ';

		for(size_t t; (t=s*2)<E; s=t, e=e*2+1);

		// cout<<"s: "<<s<<' ';
		// cout<<"e: "<<e<<'\t';

		e = min(e, E-1);
		// cout<<"e: "<<e<<endl;
		swap(r, e);
		d[e] = id;

		for(size_t i = r; i<e;){
			const array<size_t, 2> js{i*2, i*2+1};
			size_t t = i;

			if(js[0] < e && cmp(d[t], d[js[0]])) t = js[0];
			if(js[1] < e && cmp(d[t], d[js[1]])) t = js[1];

			if(t == i) break;

			swap(i, t);
			i = t;
		}
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 N, Q;
	cin>>N>>Q;

	array<list<if4>, 100'001> a;

	while(Q--){
		uf4 p, q;
		if4 x;
		cin>>p>>q>>x;
		a[p-1].push_back(x);
		a[q].push_back(-x);
	}

	unordered_map<array<uf4, 2>::iterator, uf4> m;

	// PQ<pair<uf4, uf4>, 100'000, greater<pair<uf4, uf4>>> pq(make_pair(
	// 	numeric_limits<uf4>::max(),
	// 	numeric_limits<uf4>::max()
	// ));

	for(uf4 i=0; i<N; ++i){
		for(auto& aa : a[i]){
			if(aa < 0){
				aa = -aa;
			}else{
			}
		}
	}
	return 0;
}
//; echo """
