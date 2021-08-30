#include <bits/extc++.h>
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
const int N = 1e3+5,M = 1e5+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
bitset<N>vis;
signed main(){
	IOS;
	int n,m,c;
	cin>>n>>m>>c;
	VI p(n+1),w(n+1),x(m),s(m),dp(c+1);
	rep(i,1,n)
		cin>>p[i];
	rep(i,1,n)
		cin>>w[i];
	rep(i,0,m-1)
		cin>>x[i];
	rep(i,0,m-1)
		cin>>s[i];
	rep(i,0,m-1){
		vector<pii>item;
		int totp = -x[i],totw = 0;
		rep(j,0,s[i]-1){
			int t;
			cin>>t;
			vis[t] = 1;
			totp+=p[t];
			totw+=w[t];
			item.pb({p[t],w[t]});
		}
		VI dp1 = dp,dp2 = dp;
		res(j,c,totp){
			dp1[j] = max(dp1[j],dp1[j-totp]+totw);
		}
		for(auto j:item){
			res(k,c,j.F){
				dp2[k] = max(dp2[k],dp2[k-j.F]+j.S);
			}
		}
		rep(j,0,c){
			dp[j] = max(dp1[j],dp2[j]);
		}
	}
	rep(i,1,n){
		if(vis[i])continue;
		res(j,c,p[i]){
			dp[j] = max(dp[j],dp[j-p[i]]+w[i]);
		}
	}
	cout<<*max_element(dp.begin(),dp.end())<<endl;
}
