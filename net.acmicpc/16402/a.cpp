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

struct S;
unordered_map<string_view, S> m;
struct S{
	S* p = this;

	bool isRoot() const{
		return p==this;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 n, nq;
	cin>>n>>nq;
	for(uf4 i=n; i--; ){
		string s;
		cin.ignore(numeric_limits<std::streamsize>::max(), 'f');

		cin>>s;
		{
			cout<<"in "<<s<<endl;
			auto& t = m.emplace(s, S()).first->second;
			t.p = &t;
	
	}

	for(uf4 i=nq; i--; ){
		string s, ss;

		cin.ignore(numeric_limits<std::streamsize>::max(), 'f'), cin.ignore();
		std::getline(cin, s, ',');
		auto& p = m[s];

		cin.ignore(numeric_limits<std::streamsize>::max(), 'f'), cin.ignore();
		std::getline(cin, ss, ',');
		auto& q = m[ss];
		cout<<"p "<<s<<' '<<&p<<' '<<p.p<<endl;
		cout<<"q "<<ss<<' '<<&q<<' '<<q.p<<endl;
	}
	return 0;
}

