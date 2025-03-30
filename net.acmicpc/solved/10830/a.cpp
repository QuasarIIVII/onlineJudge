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

// matrix
struct S{
	vector<vector<uf4>> v;

	S(uf4 n):v(n,vector<uf4>(n)){}
	S(const S& other):v(other.v){}
	S(S&& other):v(move(other.v)){}

	S& operator=(const S& other){
		v=other.v;
		return *this;
	}
	S& operator=(S&& other){
		v=move(other.v);
		return *this;
	}
	S& operator*=(const S& other){
		const uf4 n=v.size();
		vector<vector<uf4>> t(n,vector<uf4>(n, 0));
		for(uf4 i=n;i--;)for(uf4 j=n;j--;){
			for(uf4 k=n;k--;)
				(t[i][j]+=v[i][k]*other.v[k][j]%1000)%=1000;
		}
		v=move(t);
		return *this;
	}
};

S f(const S& s,const uf8 e){
	if(e==1)
		return s;

	S t=f(s,e/2);
	t*=t;

	if(e&1)
		t*=s;

	return t;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n;
	uf8 e;
	cin>>n>>e;

	S s(n);
	for(auto& i:s.v)for(auto& j:i)cin>>j;

	s=f(s,e);
	for(auto& i:s.v){for(auto& j:i)cout<<j%1000<<' ';cout<<'\n';}

	return 0;
}

