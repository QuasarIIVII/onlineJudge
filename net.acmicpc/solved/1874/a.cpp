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

	uf4 n;
	cin>>n;
	array<uf4, 100'000> a;
	for(uf4 i=0; i<n; ++i)
		cin>>a[i];

	uf4 p=0, q=0;
	stack<uf4> s;

	ostringstream ss;

	while(true){
		if(s.size() && s.top()==a[p]){
			s.pop();
			++p;
			ss<<"-\n";
		}else if(q<n){
			s.push(++q);
			ss<<"+\n";
		}else if(p<n && s.size() && s.top()!=a[p]){
			cout<<"NO\n";
			return 0;
		}else{
			break;
		}
	}
	if(p<n){
		cout<<"NO\n";
		return 0;
	}else{
		cout<<ss.str();
	}
	return 0;
}
//; echo """
