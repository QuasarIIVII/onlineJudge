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

template<class T, class Cmp=std::less<T>>
class PQ{
private:
	vector<T> data;
public:
	PQ(){}

	void push(const T& v){
		data.push_back(v);
		push_heap(data.begin(), data.end(), Cmp());
	}
	const T& top() const{
		return data.front();
	}
	void pop(){
		pop_heap(data.begin(), data.end(), Cmp());
		data.pop_back();
	}
};

class c{
public:
	bool operator()(const pair<uf4, vector<int>>& a, const pair<uf4, vector<int>>& b) const{
		return a.first > b.first;
	}
};

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		PQ<pair<uf4, vector<int>>, c> pq;
		for(auto& p : points){
			uf4 d = p[0] * p[0] + p[1] * p[1];
			pq.push({d, p});
		}
		vector<vector<int>> r;
		for(int i=0; i<k; ++i){
			r.push_back(pq.top().second);
			pq.pop();
		}
		return r;
	}
};

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	Solution s;
	vector<vector<int>> points = {{1,3},{-2,2},{5,8},{0,1}};
	auto r = s.kClosest(points, 2);

	for(auto& v : r){
		cout<<v[0]<<" "<<v[1]<<"\n";
	}

	return 0;
}
//; echo """
