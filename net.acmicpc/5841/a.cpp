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
#include<stdfloat>
#include<cmath>
#include<cstring>
#include<ranges>
//; echo """

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

	uf4 n, k;
	cin>>n>>k;

	auto a = [] consteval {
		array<uf4, 15> a;
		for(uf4 i=a.size(); i--;)
			a[i] = i;
		return a;
	}();

	uf1 bn = 0;
	array<pair<uf1, uf1>, 50> b;

	while(k--){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		char z;
		uf2 x, y;
		cin>>z>>x>>y;
		--x, --y;
		if(z == 'S'){
			uf1 p = x, q = y;
			for(; p != a[p]; p = a[p]);
			for(; q != a[q]; q = a[q]);
			a[p] = q;
		}else{
			b[bn++] = {x, y};
		}
	}

	uf1 cn = 0;
	array<uf1, 15> c;

	for(uf1 i=n; i--;){
		if(a[i] == i) c[cn++] = i;
		else for(uf1 p = i; p != a[p] || (a[i] = p, 0); p = a[p]);
	}

	array<bitset<15>, 15> m;
	for(const auto& [x, y] : b | views::take(bn)){
		uf1 p = a[x], q = a[y];
		if(p == q){
			cout<<'0';
			return 0;
		}
		m[p].set(q);
		m[q].set(p);
	}

	bitset<15> v;

	uf4 r = 1;

	array<uf1, 15> d;
	function<uf4(uf1, bitset<15>)> f = [&](uf1 p, bitset<15> vv){
		const uf4 x = c[p];
		uf4 ret = 0;
		v.set(x);
		vv |= bitset<15>().set(x);
		cout<<"f: "<<uf2(x)<<' '<<vv<<'\n';

		for(uf4 i=3; i--;){
			for(uf1 j=cn; j--;)
				if(vv.test(c[j]) && m[x].test(c[j]) && i == d[c[j]])
					goto cont;

			{
				bool fl = false;
				d[x] = i;
				for(uf1 j=p; j--;){
					if(vv.test(c[j]) || !m[x].test(c[j])) continue;
					fl = true;
					ret += f(j, vv);
				}
				if(!fl) ret += 1;
			}
		cont:
		}

		cout<<"f: "<<uf2(x)<<' '<<vv<<' '<<ret<<'\n';

		return ret;
	};

	for(uf4 i=cn; i--;){
		if(v.test(c[i])) continue;
		uf4 x = f(i, bitset<15>());
		cout<<x<<'\n';
		r *= x;
	}
	cout<<'\n';
	cout<<r;

	return 0;
}
//; echo """
