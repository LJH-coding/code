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
#define endl '\n'
#define VI vector<int>
#define rep(i,m,n) for(int i = m;i<=n;++i)
#define res(i,m,n) for(int i = m;i>=n;--i)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case)
using namespace std;
const int N = 1e5+5,inf = 1e15;
int n,input,water;
pair<int,int>a[N];
pair<int,int>tree[N<<2];
void build(int index,int l,int r){
	if(l==r){
		tree[index] = {a[l].first,l};
		return;
	}
	int m = (l+r)/2;
	build(index*2,l,m);
	build(index*2+1,m+1,r);
	if(tree[index*2].first>tree[index*2+1].first){
		tree[index] = tree[index*2];
	}
	else{
		tree[index] = tree[index*2+1];
	}
}
pair<int,int> query(int ql,int qr,int index = 1,int l = 0,int r = n-1){
	if(qr<l or ql>r)return {-inf,-inf};
	if(ql<=l and r<=qr)return tree[index];
	int m = (l+r)/2;
	pair<int,int>a,b;
	a = query(ql,qr,index*2,l,m),b = query(ql,qr,index*2+1,m+1,r);
	if(a.first>b.first)return a;
	return b;
}
void sol(int l,int r,int w,int in){
	if(r-l<=1){
		a[l].second = w;
		return;
	}
	pair<int,int>h = query(l+1,r-1);
	if(w>=(r-l)*h.first){
		rep(i,l,r-1){
			a[i].second = w/(r-l);
		}
	}
	else if(h.second>in){
		int tmp_w = (h.second-l)*(h.first);
		if(w<tmp_w){
			sol(l,h.second,w,in);
			return;
		}
		rep(i,l,h.second-1){
			a[i].second = h.first;
		}
		if(w>tmp_w){
			sol(h.second,r,w-tmp_w,h.second);
		}
	}
	else{
		int tmp_w = (r-h.second)*(h.first);
		if(w<tmp_w){
			sol(h.second,r,w,in);
			return;
		}
		rep(i,h.second,r-1){
			a[i].second = h.first;
		}
		if(w>tmp_w){
			sol(l,h.second,w-tmp_w,h.second-1);
		}
	}
}
signed main(){
	IOS;
	cin>>n>>input>>water;
	rep(i,0,n-1){
		cin>>a[i].first;
		a[i].second = 0;
	}
	build(1,0,n-1);
	sol(0,n-1,water,input);
	rep(i,0,n-2)cout<<a[i].second<<' ';
}
