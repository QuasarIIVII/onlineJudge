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

	array<array<array<u1, 8>, 8>, 16384> a, d, v{};
	memset(&d, 0xff, sizeof(d));

	uf2 n, m;
	cin>>n>>m;

	for(uf2 i=n; i--;){
		string s;
		cin>>s;
		for(uf2 j=m; j--;){
			constexpr array<u1, 4> mp{0xff, 0x00, 0x0f, 0xf0};
			a[0][i][m-j-1] = mp[s[j]-0x41];
		}
	}

	for(uf2 I=0; I<7; ++I){
		const uf2 i=1u<<I;
		for(uf2 j=i; j--;) a[i+j]=a[j];
		for(uf2 j=i; j--;){
			for(uf2 k=8; k--;)
				a[i+j][k][I] = rotl<u1>(a[i+j][k][I], 4);
		}
	}

	for(uf2 I=0; I<7; ++I){
		const uf2 i=1u<<I;
		for(uf2 j=i; j--;)
			memcpy(&a[(i+j)<<7], &a[j<<7], 128*sizeof(a[0]));
		for(uf2 j=i; j--;)for(uf2 p=128; p--;){
			for(uf2 k=8; k--;){
				u1 &x = a[(i+j)<<7 | p][I][k];
				x = rotl<u1>(x, 4);
			}
		}
	}

	const auto df = [&](const u2 x){
		DEBUG for(uf2 i=n; i-- || (cout<<endl,0); cout<<endl)for(uf2 j=m; j--;)
			cout<<+(a[x][i][j]>>3 & 3);
	};

	df(520);

	queue<tuple<u2, u1, u1>> q;
	d[0][n-1][m-1]=0;

	for(q.emplace(0, n-1, m-1); q.size(); q.pop()){
		const auto &[w, x, y] = q.front();
		v[w][x][y]=0;
		DEBUG cout<<w<<" "<<+x<<" "<<+y<<" : "<<+d[w][x][y]<<endl;

		if(!x && !y){
			cout<<+d[w][x][y];
			return 0;
		}

		const auto f = [&](const u2 nw, const u1 nx, const u1 ny, const u1 dir){
			if(n<=nx || m<=ny) return;
			DEBUG cout<<"  "<<nw<<"\t"<<+nx<<" "<<+ny<<" "<<+dir<<' '<<~if4(if1(dir))<<endl;
			if(!(a[nw][nx][ny] & dir)) return;
			if(d[nw][nx][ny] <= d[w][x][y]) return;
			d[nw][nx][ny] = d[w][x][y] + 1u;
			if(!v[nw][nx][ny]) q.emplace(nw, nx, ny), v[nw][nx][ny]=1;
		};

		f(w^(128u<<x)^(1u<<y), x, y, 0xff);

		if(a[w][x][y] & 0x0f){
			f(w, x+1u, y, 0x0f);
			f(w, x-1u, y, 0x0f);
		}

		if(a[w][x][y] & 0xf0){
			f(w, x, y+1u, 0xf0);
			f(w, x, y-1u, 0xf0);
		}
	}

	cout<<"-1";

	return 0;
}
AFESDJPOI
;
