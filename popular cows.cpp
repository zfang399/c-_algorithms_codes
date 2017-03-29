#include<iostream>
using namespace std;

struct point{
	int index,lowlink;
}v[10001];

int n,index=1,q[10001],r=0,m,i,j,b;
bool ga[10001][10001]={false},visited[10001],inque[10001];

void tarjan(int x)
{
	visited[x]=true;
	v[x].index=index;
	v[x].lowlink=index;
	index++;
	r++;
	q[r]=x;
	inque[x]=true;
	for(int i=1;i<=n;i++){
		if(ga[x][i]){
			if(v[i].index==0){
				tarjan(i);
				if(v[x].lowlink>v[i].lowlink)
					v[x].lowlink=v[i].lowlink;
			}
			else if(inque[i]){
				if(v[x].lowlink>v[i].lowlink)
					v[x].lowlink=v[i].lowlink;
			}
		}
	}
	if(v[x].index==v[x].lowlink){
		int xx;
		do{
			xx=q[r];
			r--;
			inque[xx]=false;
			}while(xx!=x);
	}
}

int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++){
		cin>>j>>b;
		ga[j][b]=true;
	}
	for(i=1;i<=n;i++){
		if(!visited[i])
			tarjan(i);
	}
	for(i=1;i<=n;i++){
		inque[i]=false;
		visited[i]=false;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(ga[i][j] && v[i].lowlink!=v[j].lowlink){
				visited[v[i].lowlink]=true;
			}
		}
	}
	for(i=1;i<=n;i++){
		q[i]=0;
		if(!visited[v[i].lowlink]) inque[v[i].lowlink]=true;
	}
	for(i=1;i<=n;i++){
		b=v[i].lowlink;
		q[b]++;
	}
	b=0,j=0;
	for(i=1;i<=n;i++){
		if(inque[i]){
			j++;
			b=i;;
		}
	}
	if(j>1) cout<<0<<endl;
	else cout<<q[v[b].lowlink]<<endl;
	return 0;
}
