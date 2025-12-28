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
#include<iomanip>
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
	constexpr typename varray::const_iterator end() const noexcept { return this->begin()+n; }
	constexpr typename varray::const_iterator cend() const noexcept { return this->cbegin()+n; }

	constexpr typename varray::reverse_iterator rbegin() noexcept { return this->rend()-n; }
	constexpr typename varray::const_reverse_iterator crbegin() const noexcept { return this->crend()-n; }

	// modifiers
	constexpr void clear() noexcept { n = 0; }
	constexpr void push_back(const T& val) noexcept { this->operator[](n++) = val; }
	constexpr void push_back(T&& val) noexcept { this->operator[](n++) = move(val); }
	template<class... As>
	constexpr void emplace_back(As&&... as) noexcept {
		this->operator[](n++) = T(forward<As>(as)...);
	}
	constexpr void pop_back() noexcept { --n; }
	constexpr void resize(typename varray::size_type cnt) noexcept { n = cnt; }
	constexpr void swap(varray& other) noexcept {
		array<T, N>::swap(other);
		std::swap(n, other.n);
	}
};

template<size_t N>
class I{
	array<u8,N> a{};

	static constexpr size_t limb_bits=sizeof(typename decltype(a)::value_type)*8;
	static constexpr size_t total_bits=N*limb_bits;

	constexpr static u8 lo(u16 x){return static_cast<u8>(x);}
	constexpr static u8 hi(u16 x){return static_cast<u8>(x>>limb_bits);}

	constexpr bool test_bit(size_t pos) const {
		// if(pos >= total_bits) return false;
		size_t li = pos/limb_bits;
		size_t off = pos%limb_bits;
		return (a[li]>>off) & 1u;
	}

	constexpr void set_bit(size_t pos){
		// if(pos >= total_bits) return;
		size_t li = pos/limb_bits;
		size_t off = pos%limb_bits;
		a[li] |= u8(1)<<off;
	}

	constexpr void shl1(){
		u8 carry=0;
		for(size_t i=0;i<N;++i){
			u16 v = static_cast<u16>(a[i])<<1 | carry;
			a[i] = lo(v);
			carry = hi(v);
		}
	}

	constexpr void shr1(){
		u8 carry=0;
		for(size_t i=N;i--;){
			u16 v = static_cast<u16>(carry)<<limb_bits | a[i];
			a[i] = static_cast<u8>(v>>1);
			carry = static_cast<u8>(v&1u);
		}
	}

public:
	// constexpr constructors
	constexpr I() = default;

	constexpr I(u8 x){
		a.fill(0);
		a[0]=x;
	}

	constexpr I(const I& other) = default;
	constexpr I(I&& other) noexcept = default;

	constexpr I(const array<u8,N>& a_): a(a_) {}
	constexpr I(array<u8,N>&& a_) noexcept : a(move(a_)) {}

	constexpr I& operator=(const I& other) = default;
	constexpr I& operator=(I&& other) noexcept = default;

	constexpr I& operator=(u8 x){
		a.fill(0);
		a[0]=x;
		return *this;
	}

	// conversion / comparison
	constexpr explicit operator bool() const {
		for(size_t i=N; i--;)
			if(a[i]) return true;
		return false;
	}

	constexpr strong_ordering operator<=>(const I& o) const {
		for(size_t i=N; i--;){
			if(a[i]<o.a[i]) return strong_ordering::less;
			if(a[i]>o.a[i]) return strong_ordering::greater;
		}
		return strong_ordering::equal;
	}

	constexpr bool operator==(const I& o) const = default;

	// --- addition / subtraction ---

	constexpr I operator+(const I& o) const {
		I r;
		u8 c = 0;
		for(size_t i=0; i<N; ++i){
			u16 s = static_cast<u16>(a[i])+o.a[i]+c;
			r.a[i] = lo(s);
			c = hi(s);
		}
		return r;
	}

