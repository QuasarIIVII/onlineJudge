#include<iostream>
#include<string>
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

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
										using f4=float;		using f8=double;	using f16=long double;
using uf1=uint_fast8_t;	using uf2=uint_fast16_t;using uf4=uint_fast32_t;using uf8=uint_fast64_t;
using if1=int_fast8_t;	using if2=int_fast16_t;	using if4=int_fast32_t;	using if8=int_fast64_t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	array<array<uf2,3>,2> mx={0,}, mn={0,};
	uf4 n;

	cin>>n;
	for(uf4 i=n;i--;){
		const uf1 &p=i&1, &q=p^1;
		{
			auto &a=mx;
			cin>>a[p][0]>>a[p][1]>>a[p][2];
			mn[p]=a[p];
			const uf2	&c0 = a[q][0]>a[q][1] ? a[q][0] : a[q][1],
						&c1 = a[q][1]>a[q][2] ? a[q][1] : a[q][2],
						&c2 = c0>c1 ? c0 : c1;
			a[p][0]+=c0,a[p][2]+=c1,a[p][1]+=c2;
		}{
			auto &a=mn;
			const uf2	&c0 = a[q][0]<a[q][1] ? a[q][0] : a[q][1],
						&c1 = a[q][1]<a[q][2] ? a[q][1] : a[q][2],
						&c2 = c0<c1 ? c0 : c1;
			a[p][0]+=c0,a[p][2]+=c1,a[p][1]+=c2;
		}
	}
	{
		auto &a=mx;constexpr uf1 q=0;
		const uf2	&c0 = a[q][0]>a[q][1] ? a[q][0] : a[q][1],
					&c1 = a[q][1]>a[q][2] ? a[q][1] : a[q][2],
					&c2 = c0>c1 ? c0 : c1;
		cout<<c2<<' ';
	}{
		auto &a=mn;constexpr uf1 q=0;
		const uf2	&c0 = a[q][0]<a[q][1] ? a[q][0] : a[q][1],
					&c1 = a[q][1]<a[q][2] ? a[q][1] : a[q][2],
					&c2 = c0<c1 ? c0 : c1;
		cout<<c2;

	}
	return 0;
}

