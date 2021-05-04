#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define pb push_back
const int N = 1e5+5;
int a[N] = {},n,k,vis[N] = {};
vector<int>point;
bool check(int m){
    point.clear();
    memset(vis,0,sizeof(vis));
    int cnt = 0;
	for(int i = 0;i<n;++i){
		if(point.size()==0){
			point.pb(a[i]+m);
			cnt++;
		}
		if(abs(a[i]-point.back())>m){
			point.pb(a[i]+m);
			cnt++;
		}
	}
    return cnt<=k;
}
signed main(){
    IOS;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n==k){
            cout<<0<<endl;
            continue;
        }
        for(int i = 0;i<n;++i){
            cin>>a[i];
        }
        sort(a,a+n);
        int l = 0,r = a[n-1],ans;
        while(l<=r){
            int m = (l+r)/2;
            if(check(m)){
		/*
                cout<<m<<endl;
                for(auto seg:point){
                    cout<<seg<<' ';
                }
                cout<<endl;
		*/
		ans = m;
                r = m-1;
            }
            else{
                l = m+1;
            }
        }
        cout<<ans<<endl;
    }
}
