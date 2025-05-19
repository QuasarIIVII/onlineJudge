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

struct Point {
	int x, y;
};

struct Node {
	Point pt;
	Node *left, *right;
	int dim;
	Node(const Point& p, int d) : pt(p), left(nullptr), right(nullptr), dim(d) {}
};

class KdTree {
private:
	Node* root;
	vector<Point> points;

public:
	KdTree(const vector<Point>& pts) {
		points = pts;
		root = build(0, points.size(), 0);
	}

	vector<Point> kNearest(const Point& target, int k) {
		auto cmp = [](const pair<int, Point>& a, const pair<int, Point>& b) {
			return a.first < b.first;
		};
		priority_queue<pair<int, Point>, vector<pair<int, Point>>, decltype(cmp)> pq(cmp);
		search(root, target, k, pq);
		vector<Point> res;
		while(!pq.empty()){
			res.push_back(pq.top().second);
			pq.pop();
		}
		return res;
	}

private:
	Node* build(size_t l, size_t r, int depth) {
		if(r <= l) return nullptr;
		int dim = depth & 1;
		size_t m = (l + r) / 2;
		nth_element(points.begin() + l, points.begin() + m, points.begin() + r,
			[dim](const Point& a, const Point& b) {
				return (!dim ? a.x < b.x : a.y < b.y);
			}
		);
		Node* node = new Node(points[m], dim);
		node->left = build(l, m, depth + 1);
		node->right = build(m + 1, r, depth + 1);
		return node;
	}

	template<class PQ>
	void search(Node* node, const Point& target, int k, PQ& pq) {
		if(!node) return;
		int dist = f(node->pt, target);
		if(pq.size() < static_cast<size_t>(k)){
			pq.emplace(dist, node->pt);
		}else if(dist < pq.top().first){
			pq.pop();
			pq.emplace(dist, node->pt);
		}
		int dim = node->dim;
		int diff = (!dim ? target.x - node->pt.x : target.y - node->pt.y);
		Node* first = diff < 0 ? node->left : node->right;
		Node* second = diff < 0 ? node->right : node->left;

		search(first, target, k, pq);
		if(pq.size() < (size_t)k || diff*diff < pq.top().first){
			search(second, target, k, pq);
		}
	}

	static int f(const Point& a, const Point& b) {
		int dx = a.x - b.x;
		int dy = a.y - b.y;
		return dx*dx + dy*dy;
	}
};

class Solution{
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k){
		vector<Point> pts;
		pts.reserve(points.size());
		for(auto& v : points){
			pts.push_back({v[0], v[1]});
		}
		KdTree tree(pts);
		Point origin{0, 0};
		vector<Point> nearest = tree.kNearest(origin, k);
		vector<vector<int>> ans;
		ans.reserve(k);
		for(auto& p : nearest){
			ans.push_back({p.x, p.y});
		}
		return ans;
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
