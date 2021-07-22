#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl '\n'
#define pb push_back
const int N = 1e5+5,M = 5e3+5;
int n,m,bit[N<<1];
struct node{
	int val,index;
}a[N<<1];
bool cmp(node a,node b){
	return a.val<b.val;
}
struct query{
	int l,r,k,ans;
}q[M<<1];
void add(int i,int v){
	for(;i<=n;i+=i&-i)
		bit[i]+=v;
	return;
}
int sum(int i){
	int sum = 0;
	for(;i>0;i-=i&-i)
		sum+=bit[i];
	return sum;
}
void sol(vector<int>num,vector<int>v,int l,int r){
	if(l==r){
		for(int i = 0;i<v.size();++i){
			q[v[i]].ans = l;
		}
		return;
	}
	vector<int>v1,v2,n1,n2;
	int mid = (l+r)>>1;
	for(int i = 0;i<num.size();++i){
		if(a[num[i]].val<=mid){
			add(a[num[i]].index,1);
			n1.pb(num[i]);
		}
		else{
			n2.pb(num[i]);
		}
	}
	for(int i = 0;i<v.size();++i){
		if(sum(q[v[i]].r)-sum(q[v[i]].l-1)>=q[v[i]].k){
			v1.pb(v[i]);
		}
		else{
			q[v[i]].k-=sum(q[v[i]].r)-sum(q[v[i]].l-1);
			v2.pb(v[i]);
		}
	}
	for(int i = 0;i<n1.size();++i){
		add(a[n1[i]].index,-1);
	}
	if(v1.size())sol(n1,v1,l,mid);
	if(v2.size())sol(n2,v2,mid+1,r);
}
signed main(){
	IOS;
	cin>>n>>m;
	for(int i = 1;i<=n;++i){
		cin>>a[i].val;
		a[i].index = i;
	}
	sort(a,a+n,cmp);
	for(int i = 1;i<=m;++i){
		cin>>q[i].l>>q[i].r>>q[i].k;
	}
	vector<int>num;
	vector<int>v;
	for(int i = 1;i<=n;++i)num.pb(i);
	for(int i = 1;i<=m;++i)v.pb(i);
	sol(num,v,-1e9,1e9);
	for(int i = 1;i<=m;++i)
		cout<<q[i].ans<<endl;
}
