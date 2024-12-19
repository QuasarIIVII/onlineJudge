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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

inline bool isMoo(const char *s){
	return s[0] != s[1] && s[1] == s[2];
}

inline if1 mayError(const char *s, char ci, char cj){
	if((s[0] == ci) + (s[1] == cj) + (s[2] == cj) != 2) return -1;
	if(s[1] != cj) return 1;
	if(s[2] != cj) return 2;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n, f;
	array<array<list<uf2>,26>,26> l;
	vector<array<uf1,2>> v;
	array<array<bool,26>,26> vv={0,};
	cin>>n>>f;
	char s[20001];
	cin>>s;
//momoobaaaaaqqqcqq
	for(uf2 i=n-2; i--;){
		if(isMoo(s+i))
			l[s[i]-97][s[i+1]-97].push_back(i);
	}

	for(uf1 i=0;i<26;++i)for(uf1 j=0;j<26;++j){
		if(i==j) continue;
		switch(f - l[i][j].size()){
		case 0:
			if(!vv[i][j])
				vv[i][j]=true,
				v.push_back({i,j});
			break;
		case 1:
			for(uf2 k=n-2; k--;){
				uf2 p;
				if(if1 r = mayError(s+k, i+97, j+97); r+1)
					p = k+r;
				else continue;

				bool flg=true;
				for(auto& a:l[i][j])if(a<=p && p<=a+2){flg=false;break;}
				if(flg && !vv[i][j])
					vv[i][j]=true,
					v.push_back({i,j});
			}
			break;
		default:break;
		}
		
	}

	sort(v.begin(), v.end(), [](const auto& p, const auto& q){return p[0]==q[0] ? p[1]<q[1] :p[0]<q[0];});

	cout<<v.size()<<'\n';
	for(const auto& a:v)
		cout<<static_cast<char>(a[0]+97)<<static_cast<char>(a[1]+97)<<static_cast<char>(a[1]+97)<<'\n';

	return 0;
}

