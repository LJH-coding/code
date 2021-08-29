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
#define int long long
#define double long double
#define pb push_back
#define all(v) begin(v),end(v)
#define LINE cout<<"\n-----------------\n"
#define endl '\n'
#define VI vector<int>
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
const int N = 2e3+5,mod = 1e9+7,inf = 1e9+5;
typedef pair<int,int> pii;
vector<pii>g[N] = {};
int in[N] = {};
int dis[N] = {};
int cost[20][N] = {};
int table[20] = {};
int dp[20][1<<20] = {};
void dijkstra(int a,int n,int index){
	_heap<pii,greater<pii>>pq;
	_heap<pii,greater<pii>>::point_iterator ite[N];
	for(int i = 1;i<=n;++i){
		dis[i] = inf;
		ite[i] = NULL;
	}
	dis[a] = 0,ite[a] = pq.push({dis[a],a});
	while(!pq.empty()){
		int now = pq.top().second;
		pq.pop();
		for(auto i:g[now]){
			int v = i.first,w = i.second;
			if(dis[now]+w<dis[v]){
				dis[v] = dis[now]+w;
				if(ite[v]==NULL)ite[v] = pq.push({dis[v],v});
				else pq.modify(ite[v],{dis[v],v});
			}
		}
	}
	for(int i = 1;i<=n;++i)cost[index][i] = dis[i];
}
int count(vector<int>a,vector<int>b){
	for(int i = 0;i<=a.size();++i){
		for(int j = 0;j<(1<<b.size());++j){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	for(int i = 0;i<a.size();++i){
		for(int j = 0;j<b.size();++j){
			for(int k = 0;k<(1<<b.size());++k){
				dp[i+1][k|(1<<j)] = min({dp[i+1][k|(1<<j)],dp[i+1][k]+cost[a[i]][table[b[j]]],dp[i][k]+cost[a[i]][table[b[j]]]});
			}
		}
	}
	return dp[a.size()][(1<<b.size())-1];
}
int sol(vector<int>v){
	int ans = inf;
	vector<int>a,b;
	int n = v.size();
	for(int i = 0;i<(1<<n);++i){
		for(int j = 0;j<n;++j){
			if(i&(1<<j)){
				a.pb(v[j]);
			}
			else{
				b.pb(v[j]);
			}
		}
		if(a.size()==0 or b.size()==0){
			a.clear();
			b.clear();
			continue;
		}
		ans = min(ans,count(a,b));
		a.clear();
		b.clear();
	}
	return (ans==inf?0:ans);
}
signed main(){
	IOS;
	int n,m,a,ans = 0;
	cin>>n>>m>>a;
	for(int i = 0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
		in[u]++,in[v]++;
		ans+=w;
	}
	int index = 1;
	vector<int>Nodd;
	for(int i = 1;i<=n;++i){
		if(in[i]&1){
			table[index] = i;
			dijkstra(i,n,index);
			Nodd.pb(index);
			index++;
		}
	}
	ans+=sol(Nodd);
	cout<<ans<<endl;
}
