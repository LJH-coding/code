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
vector<pii>g[N] = {};
map<pii,int>dis;
vector<int>b(N);
void dijkstra(int a,int n){
	_heap<pii,greater<pii>>pq;
	_heap<pii,greater<pii>>::point_iterator ite[N] = {};
	for(int i = 1;i<=n;++i){
		dis[{a,i}] = inf;
		ite[i] = NULL;
	}
	dis[{a,a}] = 0;
	ite[a] = pq.push({dis[{a,a}],a});
	while(!pq.empty()){
		int u = pq.top().S;
		pq.pop();
		for(auto seg:g[u]){
			int v = seg.F,w = seg.S;
			if(dis[{a,v}]>dis[{a,u}]+w){
				dis[{a,v}] = dis[{a,u}]+w;
				if(ite[v]==NULL){
					ite[v] = pq.push({dis[{a,v}],v});
				}
				else{
					pq.modify(ite[v],{dis[{a,v}],v});
				}
			}
		}
	}
}
signed main(){
	IOS;
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i<m;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].pb({v,w});
		g[v].pb({u,w});
	}
	for(int i = 0;i<k;++i){
		cin>>b[i];
		dijkstra(b[i],n);
	}
	int ans = inf;
	for(int i = 0;i<k;++i){
		for(int j = i+1;j<k;++j){
			ans = min(ans,dis[{b[i],b[j]}]);
		}
	}
	cout<<ans<<endl;
}
