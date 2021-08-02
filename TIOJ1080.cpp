#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
#define pb push_back
const int N = 1e5+5;
int dp[N] = {},ans;
int a[N];
void sol(int v[],int L,int R,int n){
	if(R-L==1){
		return;
	}
	int mid = (L+R)/2,l_index = 0,r_index = 0;
	int l[mid+5],r[mid+5];
	for(int i = 0;i<n;++i){
		if(v[i]>mid){
			r[r_index] = v[i];
			r_index++;
			if(!i) dp[i] = 1;
			else dp[i] = dp[i-1] +1;
		}
		else{
			l[l_index] = v[i];
			l_index++;
			if(!i) dp[i] = 0;
			else dp[i] = dp[i-1];
			ans+=dp[i];
		}
	}
	sol(l,L,mid,l_index);
	sol(r,mid,R,r_index);
}
signed main(){
	IOS;
	int n,t = 1;
	while(cin>>n and n){
		ans = 0;
		cout<<"Case #"<<t<<": ";
		t++;
		for(int i = 0,j;i<n;++i){
			cin>>a[i];
		}
		sol(a,0,n,n);
		cout<<ans<<endl;	
	}
}
