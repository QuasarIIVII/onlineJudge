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

class C{
	uf4 n;
	vector<const C*> v;
public:
	C(const uf4 n): n(n) {}
	template<class PQ>
	C(PQ &pq, uf4 k): n(0), v(k){
		for(;k--; pq.pop()){
			v[k] = pq.top();
			n += v[k]->n;
		}
	}
	~C(){
		for(const C* p: v) delete p;
	}

	uf4 get() const { return n; }
	strong_ordering operator<=>(const C& other) const { return n <=> other.n; }

	uf4 f(uf4 d = 0) const {
		DEBUG cout<<string(d*2, ' ')<<"C(n="<<n<<")\n";
		if(v.empty()) return n*d;
		uf4 r = 0;
		for(const C* p: v) r += p->f(d+1);
		return r;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 T;

	for(cin>>T; T--;){
		uf4 n, k;
		cin>>n>>k;

		if(n == 1){
			uf4 x;
			cin>>x;
			cout<<x<<'\n';
			continue;
		}

		constexpr auto cmp = [](const C* a, const C* b){ return *a > *b; };
		priority_queue<const C*, vector<const C*>, decltype(cmp)> pq(cmp);
		for(uf4 i=n; i--;){
			uf4 x;
			cin>>x;
			pq.emplace(new C(x));
		}

		for(
			pq.emplace(new C(pq, 2+(n-2)%(k-1)));
			pq.size() != 1;
			pq.emplace(new C(pq, k))
		);

		cout<<pq.top()->f()<<"\n";
		delete pq.top();
	}
	return 0;
}

/* References:
 * https://github.com/rdbliss/huffman/blob/master/notes.pdf
 * https://en.wikipedia.org/wiki/Huffman_coding
 */

//; echo """
