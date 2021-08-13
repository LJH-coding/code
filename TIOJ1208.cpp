#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("abm,bmi,bmi2,mmx,sse,sse2,sse3,ssse3,sse4,popcnt,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#ifdef local
#define debug(args...) qqbx(#args, args)
template <typename ...T> void qqbx(const char *s, T ...args) {
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
#define rep(i,m,n) for(int i = m;i<=n;++i)
#define res(i,m,n) for(int i = m;i>=n;--i)
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) a*b/gcd(a,b)
#define Case() int _;cin>>_;for(int Case = 1;Case<=_;++Case)
using namespace std;
const int N = 1e6+5,inf = 1e9+7;
VI a(N);
VI s(N);
VI new_s(N);
VI tmp(N);
int n,k;
int sol(int l,int r,int q){
	if(l>=r)return 0;
	int cnt = 0;
	int m = (l+r)>>1;
	cnt+=sol(l,m,q);
	cnt+=sol(m+1,r,q);
	rep(i,l,m){
		int j = upper_bound(new_s.begin()+m+1,new_s.begin()+r+1,new_s[i]+q)-new_s.begin();
		cnt+=r-j+1;
	}
	int idx = l,i = l,j = m+1;
	while(i<=m and j<=r){
		if(new_s[i]<new_s[j])tmp[idx++] = new_s[i++];
		else tmp[idx++] = new_s[j++];
	}
	while(i<=m)tmp[idx++] = new_s[i++];
	while(j<=r)tmp[idx++] = new_s[j++];
	for(int i = l;i<=r;++i){
		new_s[i] = tmp[i];
	}
	return cnt;
}
bool check(int m){
	new_s = s;
	int cnt = sol(0,n,m);
	return cnt>(k-1);
}
signed main(){
	IOS;
	while(cin>>n>>k and n+k){
		s[0] = 0;
		rep(i,1,n){
			cin>>a[i];
			s[i] = s[i-1]+a[i];
		}
		int l = -inf,r = inf;
		while(l<r){
			int m = (l+r)>>1;
			if(check(m))l = m+1;
			else r = m;
		}
		cout<<l<<endl;
	}
}
