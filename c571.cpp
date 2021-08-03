#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
const int N = 1e5+5;
struct point{
	int x,y,z,index;
}a[N],l[N],r[N];
int ans[N] = {};
void sol(point v[],int L,int R,int n){
	if(n<=1)return;
	int mid = (L+R)/2,l_index = 0,r_index = 0;
	for(int i = 0;i<n;++i){
		if(v[i].z>mid){
			r[r_index++] = v[i];
		}
		else{
			l[l_index++] = v[i];
			for(int j = 0;j<r_index;++j){
				if(r[j].x>v[i].x and r[j].y>v[i].y){
					ans[v[i].index]++;
				}
			}
		}
	}
	int new_R = 0,new_L = N;
	for(int i = 0;i<l_index;++i){
		v[i] = l[i];
		new_R = max(new_R,v[i].z);
	}
	for(int i = 0;i<r_index;++i){
		v[i+l_index] = r[i];
		new_L = min(new_L,v[i+l_index].z);
	}
	if(l_index==0 or r_index==0)return;
	sol(v,L,new_R,l_index);
	sol(v+l_index,new_L,R,r_index);
}
signed main(){
	IOS;
	int n,L = N,R = 0;
	cin>>n;
	for(int i = 0;i<n;++i){
		cin>>a[i].x>>a[i].y>>a[i].z,a[i].index = i;
		L = min(L,a[i].z);
		R = max(R,a[i].z);
	}
	sort(a,a+n,[](point a,point b){if(a.x!=b.x)return a.x>b.x;if(a.y!=b.y)return a.y>b.y;return a.z>b.z;});
	sol(a,L,R,n);
	for(int i = 0;i<n;++i){
		cout<<ans[i]<<endl;
	}
}
