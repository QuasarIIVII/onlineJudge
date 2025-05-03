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

template<class T>
T f(T s, T e, if4 k){
	const T S = s;
	T m;

	while(s<e){
		m = s + (e-s)/2;
		if(*m < k)
			s=m+1;
		else if(*m > k)
			e=m;
		else break;
	}
	for(; S<m && k<=*m; --m);
	if(S==m)
		return k<=*m ? S : S+1;
	return m+1;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 n, k;
	array<if4, 100'000> a, s{0, }, b{0, };

	cin>>n>>k;
	for(uf4 i=n; i--;) cin>>a[i];
	for(uf4 i=k; i--;){
		if4 x;
		cin>>x;
		b[i]=x*10;
	}

	if(a[n-1]<0) s[n-1]=a[n-1]*-2;
	DEBUG cout<<s[n-1]<<' ';
	for(uf4 i=n-1; i--;){
		s[i] = s[i+1] + a[i]*-2;
		if(s[i] < 0) s[i] = 0;
		DEBUG cout<<s[i]<<' ';
	}
	DEBUG cout<<endl;

	sort(s.begin(), s.begin()+n);

	DEBUG{
		for(uf4 i=n; i--;)
			cout<<s[i]<<' ';
		cout<<endl;
		for(uf4 i=k; i--;)
			cout<<b[i]<<' ';
		cout<<endl;
	}

	const auto E = s.begin()+n;
	for(uf4 i=k; i--;){
		DEBUG cout<<'('<<b[i]<<") ";
		cout<<E-f(s.begin(), s.begin()+n, b[i])<<' ';
	}

	return 0;
}
//; echo """
