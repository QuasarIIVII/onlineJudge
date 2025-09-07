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

	uf2 n;
	array<pair<uf1, if2>, 1000> a;

	cin>>n;
	for(uf2 i=0; i<n; ++i){
		string s;
		if2 x;
		cin>>s;
		switch(s[0]){
		case 'P':
			if(s[1]=='U'){
				cin>>x;
				a[i] = {1, x};
			}else a[i].first = 2;
			break;
		case 'S':
			a[i].first = 5;
			break;
		case 'L':
			a[i].first = 4;
			break;
		case 'T':
			a[i].first = 3;
			break;
		case 'I':
			cin>>x;
			a[i] = {6, x};
			break;
		case 'D':
			a[i].first = 0;
			break;
		}
	}

	uf1 sp = 0;
	array<if2, 100> s;
	if2 r = 0;

	for(uf2 ip=0; a[ip].first;){
		DEBUG cout<<ip<<'\t'<<r<<'\t';
		DEBUG for(uf1 i=0; i<sp || (cout<<endl, 0); ++i) cout<<s[i]<<' ';
		switch(a[ip].first){
		case 1:
			s[sp++] = a[ip].second;
			++ip;
			break;
		case 2:
			s[sp-2] += s[sp-1];
			--sp, ++ip;
			break;
		case 3:
			s[sp-2] *= s[sp-1];
			--sp, ++ip;
			break;
		case 4:
			s[sp++] = r;
			++ip;
			break;
		case 5:
			r = s[--sp];
			++ip;
			break;
		case 6:
			if(!s[--sp])
				ip = a[ip].second;
			else ++ip;
			break;
		}
	}

	cout<<s[sp-1];
	return 0;
}
//; echo """
