#include<iostream>
using namespace std;

int ga[10005][10005]={0},que[10005],r=0,n,m,s,index=1;
bool inque[10005];

struct point{
	int index,lowlink;
}v[10005];

void tarjan(int x)
{
	v[x].index=index;
	v[x].lowlink=index;
	index++;
	r++;
	que[r]=x;
	inque[x]=true;
	for(int i=1;i<=n;i++){
		if(ga[x][i]>0){
			if(v[i].index=0){
				tarjan(i);
				if(v[x].lowlink>v[i].lowlink)
					v[x].lowlink=v[i].lowlink;
			}
			else if(inque[i]){
				if(v[x].lowlink>v[i].index)
					v[x].lowlink=v[i].index;
			}
		}
	} 
	if(v[x].index==v[x].lowlink){
		cout<<"SCC: ";
		int xx;
		do{
			xx=que[r--];
			cout<<xx<<" ";
		}while(xx!=x);
		cout<<endl;
	}
}


int main()
{
	cin>>n>>m;
	int i,j,u,v,w;
	for(i=1;i<=m;i++){
		cin>>u>>v>>w;
		ga[u][v]=w;
	}
	tarjan(1);
	return 0;
}
