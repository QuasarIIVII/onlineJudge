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

struct S{
	S* p;

	bool isRoot() const{
		return p==this;
	}
	S& root(){
		DEBUG cout<<this<<" root() [p = "<<p<<"] : "<<flush;
		while(p != p->p) p = p->p;
		DEBUG cout<<p<<endl;
		return *p;
	}
	S& join(S& to){
		DEBUG cout<<this<<" join("<<&to<<")"<<endl;
		p = &to.root();
		return *this;
	}
	S& xchgrt(){
		DEBUG cout<<this<<" xchgrt()"<<endl;
		p = root().p = this;
		return *this;
	}

	bool operator==(const S& other) const{
		return this == &other;
	}
};

unordered_map<string, S*> m;
array<string, 500> ss;
array<S, 500> objs;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf4 n, nq;
	cin>>n>>nq;
	for(uf4 i=n; i--; ){
		string s;
		cin.ignore(numeric_limits<std::streamsize>::max(), 'f');

		cin>>s;
		ss[i] = s;
		m.emplace(s, &objs[i]);
		auto &t = *m[ss[i]];
		t.p = &t;
		DEBUG cout<<ss[i]<<'\t'<<m[ss[i]]<<' '<<m[ss[i]]->p<<endl;
	}

	sort(ss.begin(), ss.begin()+n, greater());

	for(uf4 i=nq; i--; ){
		uf4 n;
		string s, ss;

		cin.ignore(numeric_limits<std::streamsize>::max(), 'f'), cin.ignore();
		std::getline(cin, s, ',');
		auto& p = *m[s];

		cin.ignore(numeric_limits<std::streamsize>::max(), 'f'), cin.ignore();
		std::getline(cin, ss, ',');
		auto& q = *m[ss];

		cin>>n;

		if(p.root() == q.root()){
			if(p.isRoot()){
				if(n==2)q.xchgrt();
			}else if(n==1)p.xchgrt();
		}else
			n==1 ? q.root().join(p) : p.root().join(q);

		DEBUG cout<<endl;
	}

	ostringstream oss;
	uf4 c=0;
	for(uf4 i=n; i--; ){
		DEBUG cout<<ss[i]<<'\t'<<m[ss[i]]<<' '<<m[ss[i]]->p<<endl;
		if(m[ss[i]]->isRoot()){
			++c;
			oss<<"Kingdom of "<<ss[i]<<'\n';
		}
	}
	cout<<c<<'\n'<<oss.str();
	return 0;
}

