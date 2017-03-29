#include<iostream>
using namespace std;

int ga[10005][10005],c[10005],q[10005];
int d[10005],n,k,m,s,e;
bool t[10005][10005],inque[10005];

int main()
{
	cin>>n>>k>>m>>s>>e;
	int i,j,u,v,w;
	for(i=1;i<=n;i++) cin>>c[i];
	for(i=1;i<=k;i++)
		for(j=1;j<=k;j++){
			cin>>t[i][j];
		}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++) ga[i][j]=99999999;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		ga[u][v]=w;
		ga[v][u]=w;
		if (t[c[u]][c[v]]==1)   ga[v][u] = 99999999;
        if (t[c[v]][c[u]]==1)   ga[u][v] = 99999999;
	}
	for(i=1;i<=n;i++){
		if(c[i]==c[e]){
			ga[s][i]=99999999;
		}
	}
	for(i=1;i<=n;i++){
		inque[i]=false;
		d[i]=99999999;
	}
	int f=0,r=0,x;
	r++;
	q[r]=s;
	d[s]=0;
	inque[s]=true;
	while(f<r){
		f++;
		x=q[f];
		inque[x]=false;
		for(i=1;i<=n;i++){
			if(c[x]!=c[i] && ga[x][i]>0 && ga[x][i]+d[x]<d[i]){
				d[i]=ga[x][i]+d[x];
				if(!inque[i]){
					r++;
					q[r]=i;
					inque[i]=true;
				}
			}
		}
	}
    if(d[e]==99999999 || c[s]==c[e]) cout<<"-1"<<endl;
    else cout<<d[e]<<endl;
    return 0;
} 
