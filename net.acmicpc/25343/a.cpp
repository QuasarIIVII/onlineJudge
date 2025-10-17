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

	uf2 n;
	cin>>n;

	array<array<u2, 100>, 100> a;

	for(uf2 i=n; i--;)for(uf2 j=n; j--;) cin>>a[i][j];
	DEBUG for(uf2 i=0; i<n; ++i)for(uf2 j=0; j<n || (cout<<endl, 0); ++j)
		cout<<a[i][j]<<' ';

	u1 mx = 1;
	vector<vector<u1>> vs;
	array<array<vector<vector<u1>>::iterator, 100>, 100> v;
	array<array<u1, 100>, 100> b{0, };
	queue<pair<u1, u1>> q;

	vs.reserve(10'000);
	b[n-1][n-1] = 1;
	vs.push_back({0, static_cast<u1>(a[n-1][n-1])});
	v[n-1][n-1] = vs.end()-1;

	for(q.emplace(n-1u, n-1u); q.size(); q.pop()){
		const auto &[x, y] = q.front();
		auto &cv = *v[x][y];
		DEBUG cout<<uf2(x)<<' '<<uf2(y)<<"  "<<uf2(b[x][y])<<endl;

		uf1 f = 0;
		if(x-1u < n) f |= 1;
		if(y-1u < n) f |= 2;

		switch(f){
		case 0: continue;
		case 1:{
			auto it = lower_bound(cv.begin(), cv.end(), a[x-1u][y]);
			auto idx = it - cv.begin();
			DEBUG{
				cout<<"cv: ";
				for(const auto x : cv) cout<<uf2(x)<<' ';
				cout<<endl;
				cout<<"idx: "<<idx<<endl;
			}
			if(b[x-1u][y] < idx){
				if(!b[x-1u][y]) q.emplace(x-1u, y);

				if(it == cv.end()) cv.emplace_back(a[x-1u][y]);
				else *it = min(*it, static_cast<u1>(a[x-1u][y]));

				mx = max(mx, static_cast<decltype(mx)>(idx));
				b[x-1u][y] = idx;
				v[x-1u][y] = v[x][y];
			}
			DEBUG cout<<"> "<<uf2(x-1u)<<' '<<uf2(y)<<"  "<<uf2(b[x-1u][y])<<endl;
			break;
		}
		case 2:{
			auto it = lower_bound(cv.begin(), cv.end(), a[x][y-1u]);
			auto idx = it - cv.begin();
			DEBUG{
				cout<<"cv: ";
				for(const auto x : cv) cout<<uf2(x)<<' ';
				cout<<endl;
				cout<<"idx: "<<idx<<endl;
			}
			if(b[x][y-1u] < idx){
				if(!b[x][y-1u]) q.emplace(x, y-1u);

				if(it == cv.end()) cv.emplace_back(a[x][y-1u]);
				else *it = min(*it, static_cast<u1>(a[x][y-1u]));

				mx = max(mx, static_cast<decltype(mx)>(idx));
				b[x][y-1u] = idx;
				v[x][y-1u] = v[x][y];
			}
			DEBUG cout<<"> "<<uf2(x)<<' '<<uf2(y-1u)<<"  "<<uf2(b[x][y-1u])<<endl;
			break;
		}
		case 3:{
			auto it0 = lower_bound(cv.begin(), cv.end(), a[x-1u][y]);
			auto it1 = lower_bound(cv.begin(), cv.end(), a[x][y-1u]);
			auto idx0 = it0 - cv.begin(), idx1 = it1 - cv.begin();

			uf1 f = 0;
			if(b[x-1u][y] < idx0) f |= 1;
			if(b[x][y-1u] < idx1) f |= 2;
			
			switch(f){
			case 0: continue;
			case 1:{
				if(!b[x-1u][y]) q.emplace(x-1u, y);

				if(it0 == cv.end()) cv.emplace_back(a[x-1u][y]);
				else *it0 = min(*it0, static_cast<u1>(a[x-1u][y]));

				mx = max(mx, static_cast<decltype(mx)>(idx0));
				b[x-1u][y] = idx0;
				v[x-1u][y] = v[x][y];
				break;
			}
			case 2:{
				if(!b[x][y-1u]) q.emplace(x, y-1u);

				if(it1 == cv.end()) cv.emplace_back(a[x][y-1u]);
				else *it1 = min(*it1, static_cast<u1>(a[x][y-1u]));

				mx = max(mx, static_cast<decltype(mx)>(idx1));
				b[x][y-1u] = idx1;
				v[x][y-1u] = v[x][y];
				break;
			}
			case 3:{
				if(!b[x-1u][y]) q.emplace(x-1u, y);
				if(!b[x][y-1u]) q.emplace(x, y-1u);

				vs.push_back(cv);
				auto &cv0 = cv, &cv1 = *(v[x][y-1u] = vs.end()-1);

				if(it1 == cv.end()) cv1.emplace_back(a[x][y-1u]);
				else cv1[idx1] = max(cv1[idx1], static_cast<u1>(a[x][y-1u]));
				if(it0 == cv.end()) cv0.emplace_back(a[x-1u][y]);
				else *it0 = max(*it0, static_cast<u1>(a[x-1u][y]));

				mx = max(mx, static_cast<decltype(mx)>(max(idx0, idx1)));
				b[x-1u][y] = idx0, b[x][y-1u] = idx1;
				v[x-1u][y] = v[x][y];
				break;
			}

			default: __builtin_unreachable();
			}

			break;
		}

		default: __builtin_unreachable();
		}
	}

	cout<<static_cast<uf2>(mx);

	return 0;
}
//; echo """
