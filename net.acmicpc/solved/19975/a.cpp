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

	constexpr hash<string_view> h;
	unordered_map<size_t, char[32]> mm;
	array<size_t, 50> a;
	unordered_map<size_t, pair<u4, bool>> aa;
	array<pair<array<char[128], 10>, u4>, 50> li;

	constexpr auto f1 = [](char *s) -> char* {
		if(0x60 < s[0]) s[0] -= 0x20;
		return s;
	};

	u2 n;
	cin>>n;
	for(u2 i=n; i--;){
		char s[32], _s[32];
		cin>>s;
		memcpy(_s, s, sizeof(s));
		const size_t hh = h(f1(s));
		memcpy(mm[hh], _s, sizeof(s));
		a[i] = hh;
		aa.emplace(hh, pair{i, true});

		u2 m;
		cin>>m;
		while(m--){
			cin>>s;
			const size_t hhh = h(f1(s));
			memcpy(mm[hhh], s, sizeof(s));
			aa.emplace(hhh, pair{i, false});
		}


		cin>>m;
		li[i].second = m;
		DEBUG cout<<"C i: "<<i<<" m: "<<m<<endl;
		cin.ignore(numeric_limits<streamsize>::max(), 10);
		while(m--) cin.getline(li[i].first[m], 128);
	}

	DEBUG for(u2 i=n; i--;){
		cout<<i<<" "<<mm[a[i]]<<endl;
		DEBUG for(u2 j=li[i].second; j--;)
			cout<<li[i].first[j]<<endl;
	}

	constexpr auto b = [](){
		array<u1, 128> b{};
		for(u1 i=26; i--;)
			b[i+0x41] = b[i+0x61] = 1;
		return b;
	}();

	DEBUG cout<<"B "<<n<<endl;
	while(n--){
		cout<<mm[a[n]]<<'\n';
		while(li[n].second--){
			const auto m = li[n].second;
			ostringstream oss;
			char ts[128];
			memcpy(ts, li[n].first[m], sizeof(ts));

			for(u2 i=0, j; ts[i]; i=j){
				j = i+1;
				if(!b[li[n].first[m][i]]){
					oss<<li[n].first[m][i];
					continue;
				}
				for(; ts[j]; ++j) if(!b[li[n].first[m][j]]) break;

				const auto sv = string_view(f1(ts+i), j-i);
				const auto _sv = string_view(li[n].first[m]+i, j-i);
				const auto hh = h(sv);

				if(const auto it = aa.find(hh); it != aa.end()){
					if(it->second.first == n) goto print;
					if(it->second.second) oss<<"[["<<_sv<<"]]";
					else oss<<"[["<<mm[a[it->second.first]]<<'|'<<_sv<<"]]";
					continue;
				}

			print:
				oss<<_sv;
			}
			cout<<oss.str()<<'\n';
			// DEBUG for(u2 i=0; oss.str()[i] || (cout<<endl, 0); i++)
			// 	cout<<hex<<+oss.str()[i]<<' ';
		}
	}

	return 0;
}
AFESDJPOI
;
