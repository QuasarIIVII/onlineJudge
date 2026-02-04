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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	u2 T;
	cin>>T;
	
	for(u2 t=1; t<=T; ++t){
		u2 n;
		cin>>n;

		array<pair<u1, u1>, 10> a;
		array<u1, 8> m{};

		string s;
		for(u1 i=n; i--;){
			cin>>s;
			const u1 p = s[1]-0x31, q = s[0]-0x41;
			a[i] = {p<<4 | q, s[3]};
			m[p] |= 1u << q;
		}

		u2 r = 0;
		for(u1 i=n; i--;){
			const u1 p = a[i].first>>4, q = a[i].first&0xf;
			switch(a[i].second){
			case 'K':{
				constexpr array<pair<u1, u1>, 8> d{
					pair{-1, -1}, pair{-1, 0}, pair{-1, 1},
					pair{0, -1}, pair{0, 1},
					pair{1, -1}, pair{1, 0}, pair{1, 1},
				};
				for(const auto &[dp, dq] : d){
					const u1 np = p + dp, nq = q + dq;
					if((np|nq)&0xf8) continue;
					if(m[np] & (1u << nq))
						++r;
				}
				break;
			}
			case 'Q':{
				constexpr array<pair<u1, u1>, 8> d{
					pair{-1, -1}, pair{-1, 0}, pair{-1, 1},
					pair{0, -1}, pair{0, 1},
					pair{1, -1}, pair{1, 0}, pair{1, 1},
				};
				for(const auto &[dp, dq] : d){
					u1 np = p, nq = q;
					while(true){
						np += dp; nq += dq;
						if((np|nq)&0xf8) break;
						if(m[np] & (1u << nq)){
							++r;
							break;
						}
					}
				}
				break;
			}
			case 'R':{
				constexpr array<pair<u1, u1>, 4> d{
					pair{-1, 0}, pair{0, -1}, pair{0, 1}, pair{1, 0},
				};
				for(const auto &[dp, dq] : d){
					u1 np = p, nq = q;
					while(true){
						np += dp; nq += dq;
						if((np|nq)&0xf8) break;
						if(m[np] & (1u << nq)){
							++r;
							break;
						}
					}
				}
				break;
			}
			case 'B':{
				constexpr array<pair<u1, u1>, 4> d{
					pair{-1, -1}, pair{-1, 1}, pair{1, -1}, pair{1, 1},
				};
				for(const auto &[dp, dq] : d){
					u1 np = p, nq = q;
					while(true){
						np += dp; nq += dq;
						if((np|nq)&0xf8) break;
						if(m[np] & (1u << nq)){
							++r;
							break;
						}
					}
				}
				break;
			}
			case 'N':{
				constexpr array<pair<u1, u1>, 8> d{
					pair{-2, -1}, pair{-2, 1},
					pair{-1, -2}, pair{-1, 2},
					pair{1, -2}, pair{1, 2},
					pair{2, -1}, pair{2, 1},
				};
				for(const auto &[dp, dq] : d){
					const u1 np = p + dp, nq = q + dq;
					if((np|nq)&0xf8) continue;
					if(m[np] & (1u << nq)) ++r;
				}
				break;
			}
			case 'P':{
				const u1 nq = q + 1;
				if(!(nq&0xf8)){
					if(p>0 && m[p-1] & (1u << nq)) ++r;
					if(p<7 && m[p+1] & (1u << nq)) ++r;
				}
				break;
			}
			}
		}
		cout<<"Case #"<<t<<": "<<r<<"\n";
	}
	return 0;
}
AFESDJPOI
;
