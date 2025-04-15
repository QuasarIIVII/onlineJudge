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
#define DEBUG_MACRO(x)
#define DEBUG_MACRO_ELSE(x) x
#else
#define DEBUG_MACRO(x) x
#define DEBUG_MACRO_ELSE(x)
#endif

#define DEBUG if constexpr(debug)
#define DEBUG_BLOCK(x) if constexpr(debug){x}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	for(uf4 x; cin>>x;){
		uf4 d,m,y, t, k, s=0;
		for(uf4 xx=x; xx; xx/=10){
			uf4 t=xx%10;
			s+=t*t;
		}

		d=x/10'000'000;
		x%=10'000'000;
		m=x/100'000;
		x%=100'000;
		y=x/100;
		x%=100;
		t=x/10;
		k=x%10;

		s-=k*k;
		s%=7;

		y = y<600 ? 2000+y : 1000+y;


		constexpr array<bool, 10> a={0,1,0,0,0,0,1,0,0,1};
		constexpr array<bool, 12> b={1,0,1,0,1,0,1,1,0,1,0,1};
		if(!a[t] || s!=k){
			cout<<"0\n";
			DEBUG cout<<!a[t]<<' '<<s<<' '<<k<<'\n';
			continue;
		}

		if(d==29 && m==2){
			if(y%4!=0 || y%100==0 && y%400!=0){
				cout<<"0\n";
				DEBUG cout<<"A "<<d<<' '<<m<<' '<<y<<' '<<t<<' '<<k<<'\n';
			}
			else cout<<"1\n";
			continue;
		}

		if(m==2 && 28<d){
			cout<<"0\n";
			DEBUG cout<<"B "<<d<<' '<<m<<' '<<y<<' '<<t<<' '<<k<<'\n';
			continue;
		}

		if(m<1 || 12<m){
			cout<<"0\n";
			DEBUG cout<<"C "<<d<<' '<<m<<' '<<y<<' '<<t<<' '<<k<<'\n';
			continue;
		}

		if(d==0 || 30+b[m-1]<d){
			cout<<"0\n";
			DEBUG cout<<"D "<<d<<' '<<m<<' '<<y<<' '<<t<<' '<<k<<'\n';
			continue;
		}

		cout<<"1\n";
		DEBUG cout<<d<<' '<<m<<' '<<y<<' '<<t<<' '<<k<<'\n';
	}

	return 0;
}

