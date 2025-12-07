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
#include<complex>
#include<cmath>
#include<cstring>
#define AFESDJPOI asm("nop")
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

class C{
public:
	template<class T, size_t _N>
	requires is_floating_point_v<T> && (0 < _N)
	static void f(array<complex<T>, _N> &a, const complex<T> w_n){
		constexpr size_t N = 1z << (numeric_limits<size_t>::digits - countl_zero(_N-1));

		array<complex<T>, N> aa;
		aa.fill(0);
		copy(a.begin(), a.end(), aa.begin());

		ff(aa, w_n);

		copy(aa.begin(), aa.begin()+_N, a.begin());
	}

private:
	template<class T, size_t N>
	requires is_floating_point_v<T> && (popcount(N) == 1)
	static void ff(array<complex<T>, N> &a, const complex<T> w_n){
		array<complex<T>, N/2> o, e;

		for(size_t i=N/2; i--;){
			e[i] = a[2*i];
			o[i] = a[2*i+1];
		}

		ff(e, w_n*w_n), ff(o, w_n*w_n);

		complex<T> w = 1;
		for(size_t i=0; i<N/2; w *= w_n, ++i){
			a[i] = e[i] + w*o[i];
			a[i+N/2] = e[i] - w*o[i];
		}
	}

	template<class T>
	static void ff(array<complex<T>, 1> &a, const complex<T> w_n){ return; }
};

template<class T, size_t N, size_t M, size_t K = 1z << (numeric_limits<size_t>::digits - countl_zero(N+M-1))>
requires is_floating_point_v<T> && (0 < N) && (0 < M)
	&& (1z << (numeric_limits<size_t>::digits - countl_zero(N+M-1)) <= K)
array<complex<T>, K> mul(array<complex<T>, N> &a, array<complex<T>, M> &b){
	const complex<T> w_k = polar<T>(1, 2*numbers::pi_v<T>/K);

	array<complex<T>, K> aa, bb;
	aa.fill(0), bb.fill(0);
	copy(a.begin(), a.end(), aa.begin());
	copy(b.begin(), b.end(), bb.begin());

	C::f(aa, w_k), C::f(bb, w_k);

	array<complex<T>, K> r;
	for(size_t i=K; i--;)
		r[i] = aa[i]*bb[i];

	C::f(r, complex<T>(1,0)/w_k);
	for(size_t i=K; i--;)
		r[i] /= static_cast<T>(K);
	return r;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	string s0, s1;
	cin>>s0>>s1;

	array<complex<f8>, 500'000> a, b;
	a.fill(0), b.fill(0);

	constexpr auto f = []<size_t K, class T, size_t N>(string_view s, array<complex<T>, N> &a){
		auto p = s.rbegin();
		for(auto q = a.begin(); p != s.rend(); ++q){
			u8 v = 0, d = 1;
			for(auto eit = min(s.rend(), p+K); p != eit; ++p, d*=10)
				v += d*static_cast<u8>(*p - 0x30);
			*q = static_cast<T>(v);
		}
	};

	f.template operator()<2>(s0, a), f.template operator()<2>(s1, b);
	DEBUG{
		for(size_t i=0; i<10; ++i)
			cout<<a[i].real()<<" ";
		cout<<"\n";
		for(size_t i=0; i<10; ++i)
			cout<<b[i].real()<<" ";
		cout<<"\n";
	}

	auto r = mul(a, b);

	constexpr auto g = []<size_t K, class T, size_t N>(const array<complex<T>, N> &a){
		constexpr u8 b = []{
			u8 v = 1;
			for(size_t i=K; i--; v *= 10);
			return v;
		}();

		string r;
		r.reserve(N*K);

		u8 c = 0;
		for(size_t i=0; i<N; ++i){
			u8 v = static_cast<u8>(a[i].real() + 0.5) + c;
			c = v/b, v %= b;
			for(size_t j=0; j<K; ++j){
				r.push_back(static_cast<char>(v%10) + 0x30);
				v /= 10;
			}
		}

		for(; c; c /= 10)
			r.push_back(static_cast<char>(c%10) + 0x30);

		while(r.size() > 1 && r.back() == 0x30) r.pop_back();
		return string(r.rbegin(), r.rend());
	};

	cout<<g.template operator()<2>(r);

	return 0;
}

AFESDJPOI
;
