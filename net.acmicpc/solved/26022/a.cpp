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

	uf4 N, M, K;
	uf4 n, m, k;
	cin>>N>>M>>K;
	n=N, m=M, k=K;

	for(uf4 i=2, e=min(n, k); i<=e; ){
		if(!(n%i) && !(k%i))
			n/=i, k/=i;
		else ++i;
	}

	for(uf4 i=2, e=min(m, k); i<=e; ){
		if(!(m%i) && !(k%i))
			m/=i, k/=i;
		else ++i;
	}

	if(k!=1){
		cout<<"impossible";
		return 0;
	}

	array<char, 100*101+1> a;

	uf4 l=M/m;

	for(k=0; k<K; ++k){
		uf4 x = k%l, y = k/l;
		x*=m, y*=n;

		for(uf4 i=n; i--;){
			uf4 t=(i+y)*(M+1);
			for(uf4 j=m; j--;)
				a[t+x+j] = k+65;
			a[t+x+m] = 0xa;
		}
	}
	a[N*M+N] = 0;
	cout<<a.data();
	return 0;
}
//; echo """
