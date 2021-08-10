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
using namespace std;
struct matrix{
	int M[3000][3000];
	int n,m;
	matrix(int n = 0,int m = 0):n(n),m(m){
		for(int i = 0;i<n;++i){
			for(int j = 0;j<m;++j){
				M[i][j] = 0;
			}
		}
	}
	friend matrix operator *(matrix a,matrix b){
		matrix tmp(a.n,b.m);
		for(int i = 0;i<a.n;++i){
			for(int j = 0;j<b.m;++j){
				for(int k = 0;k<a.m;++k){
					tmp.M[i][j] = (tmp.M[i][j]+(a.M[i][k]*b.M[k][j]));
				}
			}
		}
		return tmp;
	}
};
matrix merge(matrix a,matrix b,matrix c,matrix d){
	matrix tmp(a.n*2,a.n*2);
	for(int i = 0;i<a.n;++i){
		for(int j = 0;j<a.n;++j){
			tmp.M[i][j] = a.M[i][j];
		}
	}
	for(int i = 0;i<b.n;++i){
		for(int j = a.n;j<a.n+b.n;++j){
			tmp.M[i][j] = b.M[i][j-a.n];	
		}
	}
	for(int i = a.n;i<a.n+c.n;++i){
		for(int j = 0;j<c.n;++j){
			tmp.M[i][j] = c.M[i-a.n][j];
		}
	}
	for(int i = a.n;i<a.n+d.n;++i){
		for(int j = a.n;i<a.n+d.n;++j){
			tmp.M[i][j] = d.M[i-a.n][j-a.n];
		}
	}
	return tmp;
}
matrix build(int n,int op){
	matrix ans;
	if(n==2){
		matrix tmp(2,2);
		tmp.M[0][0] = tmp.M[1][0] = tmp.M[0][1] = 1,tmp.M[1][1] = -1;
		ans = tmp;
	}
	else{
		matrix a = build(n/2,1),b = build(n/2,2),c = build(n/2,3),d = build(n/2,4);
		ans = merge(a,b,c,d);	
	}
	if(op==1 or op==2 or op==3 or op==0){
		return ans;
	}
	else{
		for(int i = 0;i<ans.n;++i){
			for(int j = 0;j<ans.n;++j){
				ans.M[i][j]*=-1;
			}
		}
		return ans;
	}
}
signed main(){
	IOS;
	int n;
	cin>>n;
	matrix a(n,n),h(n,n);
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cin>>a.M[i][j];
		}
	}
	h = build(n,0);
	matrix ans = a*h;
	for(int i = 0;i<n;++i){
		for(int j = 0;j<n;++j){
			cout<<ans.M[i][j]<<' ';
		}
		cout<<endl;
	}
}
