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

constexpr auto pow3 = [](){
	array<uf4, 21> a;
	a[0] = 1;
	for(auto it = a.begin()+1; it != a.end(); ++it)
		*it = *(it-1) * 3;

	return a;
}();

class A : public array<uf4, 3>{
public:
	constexpr A operator+(const A& other) const{
		return A{operator[](0) + other[0], operator[](1) + other[1], operator[](2) + other[2]};
	}
	constexpr operator bool() const{
		return operator[](0) | operator[](1) | operator[](2);
	}
};

array<array<pair<bool, A>, 3>, 21> t;

uf4 N;
pair<bool, A> f(const uf2 m,const uf4 p, const uf4 n, const uf4 l, const uf4 r){
	[[assume(1<=m && m<=3)]];

	DEBUG for(uf4 i = N-n; i--; )cout<<"    ";
	DEBUG cout<<m<<' '<<p<<' '<<n<<' '<<l/pow3[n]<<' '<<r/pow3[n]<<' ';

	if(p < l/pow3[n] || r/pow3[n] < p){
		DEBUG cout<<"outofbounds"<<endl;
		return {false, A{0, 0, 0}};
	}

	const uf1 mm = m-1;
	if(t[n][mm].first && l <= p*pow3[n] && (p+1)*pow3[n] <= r+1){
		DEBUG cout<<"cache hit"<<endl;
		return {true, t[n][mm].second};
	}

	if(!n){
		DEBUG cout<<"leaf"<<endl;
		switch(m){
		case 1: return t[n][mm].first = true, pair<bool, A>{true, t[n][mm].second = A{1, 0, 0}};
		case 2: return t[n][mm].first = true, pair<bool, A>{true, t[n][mm].second = A{0, 1, 0}};
		case 3: return t[n][mm].first = true, pair<bool, A>{true, t[n][mm].second = A{0, 0, 1}};
		}
	}

	const uf4 p3 = p*3;
	const uf4 nn = n-1;
	DEBUG cout<<"call"<<endl;
	pair<bool, A> _1, _2, _3;
	switch(m){
	case 1:
		_1 = f(1, p3, nn, l, r);
		_2 = f(3, p3+1, nn, l, r);
		_3 = f(2, p3+2, nn, l, r);
		if(_1.first && _2.first && _3.first){
			t[n][mm].first = true;
			return {true, t[n][mm].second = _1.second + _2.second + _3.second};
		}else return {false, _1.second + _2.second + _3.second};
	case 2:
		_1 = f(2, p3, nn, l, r);
		_2 = f(1, p3+1, nn, l, r);
		_3 = f(1, p3+2, nn, l, r);
		if(_1.first && _2.first && _3.first){
			t[n][mm].first = true;
			return {true, t[n][mm].second = _1.second + _2.second + _3.second};
		}else return {false, _1.second + _2.second + _3.second};
	case 3:
		_1 = f(2, p3, nn, l, r);
		_2 = f(3, p3+1, nn, l, r);
		_3 = f(2, p3+2, nn, l, r);
		if(_1.first && _2.first && _3.first){
			t[n][mm].first = true;
			return {true, t[n][mm].second = _1.second + _2.second + _3.second};
		}else return {false, _1.second + _2.second + _3.second};
	}

	return {false, A{0, 0, 0}};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int m, n, l, r;
	cin>>m>>l>>r>>n;
	N = n;

	auto a = f(m, 0, n, l, r).second;
	cout<<a[0]<<' '<<a[1]<<' '<<a[2];
	return 0;
}

