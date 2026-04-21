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

	constexpr u4 BM = 100;
	constexpr u4 NM = 3 * BM - 6;
	constexpr u4 LM = 3 * BM - 2;
	constexpr u4 TM = 100 + LM;

	u4 B, N, M;
	cin>>B>>N>>M;

	array<array<i4, BM>, BM> idx;
	for(u4 r=0; r<BM; ++r)
		for(u4 c=0; c<BM; ++c)
			idx[r][c] = -1;

	array<array<u4, 2>, LM> pos{};
	u4 L = 0;

	for(u4 c=0; c<B; ++c){
		pos[L] = {0, c};
		idx[0][c] = static_cast<i4>(L++);
	}
	for(u4 r=1; r<B; ++r){
		pos[L] = {r, B - 1};
		idx[r][B - 1] = static_cast<i4>(L++);
	}
	for(u4 c=B - 1; 1 <= c--;){
		pos[L] = {B - 1, c};
		idx[B - 1][c] = static_cast<i4>(L++);
	}

	array<u4, NM> T{};
	array<u4, NM> x{};
	array<array<i4, 2>, NM> e{};
	array<u1, NM> cnt{};

	for(u4 i=0; i<N; ++i){
		u4 r, c, t;
		cin>>r>>c>>t;
		T[i] = t;
		x[i] = 0;
		cnt[i] = 0;
		e[i][0] = e[i][1] = -1;

		if(0 < r && idx[r - 1][c] != -1) e[i][cnt[i]++] = idx[r - 1][c];
		if(r + 1 < B && idx[r + 1][c] != -1) e[i][cnt[i]++] = idx[r + 1][c];
		if(0 < c && idx[r][c - 1] != -1) e[i][cnt[i]++] = idx[r][c - 1];
		if(c + 1 < B && idx[r][c + 1] != -1) e[i][cnt[i]++] = idx[r][c + 1];
	}

	array<u4, LM> a{};
	for(u4 i=0; i<LM; ++i) a[i] = 0;

	u4 ans = 0;

	for(u4 tm=1; tm<=M+L; ++tm){
		for(u4 i=L; 1 < i--;)
			a[i] = a[i-1];
		a[0] = tm <= M ? tm : 0;

		for(u4 i=0; i<N; ++i)
			if(x[i] == tm)
				x[i] = 0;

		for(u4 i=0; i<N; ++i){
			if(x[i]) continue;

			i4 bp = -1;
			u4 bg = static_cast<u4>(-1);

			for(u4 j=0; j<cnt[i]; ++j){
				const i4 p = e[i][j];
				if(p == -1 || !a[p]) continue;
				if(a[p] < bg){
					bg = a[p];
					bp = p;
				}
			}

			if(bp != -1){
				a[bp] = 0;
				x[i] = tm + T[i];
				++ans;
			}
		}
	}

	cout<<ans;

	return 0;
}

AFESDJPOI
;
