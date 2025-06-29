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
#include<cassert>
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

	uf4 n;
	string s, ss;

	cin>>n;
	s.reserve(n+1);
	cin>>s;

	ss=s;
	sort(ss.begin(), ss.end(), greater());

	DEBUG cout<<ss<<"\n";

	u2 i=0, j=0;
	for(; i<n && s[i]==ss[i]; ++i);
	if(i==n){
		cout<<s;
		return 0;
	}

	u2 I=i;
	// for(; I<n && ss[I]==ss[i]; ++I);

	for(j=i; j<n; ++j) if(s[j]==ss[I]) break;
	DEBUG cout<<"i: "<<i<<" I: "<<I<<", j: "<<j<<"\n";
	while(j<n && s[j]==ss[I]) ++j;
	--j;

	// zaza
	// zzaa
	// xyxyy

	DEBUG cout<<"i: "<<i<<" I: "<<I<<", j: "<<j<<"\n";

	ss = s.substr(0, i);

	for(u2 k=j; k>=i && k<n; --k)
		ss.push_back(s[k]);

	ss.append(s.substr(j+1));

	cout<<ss;

	return 0;
}
//; echo """
