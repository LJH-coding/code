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
const int N = 1e5+5,mod = 1e9+7,inf = 1e9+7;
typedef pair<int,int> pii;
signed main(){
	IOS;
	double v1,v2,dtheta,dbeta;
	string s;
	cin>>s;
	for(int i = 0;i<s.size();++i){
		if(s[i]==',')s[i] = ' ';
	}
	stringstream ss(s);
	ss>>v1>>v2>>dtheta>>dbeta;
	double now_theta = atan(v1/1);
	double now_s = sqrt(1*1+v1*v1);
	double now_beta = atan(v2/now_s);
	double t = sqrt(v2*v2+now_s*now_s);
	double new_theta = now_theta+dtheta;
	double new_beta = now_beta+dbeta;
	double new_s = t*cos(new_beta);
	double new_v2 = sqrt(t*t-new_s*new_s);
	double new_v1 = new_s*sin(new_theta);
	cout<<fixed<<setprecision(2);
	cout<<t<<','<<new_v1<<','<<new_v2<<endl;
}
