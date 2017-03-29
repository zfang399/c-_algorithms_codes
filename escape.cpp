#include<iostream>
#include<cstdio>
#include<vector> 
using namespace std;

int n,a[4],q[20005],dist[20005],sum[20005]={0};
bool inque[20005];
vector<int> vd[20005],vn[20005];

int main()
{
	cin>>n>>a[1]>>a[2]>>a[3];
	int i,u,v,w,j;
	for(i=1;i<=n-1;i++){
		cin>>u>>v>>w;
		vn[u].push_back(v);
		vd[u].push_back(w);
		vn[v].push_back(u);
		vd[v].push_back(w);
	}
	for(j=1;j<=3;j++){
		for(i=1;i<=n;i++){
			dist[i]=99999999;
			inque[i]=false;
		}
		int f=0,r=0,x;
		r++;
		q[r]=a[j];
		dist[a[j]]=0;
		inque[a[j]]=true;
		while(f<r){
			f++;
			x=q[f];
			inque[x]=false;
			for(i=0;i<vd[x].size();i++){
				if(vd[x][i]+dist[x]<dist[vn[x][i]]){
					dist[vn[x][i]]=vd[x][i]+dist[x];
					if(!inque[i]){
						r++;
						q[r]=i;
						inque[i]=true;
					}
				}
			}
		}
		for(i=1;i<=n;i++){
			sum[i]+=dist[i];
		}
	}
	int ansp,ans=999999999;
	for(i=1;i<=n;i++){
		if(sum[i]<ans){
			ans=sum[i];
			ansp=i;
		}
	}
	cout<<ansp<<endl;
	cout<<ans<<endl;
	return 0;
}
