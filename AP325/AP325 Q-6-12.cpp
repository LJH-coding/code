#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
const int N = 1e5+5,inf = 1e9+7,mod = 1e9+9;
int dp[N] = {},a[N] = {};
signed main(){
	IOS;
	int n,k;
	cin>>n>>k;
	for(int i = 0;i<n;++i){
		cin>>a[i];
	}
	dp[0] = a[0];
	for(int i = 1;i<=k;++i){
		for(int j = 0;j<=i;++j){
			dp[i] = max(dp[i],a[j]);
		}
	}
	for(int i = k+1;i<n;++i){
		dp[i] = max(*max_element(dp+(i-k),dp+(i+1)),dp[i-k-1]+a[i]);
	}
	cout<<dp[n-1]<<endl;
}
