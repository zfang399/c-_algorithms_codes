#include<iostream>
using namespace std;

int ga[10005][10005],n,m,s,que[10005],dist[10005];
bool inque[10005];

int main()
{
	cin>>n>>m>>s;
	int i,j,u,v,w;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			ga[i][j]=99999999;
		}
	} //initialize the array
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		ga[u][v]=w;
	} //enter path length

	int f=0,r=0;
	r++;
	que[r]=s;
	inque[s]=true; //put start point in que
	for(i=1;i<=n;i++){
		dist[i]=99999999;
	}
	dist[s]=0; //distance from start point to start point is zero
	while(f<r){
		f++;
		int x=que[f];
		inque[x]=false;
		for(i=1;i<=n;i++){
			if(ga[x][i]>0){
				if(ga[x][i]+dist[x]<dist[i]){
					dist[i]=ga[x][i]+dist[x];
					if(!inque[i]){
						r++;
						que[r]=i;
						inque[i]=true;
					}
				}
			}
		}
	}
	for(i=1;i<=n;i++){
		cout<<dist[i]<<endl;
	}
	return 0;
}
