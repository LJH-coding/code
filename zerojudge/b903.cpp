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
//#define int long long
#define double long double
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
const int N = 3e5+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
int n,m,k,ans = 0;
struct item{
	int x,y,w;
	friend bool operator<(item a,item b){
		if(a.x!=b.x)return a.x<b.x;
		return a.y>b.y;
	}
}a[N];
struct node{
	int l,r;
	int mx;
}Tree[N<<2];
VI dp(N);
void build(int index,int l,int r){
	Tree[index].l = l,Tree[index].r = r;	
	if(l==r){
		Tree[index].mx = dp[l];
		return;
	}
	int mid = (l+r)>>1;
	build(index<<1,l,mid);
	build(index<<1|1,mid+1,r);
	Tree[index].mx = max(Tree[index<<1].mx,Tree[index<<1|1].mx);
}
void modify(int index,int x,int y){
	if(Tree[index].l==Tree[index].r){
		Tree[index].mx = y;
		return;
	}
	int mid = (Tree[index].l+Tree[index].r)>>1;
	if(x>=Tree[index].l and x<=mid)
		modify(index<<1,x,y);
	else
		modify(index<<1|1,x,y);
	Tree[index].mx = max(Tree[index<<1].mx,Tree[index<<1|1].mx);
}
int query(int index,int l,int r){
	if(l==Tree[index].l and r==Tree[index].r)return Tree[index].mx;
	int mid = (Tree[index].l+Tree[index].r)>>1;
	if(r<=mid)
		return query(index<<1,l,r);
	else if(l>mid)
		return query(index<<1|1,l,r);
	else{
		return max(query(index<<1,l,mid),query(index<<1|1,mid+1,r));
	}
}
signed main(){
	IOS;
	cin>>n>>m>>k;
	rep(i,1,k){
		cin>>a[i].x>>a[i].y>>a[i].w;
	}
	sort(a+1,a+k+1);
	build(1,1,m);
	rep(i,1,k){
		if(a[i].y==1)
			dp[a[i].y] = max(a[i].w,dp[a[i].y]);
		else
			dp[a[i].y] = max(query(1,1,a[i].y-1)+a[i].w,dp[a[i].y]);
		ans = max(ans,dp[a[i].y]);
		modify(1,a[i].y,dp[a[i].y]);
	}
	cout<<ans<<endl;
}
