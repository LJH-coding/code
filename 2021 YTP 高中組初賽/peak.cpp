#include <bits/extc++.h>
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#ifdef local
#define debug(args...) f(#args, args)
template <typename ...T> void f(const char *s, T ...args) {
    int cnt = sizeof...(T);
    ((std::cerr << "(" << s << ") = (") , ... , (std::cerr << args << (--cnt ? ", " : ")\n")));
}
#else
#define debug(...) ((void)0)
#endif // local
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
#define all(v) begin(v),end(v)
#define LINE cout<<"\n-----------------\n"
#define endl '\n'
#define VI vector<int>
#define F first
#define S second
#define rep(i,m,n) for(int i = m;i<=n;++i)
#define res(i,m,n) for(int i = m;i>=n;--i)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case)
#define int long long
#define double long double
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
template <typename K, typename M = null_type, typename cmp = less_equal<K>, typename T = rb_tree_tag> using _multitree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
const int N = 2e5+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
int n;
struct BIT{
	int arr[N] = {};
	int lowbit(int x){
		return x&(-x);
	}
	void add(int x,int y){
		for(;x<=n;x+=lowbit(x)){
			arr[x]+=y;
		}
	}
	int sum(int x){
		int ans = 0;
		for(;x>0;x-=lowbit(x)){
			ans+=arr[x];
		}
		return ans;
	}
}odd,even;
pii a[N] = {};
signed main(){
	IOS;
	cin>>n;
	for(int i = 1;i<=n;++i){
		cin>>a[i].F;
		a[i].S = i;
	}
	sort(a+1,a+n+1);
	int ans = 0;
	for(int i = 1;i<=n;++i){
		if(a[i].F%2!=0){
			ans+=(odd.sum(a[i].S-1)*(even.sum(n)-even.sum(a[i].S)));
			ans+=(even.sum(a[i].S-1)*(odd.sum(n)-odd.sum(a[i].S)));
			odd.add(a[i].S,1);
		}
		else{
			ans+=(odd.sum(a[i].S-1)*(odd.sum(n)-odd.sum(a[i].S)));
			ans+=(even.sum(a[i].S-1)*(even.sum(n)-even.sum(a[i].S)));
			even.add(a[i].S,1);
		}
	}
	cout<<ans<<endl;
}
