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

inline void coutDrop(bool a, uf4 b){
	cout<<"DROP "<<a+1<<' '<<b<<'\n';
}
inline void coutTake(bool a, uf4 b){
	cout<<"TAKE "<<a+1<<' '<<b<<'\n';
}
inline void coutMove(bool a, uf4 b){
	cout<<"MOVE "<<a+1<<"->"<<!a+1<<' '<<b<<'\n';
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	constexpr char DROP[]="DROP";

	uf4 N, n;
	array<uf4, 2> a;
	string s;

	while(cin>>N, N)for(
		a = {0 ,0};
		N-- || (cout<<'\n', 0);
	){
		cin>>s>>n;
		if(s==DROP){
			a[0] += n;
			coutDrop(0, n);
		}else{
			uf4 tn = n;
			{
				uf4 t = min(a[1], n);
				if(t){
					a[1] -= t;
					tn -= t;
					coutTake(1, t);
				}
			}
			if(tn){
				coutMove(0, a[0]);
				a[1] = a[0];
				a[0] = 0;
				coutTake(1, tn);
				a[1] -= tn;
			}
		}
	}
	return 0;
}

