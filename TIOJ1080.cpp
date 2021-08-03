#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
const int N = 1e5+5,inf = 1e9+7;
int dp[N] = {},ans;
int a[N],b[N],l[N],r[N];
void sol(int v[],int L,int R,int n){
	if(n<=1){
		return;
	}
	int mid = (L+R)/2,r_index = 0,l_index = 0;
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
	for(int i = 0;i<l_index;++i) v[i] = l[i];
	for(int i = 0;i<r_index;++i) v[l_index+i] = r[i];
	if(l_index == 0 or r_index == 0)return;
	sol(v,L,*max_element(v,v+l_index),l_index);
	sol(v+l_index,*min_element(v+l_index,v+n),R,r_index);
}
signed main(){
	IOS;
	int n,t = 1;
	while(cin>>n and n){
		int L = n,R = 1;
		ans = 0;
		cout<<"Case #"<<t<<": ";
		t++;
		for(int i = 0;i<n;++i){
			cin>>a[i],b[i] = a[i];
		}
		sort(b,b+n);
		int m = unique(b,b+n)-b;
		for(int i = 0;i<n;++i){
			a[i] = lower_bound(b,b+m,a[i])-b+1;
			if(a[i]<L)L = a[i];
			if(a[i]>R)R = a[i];
		}
		sol(a,L,R,n);
		cout<<ans<<endl;	
	}
}
