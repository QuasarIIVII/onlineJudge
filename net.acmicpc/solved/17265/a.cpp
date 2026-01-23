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

	uf2 n;
	cin>>n;

	array<array<char, 5>, 5> a;
	for(uf2 i=0; i<n; i++)for(uf2 j=0; j<n; j++){
		string s;
		cin>>s;
		a[i][j]=s[0];
	}

	constexpr auto f = [](const char op, const if4 l, const char r){
		if(op == 0x2b) return l + r - 0x30;
		if(op == 0x2a) return l * (r - 0x30);
		return l - (r - 0x30);
	};

	array<array<if4, 5>, 5> mx{};
	array<array<if4, 5>, 5> mn{};

	ostringstream oss;

	for(uf2 i=0; i<n; ++i)for(uf2 j=0; j<n; ++j){
		if4 x = numeric_limits<if4>::min();
		if4 s = numeric_limits<if4>::max();

		if((i^j)&1){
			if(i){
				x = mx[i-1][j];
				s = mn[i-1][j];
			}
			if(j){
				x = max(x, mx[i][j-1]);
				s = min(s, mn[i][j-1]);
			}
			mx[i][j] = x, mn[i][j] = s;
		}else{
			if(!(i|j)){
				mx[i][j] = a[i][j] - 0x30;
				mn[i][j] = a[i][j] - 0x30;

				DEBUG oss<<mx[i][j]<<','<<mn[i][j]<<'\t';
				DEBUG if(j==n-1)oss<<'\n';

				continue;
			}

			if(i){
				x = f(a[i-1][j], mx[i-1][j], a[i][j]);
				s = f(a[i-1][j], mn[i-1][j], a[i][j]);
				DEBUG cout<<i<<' '<<j<<" i "<<x<<','<<s<<'\n';
			}
			if(j){
				x = max(x, f(a[i][j-1], mx[i][j-1], a[i][j]));
				s = min(s, f(a[i][j-1], mn[i][j-1], a[i][j]));
				DEBUG cout<<i<<' '<<j<<" j "<<x<<','<<s<<'\n';
			}
			mx[i][j] = x, mn[i][j] = s;
		}

		DEBUG oss<<mx[i][j]<<','<<mn[i][j]<<'\t';
		DEBUG if(j==n-1)oss<<'\n';
	}

	DEBUG cout<<oss.str()<<endl;
	cout<<mx[n-1][n-1]<<' '<<mn[n-1][n-1];

	return 0;
}
AFESDJPOI
;
