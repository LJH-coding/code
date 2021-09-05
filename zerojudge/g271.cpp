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
#define int long long
#define double long double
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
using namespace __gnu_cxx;
using namespace __gnu_pbds;
using namespace std;
template <typename K, typename cmp = less<K>, typename T = thin_heap_tag> using _heap = __gnu_pbds::priority_queue<K, cmp, T>;
template <typename K, typename M = null_type> using _hash = gp_hash_table<K, M>;
template <typename K, typename M = null_type, typename cmp = less<K>, typename T = rb_tree_tag> using _tree = tree<K, M, cmp, T, tree_order_statistics_node_update>;
typedef pair<int,int> pii;
const int N = 3e5+5,inf = INT_MAX;
pii a[N] = {};
pii Tree[N<<2] = {};
int n,s[N] = {};
void build(int index = 1,int l = 1,int r = n){
	if(l==r){
		Tree[index] = a[l];
		return;
	}
	int m = (l+r)>>1;
	build(index<<1,l,m);
	build(index<<1|1,m+1,r);
	if(Tree[index<<1].first<Tree[index<<1|1].first){
		Tree[index] = Tree[index<<1];
	}
	else{
		Tree[index] = Tree[index<<1|1];
	}
}
pii query(int index,int l,int r,int ql,int qr){
	if(ql>r or qr<l)return {inf,-1};
	if(ql<=l and r<=qr)return Tree[index];
	int m = (l+r)>>1;
	pii tmp1 = query(index<<1,l,m,ql,qr);
	pii tmp2 = query(index<<1|1,m+1,r,ql,qr);
	if(tmp1.first<tmp2.first){
		return tmp1;
	}
	else{
		return tmp2;
	}
}
signed main(){
	IOS;
	cin>>n;
	for(int i = 1,t;i<=n;++i){
		cin>>t;
		a[i] = {t,i};
		s[i] = s[i-1]+t;
	}
	build();
	int l = 1,r = n;
	while(l<r){
		pii mn = query(1,1,n,l,r);
		int sum1 = s[mn.second-1]-s[l-1],sum2 = s[r]-s[mn.second];
		if(sum1>sum2){
			r = mn.second-1;
		}
		else{
			l = mn.second+1;
		}
	}
	cout<<a[l].first<<endl;
}