	constexpr I operator+(u8 o) const {
		I r;
		u8 c = o;
		for(size_t i=0;i<N;++i){
			u16 s = static_cast<u16>(a[i])+c;
			r.a[i] = lo(s);
			c = hi(s);
		}
		return r;
	}

	constexpr I& operator+=(const I& o){
		*this = *this+o;
		return *this;
	}

	constexpr I& operator+=(u8 o){
		*this = *this+o;
		return *this;
	}

	constexpr I operator-() const {
		return (~*this)+u8(1);
	}

	constexpr I operator-(const I& o) const {
		return *this+(-o);
	}

	constexpr I operator-(u8 o) const {
		return *this+(-I(o));
	}

	constexpr I& operator-=(const I& o){
		*this = *this-o;
		return *this;
	}

	constexpr I& operator-=(u8 o){
		*this = *this-o;
		return *this;
	}

	// --- bitwise ops ---

	constexpr I operator~() const {
		I r;
		for(size_t i=0; i<N; ++i) r.a[i]=~a[i];
		return r;
	}

	constexpr I operator&(const I& o) const {
		I r;
		for(size_t i=0; i<N; ++i) r.a[i]=a[i]&o.a[i];
		return r;
	}

	constexpr I operator|(const I& o) const {
		I r;
		for(size_t i=0; i<N; ++i) r.a[i]=a[i]|o.a[i];
		return r;
	}

	constexpr I operator^(const I& o) const {
		I r;
		for(size_t i=0; i<N; ++i) r.a[i]=a[i]^o.a[i];
		return r;
	}

	constexpr I operator&(u8 v) const {
		return *this & I(v);
	}

	constexpr I operator|(u8 v) const {
		return *this | I(v);
	}

	constexpr I operator^(u8 v) const {
		return *this ^ I(v);
	}

	constexpr I& operator&=(const I& o){
		for(size_t i=0; i<N; ++i) a[i]&=o.a[i];
		return *this;
	}

	constexpr I& operator|=(const I& o){
		for(size_t i=0; i<N; ++i) a[i]|=o.a[i];
		return *this;
	}

	constexpr I& operator^=(const I& o){
		for(size_t i=0; i<N; ++i) a[i]^=o.a[i];
		return *this;
	}

	constexpr I& operator&=(u8 v){
		return *this &= I(v);
	}

	constexpr I& operator|=(u8 v){
		return *this |= I(v);
	}

	constexpr I& operator^=(u8 v){
		return *this ^= I(v);
	}

	// --- shifts by bit count ---

	constexpr I operator<<(size_t k)const{
		// if(!k)return *this;
		// if(k>=total_bits)return I{};
		I r{};
		size_t limb_shift=k/limb_bits;
		size_t bit_shift=k%limb_bits;
		for(size_t i=N;i--;){
			if(i<limb_shift)continue;
			u8 v = a[i-limb_shift]<<bit_shift;
			if(bit_shift && i>limb_shift)
				v |= a[i-limb_shift-1] >> (limb_bits-bit_shift);
			r.a[i]=v;
		}
		return r;
	}	

	constexpr I operator>>(size_t k)const{
		// if(!k)return *this;
		// if(k>=total_bits)return I{};
		I r{};
		size_t limb_shift=k/limb_bits;
		size_t bit_shift=k%limb_bits;
		for(size_t i=0;i<N;++i){
			if(i+limb_shift>=N)continue;
			u8 v = a[i+limb_shift]>>bit_shift;
			if(bit_shift && i+limb_shift+1<N)
				v |= a[i+limb_shift+1]<<(limb_bits-bit_shift);
			r.a[i]=v;
		}
		return r;
	}

	constexpr I& operator<<=(size_t k){
		*this = *this<<k;
		return *this;
	}

	constexpr I& operator>>=(size_t k){
		*this = *this>>k;
		return *this;
	}

	// --- multiplication ---

