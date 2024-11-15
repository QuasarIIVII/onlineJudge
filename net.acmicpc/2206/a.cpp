#include<iostream>
#include<string>
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

#include<chrono>
#include<thread>

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

#define DEBUG if constexpr(debug)
#define DEBUG_BLOCK(x) if constexpr(debug){x}

template<class T>
struct Alloc_d: public allocator<T>{
	using Base = std::allocator<T>;
    using value_type = typename Base::value_type;

    Alloc_d() = default;
    
    template <typename U>
    Alloc_d(const Alloc_d<U>& other) noexcept : Base(other) {}

    T* allocate(std::size_t n) {
        T* ptr = Base::allocate(n);
        DEBUG std::cout
			<< "Allocating " << n
			<< " element(s) of size " << sizeof(T)
			<< " at address " << static_cast<void*>(ptr) << '\n';
        return ptr;
    }

    void deallocate(T* ptr, std::size_t n) noexcept {
        DEBUG std::cout
			<< "Deallocating " << n
			<< " element(s) of size " << sizeof(T)
			<< " from address " << static_cast<void*>(ptr) << '\n';
        Base::deallocate(ptr, n);
    }
};

template<class T,size_t N=4096>
struct Alloc_static{
	using value_type		= T;
	using size_type			= size_t;
	using difference_type	= ptrdiff_t;
	using propagate_on_container_move_assignment = true_type;

	array<T,N> data;
	array<size_t,N> map={0,};
	bitset<N> isAvailable;

	constexpr Alloc_static() noexcept {
		DEBUG cout<<"Alloc_static<T,"<<N<<'>'<<endl;
		map[0]=N;
		isAvailable[0]=true;
		DEBUG cout<<isAvailable[0]<<endl;
	}
	constexpr Alloc_static(const Alloc_static& other) noexcept : data(other.data) {
		DEBUG cout<<"Alloc_static<T,"<<N<<">(const Alloc_static&)"<<endl;
		map[0]=N;
		isAvailable[0]=true;
	}
	template<class U,size_t M>
	constexpr Alloc_static(const Alloc_static<U,M>& other) noexcept {
		DEBUG cout<<"Alloc_static<T,"<<N<<">(const Alloc_static<"<<N<<','<<M<<">&)"<<endl;
		map[0]=N;
		isAvailable[0]=true;
	}

	template<class U>
	struct rebind{
		using other=Alloc_static<U,N>;
	};

	T* allocate(std::size_t n){
		DEBUG cout<<"Allocating "<<n<<" elements"<<endl;
		size_t i, j;
		DEBUG cout<<isAvailable[0]<<endl;
		for(i=0; i<N && !isAvailable[i]; i+=map[i])DEBUG cout<<i<<' ';
		while(i<N && map[i]<n){
			for(j=i+map[i]; j<N && isAvailable[j] && map[i]<n;){
				map[i]+=map[j];
				size_t jj=j+map[j];
				map[j]=0;
				j=jj;
			}
			for(i=j; i<N && !isAvailable[i]; i+=map[i]);
		}

		// failed
		if(N<=i || map[i]<n){
			DEBUG cout<<"Failed to allocate "<<n<<" elements"<<endl;
			return nullptr;
		}

		if(map[i]==n){ // success
			isAvailable[i]=false;
			DEBUG cout<<"Allocated "<<n<<" elements at "<<i<<endl;
			return data.data()+i;
		}

		// success (split space)
		size_t sz=map[i];
		map[i]=n;
		isAvailable[i]=false;
		map[i+n]=sz-n;
		isAvailable[i+n]=true;

		DEBUG cout<<"Allocated "<<n<<" elements at "<<i<<endl;
		return data.data()+i;
	}

	void deallocate(T* p, std::size_t n){
		ptrdiff_t i=p-data.data();
		isAvailable[i]=true;
	}
};

template <typename T, std::size_t Alignment = alignof(T)>
class MyAllocator {
public:
    using value_type = T;

    MyAllocator() noexcept = default;

    template <typename U, std::size_t OtherAlignment>
    MyAllocator(const MyAllocator<U, OtherAlignment>&) noexcept {}

    // Rebind allocator to another type
    template <typename U>
    struct rebind {
        using other = MyAllocator<U, Alignment>;
    };

    T* allocate(std::size_t n) {
        std::cout << "Allocating " << n << " elements aligned to " << Alignment << " bytes\n";
        
        // Ensure the total allocation size is a multiple of the alignment
        std::size_t size = n * sizeof(T);
        if (size % Alignment != 0) {
            size += Alignment - (size % Alignment);
        }

        if (auto ptr = static_cast<T*>(std::aligned_alloc(Alignment, size))) {
            return ptr;
        } else {
            throw std::bad_alloc();
        }
    }

    void deallocate(T* p, std::size_t) noexcept {
        std::cout << "Deallocating\n";
        std::free(p); // Use free to deallocate memory from aligned_alloc
    }
};

array<char[1000],1000> a;
array<array<array<uf4,2>,1000>,1000> d;
struct S0{if2 x,y;};
struct S1:public S0{
	if1 z;
	S1()=default;
	S1(if2 x,if2 y,if1 z):S0(x,y),z(z){}
};
constexpr array<S0, 4> dd={S0{1,0},S0{-1,0},S0{0,1},S0{0,-1}};

#define ex 0
#define sy 0
#define sx (n-1)
#define ey (m-1)

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	uf2 n,m;
	cin>>n>>m;

	d[ex][ey]=array<uf4,2>{UINT_FAST32_MAX,UINT_FAST32_MAX};

	for(uf2 i=n;i--;){
		cin>>a[i];
		for(uf2 j=125;j--;)*reinterpret_cast<u8*>(a[i]+(j<<3))&=0x01010101'01010101ull;
	}

	DEBUG_BLOCK(
		for(uf2 i=0;i<n;++i,cout<<"\033[49m\n")for(uf2 j=0;j<m;++j)
			cout<<(a[i][j] ? "\033[48:5:105m1" : "\033[49m0")<<' ';
		cout<<"\033[49m";
	)

	queue<S1,deque<S1,Alloc_static<S1>>> q;
	q.emplace(sx,sy,0);
	d[q.front().x][q.front().y]={1,1};

	for(;q.size();q.pop())for(auto& dd:dd){
		const S1 &qh=q.front();
		const S0 p{qh.x+dd.x, qh.y+dd.y};
		if(p.x<0 || n<=p.x || p.y<0 || m<=p.y)continue;

		const uf4 src=d[qh.x][qh.y][qh.z]+1;
		array<uf4,2> &dst=d[p.x][p.y];

		if(!dst[0])dst[0]=~dst[0];
		if(!dst[1])dst[1]=~dst[1];

		switch(qh.z<<1 | a[p.x][p.y]){
		case 0:
			if(src>=dst[0])continue;
			dst[0]=src;
			if(dst[1]>src)dst[1]=src;
			q.emplace(p.x,p.y,0);
			break;
		case 1:
			if(src>=dst[1])continue;
			dst[1]=src;
			q.emplace(p.x,p.y,1);
			break;
		case 2:
			if(src>=dst[1])continue;
			dst[1]=src;
			q.emplace(p.x,p.y,1);
		}
	}

	DEBUG cout<<d[ex][ey][0]<<' '<<d[ex][ey][1]<<'\n';
	cout<<static_cast<if4>(d[ex][ey][0]<d[ex][ey][1]?d[ex][ey][0]:d[ex][ey][1]);

	return 0;
}
