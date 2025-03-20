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

array<uf4, 5002> t;
array<vector<uf4>, 2> a;

void print(vector<uf4>& a){
	for(auto& i : a)
		cout<<i<<' ';
	cout<<'\n';
}

template<class RandomIt>
requires is_same_v<
	random_access_iterator_tag,
	typename iterator_traits<RandomIt>::iterator_category
>
inline RandomIt f(const RandomIt first, const RandomIt last, const uf4 n){
	RandomIt s = first, e = last;
	RandomIt m = s + ((e - s) >> 1);

	for(
		;
		s < e;
		m = s + ((e - s) >> 1)
	){
		if(*m <= n)
			s = m+1;
		else
			e = m;
	}

	return m;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	a[0].reserve(5001*5001);
	a[1].reserve(5001*5001);

	uf4 n;
	while(true){
		array<uf2, 4> m;
		cin>>n>>m[3]>>m[2]>>m[1]>>m[0];
		if(!n) break;

		a[0].clear();
		a[1].clear();

		for(uf2 i = m[3]; i--;)
			cin>>t[i];

		for(uf2 i = m[2]; i--;){
			uf4 x;
			cin>>x;
			for(uf2 i = m[3]; i--; )
				a[0].push_back(x+t[i]);
		}

		for(uf2 i = m[1]; i--;)
			cin>>t[i];

		for(uf2 i = m[0]; i--;){
			uf4 x;
			cin>>x;
			for(uf2 i = m[1]; i--; )
				a[1].push_back(x+t[i]);
		}

		sort(a[0].begin(), a[0].end(), less<uf4>());
		sort(a[1].begin(), a[1].end(), less<uf4>());

		decltype(a)::value_type::iterator it = f(a[0].begin(), a[0].end(), n);
		DEBUG cout<<"it - a[0].begin() = "<<it - a[0].begin()<<endl;
		if(it == a[0].begin()){
			cout<<0<<'\n';
			continue;
		}
		uf4 s = 0;
		for(auto i = a[0].begin(); i != it; ++i){
			if(n < *i){
				DEBUG cout<<"break\n";
				break;
			}

			decltype(a)::value_type::iterator it = f(a[1].begin(), a[1].end(), n - *i);
			DEBUG cout<<"it - a[1].begin() = "<<it - a[1].begin()<<endl;
			s += it - a[1].begin();
		}

		cout<<s<<'\n';
	}

	return 0;
}