	constexpr I operator*(const I& o) const {
		I r;
		for(size_t i=0;i<N;++i){
			u8 c=0;
			for(size_t j=0;j+i<N;++j){
				u16 prod = static_cast<u16>(a[i])*o.a[j];
				u16 s = static_cast<u16>(r.a[i+j])+prod+c;
				r.a[i+j] = lo(s);
				c = hi(s);
			}
		}
		return r;
	}

	constexpr I operator*(u8 o) const {
		I r;
		u8 c=0;
		for(size_t i=0;i<N;++i){
			u16 prod = static_cast<u16>(a[i])*o+c;
			r.a[i] = lo(prod);
			c = hi(prod);
		}
		return r;
	}

	constexpr I& operator*=(const I& o){
		*this = *this*o;
		return *this;
	}

	constexpr I& operator*=(u8 o){
		*this = *this*o;
		return *this;
	}

	// --- division by scalar ---

	constexpr I operator/(u8 d) const {
		// behavior is undefined if d==0, matching built-in semantics
		I q;
		u16 rem = 0;
		for(size_t i=N;i--;){
			u16 cur = rem<<limb_bits | a[i];
			u16 qd = cur/d;
			rem = cur%d;
			q.a[i] = lo(qd);
		}
		return q;
	}

	constexpr u8 operator%(u8 d) const {
		u16 rem = 0;
		for(size_t i=N;i--;){
			u16 cur = rem<<limb_bits | a[i];
			rem = cur%d;
		}
		return static_cast<u8>(rem);
	}

	// --- division by big integer (binary long division) ---

	constexpr I operator/(const I& d) const {
		I q{}, r{};
		// if(!d)return q;
		if(!d) __builtin_unreachable();
		for(size_t bit = total_bits;bit--;){
			r.shl1();
			if(test_bit(bit))r.a[0]|=1u;
			if((r<=>d) != strong_ordering::less){
				r -= d;
				q.set_bit(bit);
			}
		}
		return q;
	}

	constexpr I operator%(const I& d) const {
		// if(!d)return I{};
		if(!d) __builtin_unreachable();
		I q{}, r{};
		for(size_t bit=total_bits;bit--;){
			r.shl1();
			if(test_bit(bit))r.a[0]|=1u;
			if((r<=>d) != strong_ordering::less){
				r -= d;
				q.set_bit(bit);
			}
		}
		return r;
	}

	constexpr I& operator/=(const I& d){
		*this = *this/d;
		return *this;
	}
	constexpr I& operator%=(const I& d){
		*this = *this%d;
		return *this;
	}

	constexpr I& operator/=(u8 d){
		*this = *this/d;
		return *this;
	}
	constexpr I& operator%=(u8 d){
		*this = *this%d;
		return *this;
	}

	// view
	constexpr const array<u8,N>& view() const { return a; }
};

template<size_t N>
ostream& operator<<(ostream& os, const I<N>& v){
	const auto& a = v.view();
	ios_base::fmtflags f=os.flags();
	for(size_t i=N; i--;)
		os<<hex<<setfill('0')<<setw(sizeof(u8)*2)<<a[i];
	os.flags(f);
	return os;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	uf4 T;
	for(cin>>T; T--;){
		uf4 n;

		using T = pair<uf4, string>;

		priority_queue<T, varray<T, 100'000>, greater<T>> pq;
		for(cin>>n; n--; ){
			string s;
			cin>>s;

			uf1 r = 0;
			bool f = true;
			for(const char c : s){
				constexpr auto b = []{
					bitset<26> b;
					for(const uf1 p : {'a', 'e', 'i', 'o', 'u'})
						b.set(p - 0x61);
					return b;
				}();

				b.test(c-0x61)
				? f ? ++r, f = false : 0
				: f = true;
			}

			pq.emplace(100-r, move(s));
		}

		for(; pq.size() || (cout<<'\n', 0); pq.pop())
			cout<<pq.top().second<<' ';
	}
	return 0;
}
AFESDJPOI
;
