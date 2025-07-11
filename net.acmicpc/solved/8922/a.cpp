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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 T;
	cin>>T;

	while(T--){
		uf4 n;
		cin>>n;

		array<uf4, 16> a;

		for(uf4 i=0; i<n; ++i)
			cin>>a[i];
		a[n] = a[0];

		unordered_set<size_t> hs;
		constexpr hash<string_view> hsh;

		const size_t zh = hsh(string_view(
			reinterpret_cast<const char*>(array<uf4, 16>{0,}.data()),
			sizeof(uf4)*n
		));

		hs.emplace(hsh(string_view(
			reinterpret_cast<const char*>(a.data()),
			sizeof(uf4)*n
		)));

		while(true){
			for(uf4 i=0; i<n; ++i)
				a[i] = abs(static_cast<if4>(a[i] - a[i+1]));
			a[n] = a[0];

			DEBUG for(uf4 i=0; i<n || (cout<<endl, 0); ++i)
				cout<<a[i]<<' ';

			size_t h = hsh(string_view(
				reinterpret_cast<const char*>(a.data()),
				sizeof(uf4)*n
			));

			if(h == zh){
				cout<<"ZERO\n";
				break;
			}

			if(hs.contains(h)){
				cout<<"LOOP\n";
				break;
			}

			hs.emplace(h);
		}
	}
	return 0;
}
//; echo """
