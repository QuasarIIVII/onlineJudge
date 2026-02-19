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

	array<u1, 200'001> a;
	char s0[200'001], s1[200'001];
	cin>>s0>>s1;
	const u4 sz = strlen(s0);

	for(u4 i=sz; i--;)
		a[i] = s1[i]<=s0[i] ? s1[i]-s0[i]+26 : s1[i]-s0[i];

	DEBUG for(u4 i=sz; i--;)
		cout<<+a[i]<<" \n"[i==0];

	u4 q=0;
	array<u4, 500> b;

	for(u4 i=1; i*i<=sz; ++i){
		const u4 qq = sz/i;
		b[q] = qq;
		b[q+1] = i;
		if(!(sz%i)) q+=2;
	}
	if(b[q-1]==b[q-2]) --q;

	DEBUG for(u4 i=q; i--;)
		cout<<b[i]<<" \n"[i==0];

	u4 r = numeric_limits<u4>::max();
	while(q--){
		const u4 k = b[q];
		if(r <= k) continue;
		for(u4 i=k; i--;){
			const u1 v = a[i];
			for(u4 j=i+k; j<sz; j+=k)
				if(a[j]!=v) goto lb0;
		}
		r = min(r, k);
	lb0:
	}

	for(u4 i=0; i<r; ++i) a[i] += 0x40;
	a[r] = 0;

	cout<<reinterpret_cast<char*>(a.data());
	return 0;
}
AFESDJPOI
;
