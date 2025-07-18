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

class C{
private:
	const uf2 n;
	const uf2 x;
	const C *l, *r;

public:
	struct S{
		const unordered_map<uf2, uf2> &in_m;
		const array<uf2, 1'000> &pre, &in;
		varray<C, 1'024> &obj;
	};

public:
	C(): n(0), x(0), l(nullptr), r(nullptr){ memset(this, 0, sizeof(C)); }

	C(const S& init, const uf2 sz)
	:n(init.pre[0])
	,x(init.in_m.find(n)->second)
	,l(
		x
		? (
			init.obj.push_back(C(
				init,
				1, x+1u,
				0, x
			)),
			&init.obj.back()
		)
		: nullptr
	)
	,r(
		x+1u != sz
		? (
			init.obj.push_back(C(
				init,
				x+1u, sz,
				x+1u, sz
			)),
			&init.obj.back()
		)
		: nullptr
	)
	{}

	C(
		const S& init,
		const uf2 pre_s, const uf2 pre_e,
		const uf2 in_s, const uf2 in_e
	)
	:n(init.pre[pre_s])
	,x(init.in_m.find(n)->second)
	,l(
		in_s != x
		? (
			init.obj.push_back(C(
				init,
				pre_s+1u, pre_s+1u + x-in_s,
				in_s, x
			)),
			&init.obj.back()
		)
		: nullptr
	)
	,r(
		x+1u != in_e
		? (
			init.obj.push_back(C(
				init,
				pre_s + x-in_s+1u, pre_e,
				x+1u, in_e
			)),
			&init.obj.back()
		)
		: nullptr
	)
	{
		DEBUG cout<<"C::C(2): "<<pre_s<<':'<<pre_e<<'\t'<<in_s<<':'<<in_e<<endl;
	}

	C& operator=(C&& other){
		memcpy(this, &other, sizeof(C));
		return *this;
	}

	template<class OS>
	void f(OS &oss) const {
		if(l) l->f(oss);
		if(r) r->f(oss);
		oss<<n<<' ';
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(false);

	DEBUG{
		struct X{
			vector<int> v;
		};

		varray<X, 100> cva;
		varray<int, 100> va{1,2,3};
		cout<<va.size()<<' '<<va.capacity()<<endl;
		cout<<(va.back()=4)<<' '<<va.back()<<endl;

		for(const auto& a:va) cout<<a<<' ';
		cout<<endl;

		{
			cout<<"==== 1 ====\n";
			varray<int, 100> va1(va);
			for(auto it = va1.crbegin(); it != va1.crend() || (cout<<endl, 0); it++)
				cout<<*it<<' ';
		}

		{
			cout<<"==== 2 ====\n";
			varray<int, 100> va1{1,2,9};
			va.swap(va1);
			for(const auto& a:va) cout<<a<<' ';
			cout<<endl;
			for(const auto& a:va1) cout<<a<<' ';
			cout<<endl;

			va1 = va;
			for(const auto& a:va1) cout<<a<<' ';
			cout<<endl;
		}

		{
			cout<<"==== 3 ====\n";
			struct Y{
				int n;
				Y():n(9){}
				Y(int n):n(n){}
			};

			varray<Y, 100> va1{1,2,3};
			va1 = {1,4,6,9};
			Y y;
			va1.push_back(y);
			va1.push_back(123);
			va1.resize(8);

			for(const auto& a:va1) cout<<a.n<<' ';
			cout<<endl;

			va1.clear();
			cout<<va1.size()<<endl;
		}

		// return 0;
	}

	uf4 T;
	if(!(cin>>T)) return (cout<<"~E\n", 0);

	unordered_map<uf2, uf2> in_m;
	varray<C, 1024> va;
	in_m.reserve(1024);

	ostringstream oss;

	while(T--){
		in_m.clear();
		va.clear();

		uf2 n;
		array<uf2, 1'000> pre, in;

		[[assume(n <= 1000)]];
		cin>>n;

		for(uf2 i=0; i<n; ++i)
			cin>>pre[i];

		for(uf2 i=0; i<n; ++i){
			uf4 x;
			cin>>x;
			in[i] = x;
			in_m.emplace(x, i);
		}

		C(C::S{in_m, pre, in, va}, in_m.size()).f(cout);
		cout<<'\n';
	}
	return 0;
}
//; echo """
