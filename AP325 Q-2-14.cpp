#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define endl '\n'
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N = 1e5+5;
int a[N] = {},ans[N],size[N] = {};
vector<pair<int,int>>v;
signed main(){
	IOS;
	int n,m,w;
	cin>>n>>m>>w;
	for(int i = 0;i<n;++i){
		cin>>a[i];
	}
	int last_op = 0,l,r,now_size = min(a[m],a[m+1]),last_size = 0;
	for(l = m,r = m+1;l>=0 and r<n and w>now_size;){
		while(a[l]<a[r] and w>now_size){
			last_op = 0;
			last_size = now_size;
			l--;
			if(a[l]>a[l+1]){
				now_size = min(a[l],a[r])*(r-l);
			}
			else{
				now_size+=a[l];
			}
		}
		while(a[r]<a[l] and w>now_size){
			last_op = 1;
			last_size = now_size;
			r++;
			if(a[r]>a[r-1]){
				now_size = min(a[l],a[r])*(r-l);
			}
			else{
				now_size+=a[r];
			}
		}
	}
	if(!last_op){
		ans[l] = w-last_size;
		l++;
	}
	else{
		r--;
		ans[r] = w-last_size;
	}
	for(int i = l;i<=r;++i){
		v.pb({a[i],i});
	}
	sort(v.begin(),v.end(),greater<>());
	for(int i = 0;i<v.size()-1;++i){
		if(v[i].second>v[i+1].second){
			v[i+1].second = v[i].second;
		}
		for(int j = v[i].second;j<v[i+1].second;++j){
			ans[j] = min(a[v[i].second],a[v[i+1].second]);
		}
	}
	for(int i = 0;i<n-1;++i){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
}
