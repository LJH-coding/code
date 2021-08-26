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
const int N = 5e2+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
int n,m,k,ans = 0;
struct node{
	int x,y;
	int step;
};
char mp[N][N] = {};
int dx[4] = {1,-1,0,0},dy[4] = {0,0,-1,1};
bool vis[N][N][5] = {};
signed main(){
	IOS;
	int n,m;
	cin>>n>>m;
	queue<node>q;
	rep(i,1,n){
		rep(j,1,m){
			cin>>mp[i][j];
			if(mp[i][j]=='X')q.push({i,j,0});
		}
	}
	int ans = -1;
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		if(now.x<1 or now.y<1 or now.x>n or now.y>m)continue;
		if(vis[now.x][now.y][now.step%3])continue;
		if(mp[now.x][now.y]=='#')continue;
		if(mp[now.x][now.y]<='C' and mp[now.x][now.y]>='A' and mp[now.x][now.y]-'A'==now.step%3)continue;
		if(mp[now.x][now.y]=='Y'){
			ans = now.step;
			break;
		}
		vis[now.x][now.y][now.step%3] = 1;
		rep(i,0,3){
			int newx = now.x+dx[i],newy = now.y+dy[i];
			q.push({newx,newy,now.step+1});	
		}
	}
	cout<<ans<<endl;
}
