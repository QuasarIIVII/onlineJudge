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
//; echo """

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

uf2 f(
	const array<array<uf2, 100>, 100>& a,
	const array<uf1, 2>& sz,
	const array<uf1, 2> p,
	array<bitset<100>, 100>& v
){
	DEBUG cout<<"f: ("<<+p[0]<<", "<<+p[1]<<")"<<endl;
	v[p[0]].set(p[1]);

	const array<array<uf1, 2>, 4> Q{
		array<uf1, 2>{static_cast<uf1>(p[0]+1u), p[1]},
		array<uf1, 2>{static_cast<uf1>(p[0]-1u), p[1]},
		array<uf1, 2>{p[0], static_cast<uf1>(p[1]+1u)},
		array<uf1, 2>{p[0], static_cast<uf1>(p[1]-1u)},
	};

	uf2 r = 1;

	for(auto& q : Q){
		if(sz[0] <= q[0] || sz[1] <= q[1]) continue;
		if(v[q[0]][q[1]] || a[q[0]][q[1]] <= a[p[0]][p[1]]) continue;
		DEBUG cout<<"f: ("<<+p[0]<<", "<<+p[1]<<") -> ";
		r += f(a, sz, q, v);
	}
	
	return r;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 N, M;

	cin>>N>>M;

	const auto a = [&](){
		array<array<uf2, 100>, 100> a;
		for(uf1 i=N; i--;)for(uf1 j=M; j--;)
			cin>>a[i][j];
		return a;
	}();

	uf2 r = 0;
	const array<uf1, 2> sz{static_cast<uf1>(N), static_cast<uf1>(M)};
	for(uf1 I=N; I--;)for(uf1 J=M; J--;){
		array<bitset<100>, 100> v;
		DEBUG cout<<"("<<+I<<", "<<+J<<")\n";
		r = max(r, f(a, sz, {I, J}, v));
	}

	cout<<r;
	return 0;
}
//; echo """
