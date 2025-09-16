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

template<class tp, class Ita, class Itb>
requires random_access_iterator<Ita> && random_access_iterator<Itb>
&& same_as<typename tp::first_type, typename tp::second_type>
uf4 g(const Ita srcs, const Ita srce, Itb itx, Itb ity, Itb itt){
	using tval = tp::first_type;

	const auto dist = [&](const uf4 a, const uf4 b) constexpr {
		const if4 dx = srcs[a].first - srcs[b].first, dy = srcs[a].second - srcs[b].second;
		return static_cast<uf4>(dx*dx + dy*dy);
	};

	const function<uf4(const Itb, const Itb, const Itb, const tval tp::*, const tval tp::*)> f = [&](
		const Itb s0, const Itb e0, const Itb s1,
		const tval tp::* first, const tval tp::* second
	) -> uf4 {
		DEBUG{
			if(first == &tp::first){
				cout<<"A ";
				for(Itb i = s0; i!=e0; ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<"| ";
				for(Itb i = s1; i!=s1+(e0-s0); ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<endl;
			}else{
				cout<<"B ";
				for(Itb i = s1; i!=s1+(e0-s0); ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<"| ";
				for(Itb i = s0; i!=e0; ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<endl;
			}
		}

		const size_t n = e0 - s0;
		if(n < 4){
			uf4 mn = numeric_limits<uf4>::max();
			for(Itb i=e0; --i != s0;) for(Itb j=i; j-- != s0;)
				mn = min(mn, dist(*i, *j));

			return mn;
		}

		const Itb e1 = s1 + n;

		const Itb m0 = s0 + n/2, m1 = s1 + n/2;
		const tval med = (srcs[*(m0-1)].*first + srcs[*m0].*first) / 2;

		{
			bitset<100'000> b;

			for(Itb i=m0; i-- != s0;) b.set(*i);

			Itb t0 = itt, t1 = itt + n/2;
			for(Itb i=s1; i!=e1; ++i){
				if(b.test(*i)) *t0++ = *i;
				else *t1++ = *i;
			}

			copy(itt, itt+n, s1);
		}

		uf4 d = min(f(s1, m1, s0, second, first), f(m1, e1, m0, second, first));

		merge(s1, m1, m1, e1, itt, [&](const uf4 a, const uf4 b){
			return srcs[a].*second < srcs[b].*second;
		});
		copy(itt, itt+n, s1);

		DEBUG{
			if(first == &tp::first){
				cout<<"A ";
				for(Itb i = s0; i!=e0; ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<"| ";
				for(Itb i = s1; i!=s1+(e0-s0); ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<endl;
			}else{
				cout<<"B ";
				for(Itb i = s1; i!=s1+(e0-s0); ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<"| ";
				for(Itb i = s0; i!=e0; ++i)
					cout<<srcs[*i].first<<','<<srcs[*i].second<<" ";
				cout<<endl;
			}
		}

		uf4 tap = 0;
		array<uf4, 100'000> ta;

		for(Itb i = e1; i-- != s1;){
			if(if4 diff = srcs[*i].*first - med; diff*diff <= d)
				ta[tap++] = *i;
		}

		DEBUG cout<<"tap "<<tap<<endl;

		if(tap)for(Itb i=ta.begin()+tap; --i != ta.begin();){
			for(Itb j=i;
				j-- != ta.begin()
				&& (srcs[*j].*second - srcs[*i].*second)*(srcs[*j].*second - srcs[*i].*second) < d;
			) d = min(d, dist(*i, *j));
		}

		return d;
	};

	return f(itx, itx+(srce-srcs), ity, &tp::first, &tp::second);
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 n;
	cin>>n;

	using tp = pair<if2, if2>;

	array<tp, 100'000> a;
	array<uf4, 100'000> a0, a1, ta;

	for(uf4 i=n; i--;)
		cin>>a[i].first>>a[i].second;

	for(uf4 i=n; i--;) a0[i] = a1[i] = i;

	sort(a0.begin(), a0.begin()+n, [&](const uf4 p, const uf4 q){
		return a[p].first < a[q].first || (a[p].first == a[q].first && a[p].second < a[q].second);
	});

	sort(a1.begin(), a1.begin()+n, [&](const uf4 p, const uf4 q){
		return a[p].second < a[q].second || (a[p].second == a[q].second && a[p].first < a[q].first);
	});

	cout<<g<tp>(a.begin(), a.begin()+n, a0.begin(), a1.begin(), ta.begin());

	return 0;
}
//; echo """
