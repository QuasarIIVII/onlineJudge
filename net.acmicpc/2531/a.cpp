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
#define DEBUG_MACRO(x) 0
#define DEBUG_MACRO_ELSE(x) x
#else
#define DEBUG_MACRO(x) x
#define DEBUG_MACRO_ELSE(x) 0
#endif

#define DEBUG if constexpr(debug)
#define DEBUG_BLOCK(x) if constexpr(debug){x}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<uf2, 30000> a;
	uf4 n, d, k, c;

	cin>>n>>d>>k>>c;
	for(uf4 i=0; i<n; ++i)
		cin>>a[i];

	array<uf2, 3000> t{0, };
	uf4 s=0, mx;
	bool f=false;
	for(uf4 i=k; i--; ){
		++t[a[i]];
		if(t[a[i]]==1){
			++s;
			DEBUG cout<<"+0 "<<a[i]<<" "<<s<<endl;
			if(a[i]==c) DEBUG_MACRO(cout<<"T"<<endl ), f=true;
		}
	}
	mx = f ? s : s+1;

	DEBUG cout<<endl;

	for(uf4 i=1; i<n; ++i){
		--t[a[i-1]];
		if(t[a[i-1]]==0){
			--s;
			DEBUG cout<<"-"<<i<<' '<<a[i-1]<<" "<<s<<endl;
			if(a[i-1]==c) DEBUG_MACRO(cout<<"F"<<endl ), f=false;
		}

		auto cur=a[(i+k-1)%n];
		++t[cur];
		if(t[cur]==1){
			++s;
			DEBUG cout<<"+"<<i<<' '<<cur<<" "<<s<<endl;
			if(cur==c) DEBUG_MACRO(cout<<"T"<<endl ), f=true;
		}

		mx=max(mx, f ? s : s+1);

		DEBUG cout<<endl;
	}

	cout<<mx;

	return 0;
}
//; echo """
