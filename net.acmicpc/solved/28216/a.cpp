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

	uf4 N, Q;
	cin>>N>>Q;

	array<vector<pair<uf4, uf4>>, 200'001> ax, ay;
	{
		array<tuple<uf4, uf4, uf4>, 200'000> b;
		array<uf4, 200'001> cx{0, }, cy{0, };

		for(uf4 i=N; i--;){
			auto &[p, q, w]=b[i];
			cin>>p>>q>>w;
			++cx[p], ++cy[q];
		}

		sort(b.begin(), b.begin()+N);

		for(uf4 i=200'001; i--;){
			ax[i].reserve(cx[i]+1);
			ax[i].emplace_back(0, 0);
			ay[i].reserve(cy[i]+1);
			ay[i].emplace_back(0, 0);
		}

		for(uf4 i=0; i<N; ++i){
			const auto &[p, q, w]=b[i];
			ax[p].emplace_back(q, ax[p].back().second + w);
			ay[q].emplace_back(p, ay[q].back().second + w);
		}

		DEBUG{
			for(uf4 i=0; i<ax.size(); ++i){
				if(ax[i].size()<=1) continue;
				cout<<"ax["<<i<<"] : ";
				for(const auto &[p, w]:ax[i]){
					cout<<"("<<p<<","<<w<<") ";
				}
				cout<<"\n";
			}
			for(uf4 i=0; i<ay.size(); ++i){
				if(ay[i].size()<=1) continue;
				cout<<"ay["<<i<<"] : ";
				for(const auto &[p, w]:ay[i]){
					cout<<"("<<p<<","<<w<<") ";
				}
				cout<<"\n";
			}
		}
	}

	uf8 r = 0;
	pair<uf4, uf4> p{1, 1};
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	constexpr auto f = [](const pair<uf4, uf4> &a, const pair<uf4, uf4> &b){ return a.first < b.first; };
	while(Q--){
		char dr;
		uf4 ds;
		cin>>dr>>ds;
		// 0x30 : +x
		// 0x31 : +y
		// 0x32 : -x
		// 0x33 : -y

		switch(dr){
		case 0x30:{
			const uf4 q = p.first + ds;
			const auto its
				= upper_bound(ay[p.second].begin(), ay[p.second].end(), pair<uf4, uf4>{p.first, 0}, f)-1;
			const auto ite
				= upper_bound(ay[p.second].begin(), ay[p.second].end(), pair<uf4, uf4>{q, 0}, f)-1;
			DEBUG cout<<"x from "<<p.first<<" to "<<q<<"\t"
				<<(its-ay[p.second].begin())<<':'<<ay[p.second][its-ay[p.second].begin()].second<<" to "
				<<(ite-ay[p.second].begin())<<':'<<ay[p.second][ite-ay[p.second].begin()].second<<"\n";
			r += ite->second - its->second;
			p.first = q;
			break;
		}
		case 0x31:{
			const uf4 q = p.second + ds;
			const auto its
				= upper_bound(ax[p.first].begin(), ax[p.first].end(), pair<uf4, uf4>{p.second, 0}, f)-1;
			const auto ite
				= upper_bound(ax[p.first].begin(), ax[p.first].end(), pair<uf4, uf4>{q, 0}, f)-1;
			DEBUG cout<<"y from "<<p.second<<" to "<<q<<"\t"
				<<(its-ax[p.first].begin())<<':'<<ax[p.first][its-ax[p.first].begin()].second<<" to "
				<<(ite-ax[p.first].begin())<<':'<<ax[p.first][ite-ax[p.first].begin()].second<<"\n";
			r += ite->second - its->second;
			p.second = q;
			break;
		}
		case 0x32:{
			const uf4 q = p.first - ds;
			const auto its
				= lower_bound(ay[p.second].begin(), ay[p.second].end(), pair<uf4, uf4>{p.first, 0}, f)-1;
			const auto ite
				= lower_bound(ay[p.second].begin(), ay[p.second].end(), pair<uf4, uf4>{q, 0}, f)-1;
			DEBUG cout<<"x from "<<p.first<<" to "<<q<<"\t"
				<<(its-ay[p.second].begin())<<':'<<ay[p.second][its-ay[p.second].begin()].second<<" to "
				<<(ite-ay[p.second].begin())<<':'<<ay[p.second][ite-ay[p.second].begin()].second<<"\n";
			r += its->second - ite->second;
			p.first = q;
			break;
		}
		case 0x33:{
			const uf4 q = p.second - ds;
			const auto its
				= lower_bound(ax[p.first].begin(), ax[p.first].end(), pair<uf4, uf4>{p.second, 0}, f)-1;
			const auto ite
				= lower_bound(ax[p.first].begin(), ax[p.first].end(), pair<uf4, uf4>{q, 0}, f)-1;
			DEBUG cout<<"y from "<<p.second<<" to "<<q<<"\t"
				<<(its-ax[p.first].begin())<<':'<<ax[p.first][its-ax[p.first].begin()].second<<" to "
				<<(ite-ax[p.first].begin())<<':'<<ax[p.first][ite-ax[p.first].begin()].second<<"\n";
			r += its->second - ite->second;
			p.second = q;
			break;
		}
		default: __builtin_unreachable();
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	cout<<r;
	return 0;
}
//; echo """
