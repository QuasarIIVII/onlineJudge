#include<iostream>

using namespace std;

inline void swap(int &a, int &b){
	a^=b^=a^=b;
}

void mergeSort(int *a, int *e);

inline int* _merge(int *a, int *e, int *l, int *r){
	while(l!=r && r!=e){
		if(*a <= *r)
			swap(*a++, *l);
		else
			swap(*l, *r++);
		++l;
	}

	while(l!=r) swap(*a++, *l++);
	return l;
}

void _mergeSort(int *a, int *e, int *l, int *r, bool doSort = true){
	if(ptrdiff_t n = e-a; n<4){ // for a[0], a[1], a[2]
		switch(n){
			case 3:
				if(a[0] > a[1]) swap(a[0], a[1]);
				if(a[1] > a[2]) swap(a[1], a[2]);
			case 2:
				if(a[0] > a[1]) swap(a[0], a[1]);
		}
		return;
	}

	if(doSort){
		mergeSort(a, l);
		mergeSort(r, e);
	}

	int *const _l = l;
	l = _merge(a, e, l, r);

	int *const p = _l - (_l - a)/2;
	if(_l - a == 1){
		for(;a+1 != e && a[0] > a[1]; ++a) swap(a[0], a[1]);
		return;
	}

	mergeSort(a, p);
	_mergeSort(a, e, p, _l, false);
}

void mergeSort(int *a, int *e){ // inplace merge
	ptrdiff_t n = e-a;
	_mergeSort(a, e, a + (n/2-n/4), a + n/2);
}

int a[1'000'000];

int main(){
	int n;
	cin>>n;
	for(int i=0;cin>>a[i];++i);
	mergeSort(a, a+n);
	for(int i=0;i<n;++i) cout<<a[i]<<'\n';
	return 0;
}
