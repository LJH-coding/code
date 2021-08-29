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
const int N = 5e3+5,M = 2e5+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
struct node{
	int x,y,t;
};
char mp[N][N] = {};
int dx[4] = {1,-1,0,0},dy[4] = {0,0,-1,1};
bitset<N>vis[N];
queue<node>q,tmp;
signed main(){
	IOS;
	int n,m;
	cin>>n>>m;
	rep(i,1,n){
		cin>>mp[i]+1;
	}
	int ans = 0;
	Case(){
		int x,y;
		cin>>x>>y;
		if(mp[x][y]!='#' and !vis[x][y]){
			ans++;
			tmp.push({x,y});
			vis[x][y] = 1;
		}
		while(!q.empty()){
			auto now = q.front();
			q.pop();
			rep(i,0,3){
				int newx = now.x+dx[i],newy = now.y+dy[i];
				if(mp[newx][newy]=='.' and !vis[newx][newy]){
					ans++;
					vis[newx][newy] = 1;
					tmp.push({newx,newy});
				}
			}
		}
		swap(q,tmp);
		cout<<ans<<endl;
	}
}
/*
6 6
######
##.#.#
#..#.#
#.##.#
#.#..#
######
4
2 3
5 4
2 5
5 2
*/
/*
4 5
..#..
.#.#.
..#..
.....
2
2 3
2 3
*/
