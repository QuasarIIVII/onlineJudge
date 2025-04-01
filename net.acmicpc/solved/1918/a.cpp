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
#include<optional>

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
#define DEBUG_BLOCK(x) if constexpr(debug){x}

struct T;
struct S{
	if4 a;
	optional<list<S>::iterator> p;
	T* q;
};

ostream& operator<<(ostream& os, const list<S>& l){
	for(const auto& i : l){
		os << &i << '\t' << i.a;
		if(i.p)
			os<<'\t'<<&**i.p;
		os<<endl;
	}
	return os;
}

struct T{
	list<S>::iterator s, e;
	T *ptl, *ptr;
	uf1 a;

	T(list<S>& li, list<S>::iterator s, list<S>::iterator e) : s(s), e(e), ptl(nullptr), ptr(nullptr){
		list<S>::iterator op = s;
		for(auto it = s; it != e;){
			if(auto opa = op->a&0xe0, ita = it->a&0xe0; !it->a){
				it = *it->p;
				continue;
			}else if(opa < 0x60){
				if(opa <= ita && it->a != 0x61)
					op = it;
			}else{
				if(it->a == 0x60)
					op = it;
			}
			++it;
		}

		DEBUG{
			cout<<"&op\t"<<&*op;
			if(op->a==0x60)
				cout<<'\t'<<&**op->p;
			cout<<endl;
		}

		switch(op->a){
		case 0x60:
			a = 0x60;
			op->a = 0;
			op->p = next(*op->p);
			op->q = new T(li, next(op), *op->p);
			ptr = new T(li, s, e);
			break;
		case 0x40:
		case 0x41:
		case 0x20:
		case 0x21:
			a = op->a;
			li.emplace(s, 0, e);
			ptl = new T(li, s, op);
			ptr = new T(li, next(op), e);
			break;
		default:
			if(op->a){
				a = op->a;
				break;
			}
			ptl = op->q;
			break;
		}
	}
	~T(){
		if(ptl) delete ptl;
		if(ptr) delete ptr;
	}

	void f(){
		if(ptl) ptl->f();
		if(ptr) ptr->f();
		if(!a) return;
		if(a < 0x20){
			cout<<static_cast<char>(a+0x40);
			return;
		}
		switch(a){
		case 0x20:
			cout<<'*';
			break;
		case 0x21:
			cout<<'/';
			break;
		case 0x40:
			cout<<'+';
			break;
		case 0x41:
			cout<<'-';
			break;
		}
	}

	void p(const uf4 lv = 0){
		if(ptl)ptl->p(lv+1);
		if(ptr)ptr->p(lv+1);
		for(uf4 i=lv; i--; ) cout<<"|   ";
		cout<<static_cast<uf2>(a)<<endl;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	list<S> l;
	{
		char c;
		stack<list<S>::iterator> st;

		while(cin.get(c)){
			switch(c){
			case '(':
				l.emplace_back(0x60, nullopt);
				st.push(prev(l.end()));
				break;
			case ')':
				l.emplace_back(0x61, st.top());
				st.top()->p = prev(l.end());
				st.pop();
				break;
			case '*':
				l.emplace_back(0x20, nullopt);
				break;
			case '/':
				l.emplace_back(0x21, nullopt);
				break;
			case '+':
				l.emplace_back(0x40, nullopt);
				break;
			case '-':
				l.emplace_back(0x41, nullopt);
				break;
			default:
				if(c < 0x40) break;
				l.emplace_back(c-0x40, nullopt);
			}
		}
	}
	DEBUG cout << l << '\n';
	T t(l, l.begin(), l.end());
	t.f();
	return 0;
}

