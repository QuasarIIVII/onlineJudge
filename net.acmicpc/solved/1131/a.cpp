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

	constexpr u4 N = 3'720'088;

	constexpr auto P = [](){
		array<array<u4, 8>, 10> P;
		for(u4 i=P.size(); i--;)
			for(u4 j = P[i][0] = 1; j<P[0].size(); ++j)
				P[i][j] = P[i][j-1] * i;
		return P;
	}();

	u4 a, b, k;
	cin>>a>>b>>k;

	const auto S = [&k, &P](){
		array<u4, N> S;
		array<u1, 8> ii{};

		for(u4 i=0; i<S.size(); ++i){
			S[i] = 0;
			for(u4 j=ii.size(); j--; S[i] += P[ii[j]][k]);

			if(++ii[0] == 10) ++ii[1], ii[0] = 0;
			if(ii[1] == 10) ++ii[2], ii[1] = 0;
			if(ii[2] == 10) ++ii[3], ii[2] = 0;
			if(ii[3] == 10) ++ii[4], ii[3] = 0;
			if(ii[4] == 10) ++ii[5], ii[4] = 0;
			if(ii[5] == 10) ++ii[6], ii[5] = 0;
			if(ii[6] == 10) ++ii[7], ii[6] = 0;
		}

		return S;
	}();

	DEBUG cout<<S[b]<<endl;

	u8 r = 0;
	array<u4, N> m{};

	for(u4 i=b-a+1; i--;){
		const u4 n = a+i;

		u4 sp = 0;
		array<u4, N> st;
		st[sp++] = n;

		u4 mn;

		for(;;){
			const u4 t = st[sp-1];
			DEBUG cout<<t<<' ';
			if(const i4 mt = static_cast<i4>(m[t]); !mt){
				m[t] = -u4(1);
				st[sp++] = S[t];
				continue;
			}else if(0 < mt){
				--sp;
				mn = m[t];
			}else{
				u4 j=--sp;
				for(u4 e=mn=t; j; mn = min(mn, st[j]))
					if(st[--j] == e) break;
				while(j < sp) m[st[--sp]] = mn;
			}
			break;
		}

		while(sp--) m[st[sp]] = mn = min(mn, st[sp]);
		r += mn;

		DEBUG cout<<endl;
	}

	cout<<r;

	return 0;
}
AFESDJPOI
;
