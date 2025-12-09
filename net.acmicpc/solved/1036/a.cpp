#include<string>
#include<memory>
#include<array>
#include<tuple>
#include<cmath>
#include<cstring>
#include<algorithm>
#define AFESDJPOI asm("")
//$(pwd); cat <<AFESDJPOI

using namespace std;

using u1=uint8_t;	using u2=uint16_t;	using u4=uint32_t;	using u8=uint64_t;	using u16=unsigned __int128;
using i1=int8_t;	using i2=int16_t;	using i4=int32_t;	using i8=int64_t;	using i16=__int128;
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

int main(){
	size_t n;
    scanf("%zu", &n);

	constexpr auto x36 = []{
		array<I<5>, 50> a;
		a[0] = 1;
		for(uf4 i=1; i<a.size(); ++i)
			a[i] = a[i-1] * 36;
		return a;
	}();

	auto a = [] consteval {
		array<tuple<I<5>, I<5>, u8>, 36> a;
		for(uf4 i=36; i--;)
			a[i] = {0, 0, static_cast<u8>(i)};
		return a;
	}();

	for(;n--;){
        array<char, 51> s;
        scanf("%s", s.data());
        
        uf4 sz = 0;
        while(s[sz++]);

		for(size_t i=sz; i--;){
			char c = s[i];
			if(c & 0x40)
				get<1>(a[c - 0x41+10]) += x36[sz-1 - i];
			else
				get<1>(a[c - 0x30]) += x36[sz-1 - i];
		}
	}

	for(auto &[p, q, v]: a)
		p = q * (35 - v);

	size_t k;
    scanf("%zu", &k);

	sort(a.begin(), a.end(), greater<>());

	I<5> r = 0;
	for(uf4 i=k; i--;) r += get<1>(a[i]) * 35;
	for(uf4 i=k; i<36; ++i) r += get<1>(a[i]) * get<2>(a[i]);

    array<char, 60> oss;
    uf4 oss_sz = 0;
    for(r/=36; r; r /= 36){
		u8 rm = r % 36;
		if(rm < 10) oss[oss_sz++] = char(rm + 0x30);
		else oss[oss_sz++] = char(rm - 10 + 0x41);
	}
    oss[oss_sz] = 0;

	string res = oss.data();
	if(res.empty()) putchar(0x30);
	else puts(string(res.rbegin(), res.rend()).c_str());

	return 0;
}
AFESDJPOI
;
