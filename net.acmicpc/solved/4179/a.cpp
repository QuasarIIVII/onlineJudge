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
#include<unistd.h>
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

template<class T, u1 _N>
class Q{
private:
	constexpr static size_t N = 1z << _N;
	constexpr static size_t M = N-1;
	array<T, N> a;
	size_t p, q, sz;

public:
	Q(): p(0), q(0), sz(0) {}

	void push(const T &v){
		a[p++] = v;
		p &= M;
		++sz;
	}
	void push(T &&v){
		a[p++] = move(v);
		p &= M;
		++sz;
	}
	void emplace(auto&&... args){
		a[p++] = T(forward<decltype(args)>(args)...);
		p &= M;
		++sz;
	}

	void pop(){
		++q &= M;
		--sz;
	}

	const T& front() const { return a[q]; }
	size_t size() const { return sz; }
	bool empty() const { return !sz; }
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf2 n=0, m=0;
	array<array<u1, 1024>, 1000> a{};
	array<Q<pair<u2, u2>, 13>, 2> qj, qf;

	{
		constexpr auto w = []{
			array<u1, 128> a{};
			a[0x20] = 1; a[0x0a] = 1;
			a[0x0d] = 1; a[0x09] = 1;
			a[0x0b] = 1; a[0x0c] = 1;
			return a;
		}();

		array<char, 1000*1001+64> in;
		uf4 pin = 0;
		syscall(0, 0, in.data(), in.size());

		while(!w[in[pin]] || (++pin, 0))
			n = n*10 + (in[pin++] & 0x0f);
		while(!w[in[pin]] || (++pin, 0))
			m = m*10 + (in[pin++] & 0x0f);

		for(uf2 i=n; i--; ++pin)for(uf2 j=m; j--; ++pin){
			if(!(in[pin] & 0x40)){
				a[i][j] = in[pin]=='.' ? 0 : 1;
			}else if(in[pin]=='F'){
				a[i][j] = 2;
				qf[0].emplace(i, j);
			}else{
				a[i][j] = 0x10;
				qj[0].emplace(i, j);
			}
		}
	}

	DEBUG for(uf2 i=n; i--; cout<<endl)for(uf2 j=m; j--;)
		cout<<+a[i][j];

	for(uf4 c = 0;;++c){
		DEBUG cout<<c<<endl;
		auto &qfc = qf[c&1], &qfn = qf[c&1^1];
		auto &qjc = qj[c&1], &qjn = qj[c&1^1];

		for(; qjc.size(); qjc.pop()){
			const auto &[p, q] = qjc.front();
			DEBUG cout<<"J "<<p<<','<<q<<' '<<+a[p][q]<<'\n';
			if(!(a[p][q]&0xf) && (!p || !q || p+1u==n || q+1u==m)){
				cout<<c+1u;
				return 0;
			}

			const array<pair<u2, u2>, 4> nxts{
				make_pair(p+1u, q),
				make_pair(p-1u, q),
				make_pair(p, q+1u),
				make_pair(p, q-1u)
			};

			for(const auto &[np, nq] : nxts){
				if(n<=np || m<=nq || a[np][nq]) continue;
				a[np][nq] |= 0x10;
				qjn.emplace(np, nq);
			}
		}

		if(qjn.empty()){
			cout<<"IMPOSSIBLE";
			return 0;
		}

		for(; qfc.size(); qfc.pop()){
			const auto &[p, q] = qfc.front();

			const array<pair<u2, u2>, 4> nxts{
				make_pair(p+1u, q),
				make_pair(p-1u, q),
				make_pair(p, q+1u),
				make_pair(p, q-1u)
			};

			for(const auto &[np, nq] : nxts){
				if(n<=np || m<=nq || a[np][nq]&0xf) continue;
				a[np][nq] = 2;
				DEBUG cout<<"F "<<np<<','<<nq<<'\n';
				qfn.emplace(np, nq);
			}
		}
	}

	return 0;
}
AFESDJPOI
;
