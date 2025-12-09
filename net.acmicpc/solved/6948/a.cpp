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
#define AFESDJPOI asm("nop")
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

	uf4 N;
	cin>>N;

	uf4 v = 0;
	array<uf4, 26> a{0, }, b{0, };

	for(uf4 n=N; n--;){
		char c0, c1;
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cin>>c0;
		cin.ignore(numeric_limits<std::streamsize>::max(), ' ');
		cin.ignore(numeric_limits<std::streamsize>::max(), ' ');
		cin>>c1;

		v |= 1u << (c0&0x1f);

		if(c1 & 0x20){
			a[(c0&0x1f)-1] |= 1u << (c1&0x1f);
		}else{
			b[(c0&0x1f)-1] |= 1u << (c1&0x1f);
			v |= 1u << (c1&0x1f);
		}
	}

	for(uf4 i=26; i--;)for(uf4 j=26; j--;){
		uf4 bb = b[j];
		for(uf4 k=-1, p; (k+=(p = countr_zero(bb))) < 26; ++k, bb>>=p+1)
			a[j] |= a[k];
	}

	v>>=1;
	for(uf4 i=0, p; (i+=(p = countr_zero(v))) < 26; ++i, v>>=p+1){
		cout<<static_cast<char>(i+0x41)<<" = {";
		bool f = false;
		for(uf4 j=-1, q; (j+=(q = countr_zero(a[i]))) < 26; ++j, a[i]>>=q+1){
			if(f) cout<<',';
			cout<<static_cast<char>(j+0x61);
			f = true;
		}
		cout<<"}\n";
	}

	return 0;
}
AFESDJPOI
;
