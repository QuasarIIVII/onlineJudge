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

int main(){
	cin.tie(0)->sync_with_stdio(false);

	string s;
	cin>>s;

	stack<uf4> st;

	uf4 i = 0;
	for(const char c : s){
		switch(c){
		case '(':{
			st.push(0);
			break;
		}
		case '[':{
			st.push(1);
			break;
		}
		case ')':{
			uf4 s = 0;
			while(st.size() && 2 <= st.top()){
				s += st.top();
				st.pop();
			}

			if(st.size() && st.top() == 0){
				st.pop();
				st.push(s ? s * 2 : 2);
			}
			else{
				DEBUG cout<<i<<" )B "<<st.size()<<' '<<(st.size() ? st.top() : -1)<<'\n';
				cout<<'0';
				return 0;
			}
			break;
		}
		case ']':{
			uf4 s = 0;
			while(st.size() && 2 <= st.top()){
				s += st.top();
				st.pop();
			}

			if(st.size() && st.top() == 1){
				st.pop();
				st.push(s ? s * 3 : 3);
			}
			else{
				DEBUG cout<<i<<" ]B "<<st.size()<<' '<<(st.size() ? st.top() : -1)<<'\n';
				cout<<'0';
				return 0;
			}
			break;
		}
		case '\n': continue;
		default:
			__builtin_unreachable();
		}

		DEBUG ++i;
	}

	if(st.size() == 0){
		DEBUG cout<<i<<" END "<<st.size()<<' '<<(st.size() ? st.top() : -1)<<'\n';
		cout<<'0';
		return 0;
	}

	uf4 ss = 0;
	while(st.size() && 2 <= st.top()){
		ss += st.top();
		st.pop();
		if(st.size() && st.top() < 2){
			DEBUG cout<<i<<" END2 "<<st.size()<<' '<<(st.size() ? st.top() : -1)<<'\n';
			cout<<'0';
			return 0;
		}
	}
	cout<<ss;
	return 0;
}
//; echo """
