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

vector<vector<uf8>> a;

void print(vector<uf8>& a){
	for(auto& i : a)
		cout<<i<<' ';
	cout<<'\n';
}

template<class RandomIt>
requires is_same_v<
	random_access_iterator_tag,
	typename iterator_traits<RandomIt>::iterator_category
>
inline RandomIt f(RandomIt first, RandomIt last, const uf8 n){
	RandomIt ff = first, ll = last;
	RandomIt m = first + ((last - first) >> 1);

	for(
		;
		first < last;
		m = first + ((last - first) >> 1)
	){
//		DEBUG cout<<*m<<' '<<first-ff<<' '<<last-ff<<' '<<m-ff<<'\n';
		if(*m == n)
			return m;
		if(*m < n)
			first = m + 1;
		else
			last = m;
	}

	for(--m ; *m >= n; --m){
		if(m == ff)
			return ll;
	}
	return m;
}

uf8 g(const uf8 n, const uf2 m){
	const decltype(a)::value_type::iterator it = f(a[m].begin(), a[m].end(), n);
	const auto idx = it - a[m].begin();

	if(it == a[m].end())
		return  0;

	if(!m)
		return 1 + idx;

	uf8 s = 0;
	for(uf8 i = idx+1; i--;){
		auto t = a[m][i] < n ? g(n - a[m][i], m-1) : 0;
		s += t;
	}
	return s;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	a.resize(4);
	a[0].reserve(5001);
	a[1].reserve(5001);
	a[2].reserve(5001);
	a[3].reserve(5001);

	uf8 n;
	while(true){
		array<uf2, 4> m;
		cin>>n>>m[3]>>m[2]>>m[1]>>m[0];
		if(!n) break;

		for(uf2 j=4; j--;){
			a[j].resize(m[j]);
			for(uf2 i=m[j]; i--;)
				cin>>a[j][i];
			sort(a[j].begin(), a[j].end(), less<uf8>());
		}

		DEBUG for(uf2  i=4; i--;)
			print(a[i]);

		cout<<g(n, 3)<<'\n';
	}

/*	DEBUG_BLOCK(
//		a[0] = a[3];
//		m[0] = m[3];

		cout<<	f(a[0].begin(), a[0].end(), 5) - a[0].begin()
		<<' '<<*f(a[0].begin(), a[0].end(), 5)<<'\n';
	);*/

	return 0;
}

