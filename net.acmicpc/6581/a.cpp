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
#include<climits>
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

constexpr inline size_t rol_13(size_t x){
	return x<<13 | x>>(CHAR_BIT*sizeof(size_t)-13);
}

constexpr size_t hash_string(const std::string& s){
	size_t h = 0;
	for(char c : s)
		h = rol_13(h) ^ static_cast<size_t>(c);
	return h;
}

int main(){
	cin.tie(0)->sync_with_stdio(false);

	string s, l;
	while(cin>>s){
		switch(hash_string(s)){
		case hash_string("<br>"):
			cout<<l<<'\n';
			l.clear();
			break;
		case hash_string("<hr>"):
			if(l.size()){
				cout<<l<<'\n';
				l.clear();
			}
			cout<<"--------------------------------------------------------------------------------\n";
			break;
		default:{
			string lt;
			if(l.size()) l.push_back(' ');
			lt = l + s;
			if(80 < lt.size()){
				cout<<l<<'\n';
				l = s;
			}else{
				l = std::move(lt);
			}
		}
		}
	}

	if(l.size()) cout<<l<<'\n';

	return 0;
}
//; echo """
