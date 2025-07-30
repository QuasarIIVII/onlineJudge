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
#include<cmath>
#include<cstring>
//; echo """

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

template<class T, size_t N>
class varray : public array<T, N>{
	size_t n;

public:
	// (constructors)
	constexpr varray()noexcept:array<T, N>{}, n(0){}

	constexpr varray(std::initializer_list<T> init) noexcept
	:array<T, N>{}
	,n(init.size())
	{ std::copy(init.begin(), init.end(), this->begin()); }

	constexpr varray(const varray& other) noexcept
	:array<T, N>{}
	,n(other.n)
	{ std::copy(other.cbegin(), other.cend(), this->begin()); }

	// operator=
	constexpr varray& operator=(initializer_list<T> init) noexcept {
		n = init.size();
		std::copy(init.begin(), init.end(), this->begin());
		return *this;
	}

	constexpr varray& operator=(const varray& other) noexcept {
		n = other.n;
		std::copy(other.cbegin(), other.cend(), this->begin());
		return *this;
	}

public:
	// capacity
	constexpr typename varray::size_type size() const noexcept { return n; }
	constexpr bool empty() const noexcept { return !n; }
	consteval typename varray::size_type capacity() { return N; }

	// element access
	constexpr typename varray::reference back(){ return this->operator[](n-1); }
	constexpr typename varray::const_reference back() const { return this->operator[](n-1); }

	// iterators
	constexpr typename varray::iterator end() noexcept { return this->begin()+n; }
	constexpr typename varray::const_iterator cend() const noexcept { return this->cbegin()+n; }

	constexpr typename varray::reverse_iterator rbegin() noexcept { return this->rend()-n; }
	constexpr typename varray::const_reverse_iterator crbegin() const noexcept { return this->crend()-n; }

	// modifiers
	constexpr void clear() noexcept { n = 0; }
	constexpr void push_back(const T& val) noexcept { this->operator[](n++) = val; }
	constexpr void push_back(T&& val) noexcept { this->operator[](n++) = move(val); }
	constexpr void resize(typename varray::size_type cnt) noexcept { n = cnt; }
	constexpr void swap(varray& other) noexcept {
		array<T, N>::swap(other);
		std::swap(n, other.n);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	array<varray<if4, 3>, 2> a;
	a.fill({0});

	uf4 n;
	cin>>n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	uf4 mx = 0;

	for(uf4 i=n; i--;){
		char c, _;
		cin>>c;
		cin.ignore(numeric_limits<streamsize>::max(), ' ');

		 // negative, positive max
		if4 nmx=numeric_limits<if4>::max();
		if4 pmx=numeric_limits<if4>::min();
		for(const auto& aa : a[i+1 & 1]){
			const if4 aaa = c&1 ? aa+1 : aa-1;
			nmx=min(nmx, aaa);
			pmx=max(pmx, aaa);
		}

		a[i&1] = {0};
		if(nmx<0) a[i&1].push_back(nmx);
		if(pmx>0) a[i&1].push_back(pmx);

		mx = max(static_cast<uf4>(max(abs(nmx), abs(pmx))), mx);
	}
	cout<<mx;
	return 0;
}
//; echo """
