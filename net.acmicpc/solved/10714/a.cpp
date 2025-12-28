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
#include<stdfloat>
#include<cmath>
#include<cstring>
#define AFESDJPOI asm("")
//$(pwd); cat <<AFESDJPOI

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
										using f4=float32_t;	using f8=float64_t;	using f16=float128_t;
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

	array<array<u8, 2000>, 2000> a{};
	array<u4, 2000> d;
	u2 n;

	cin>>n;

	if(n==1){
		u4 t;
		cin>>t;
		cout<<t;
		return 0;
	}else if(n==2){
		u4 t1, t2;
		cin>>t1>>t2;
		cout<<max(t1, t2);
		return 0;
	}

	for(u2 i=n; i--;) cin>>d[i];

	function<u8(u2, u2)> f, g;

	f = [&](const u2 l, const u2 r){
		if(a[l][r]) return a[l][r];
		if(l==r) return a[l][r]=d[l];

		u2 ll = l+1, rr = r+n-1;
		if(n<=ll) ll-=n;
		if(n<=rr) rr-=n;
		return a[l][r] = max(d[l]+g(ll, r), d[r]+g(l, rr));
	};

	g = [&](const u2 l, const u2 r){
		if(a[l][r]) return a[l][r];
		if(l==r) return a[l][r]=0;

		if(d[l] < d[r]){
			u2 t = r+n-1;
			if(n<=t) t-=n;
			return a[l][r] = f(l, t);
		}else{
			u2 t = l+1;
			if(n<=t) t-=n;
			return a[l][r] = f(t, r);
		}
	};

	u8 r = 0;
	for(u2 i=n; i--;){
		u2 e = i+n-2, p = i+n-1;
		if(n<=e) e-=n;
		if(n<=p) p-=n;
		r = max(r, d[p] + g(i, e));
	}

	cout<<r;
	return 0;
}

AFESDJPOI
;
