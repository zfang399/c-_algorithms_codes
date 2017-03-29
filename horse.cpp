#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,t[2005],q[2005],g[2005][2005];

int run(int a,int b)
{
	if(t[a]>q[b]) return 200;
	else if(t[a]<q[b]) return -200;
	else return 0; 
}

bool cmp(int a, int b)
{
	return a>b;
}

int main()
{
	cin>>n;
	int i,j;
	for(i=1;i<=n;i++) cin>>t[i];
	for(i=1;i<=n;i++) cin>>q[i];
	sort(t+1,t+n+1,cmp);
	sort(q+1,q+n+1,cmp);
	g[0][0]=0;
	for(i=1;i<=n;i++){
		g[0][i]=g[0][i-1]+run(n-i+1,i);
	}
	for(i=1;i<=n;i++){
		g[i][0]=g[i-1][0]+run(i,i);
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n-i;j++){
			if(g[i-1][j]+run(i,i+j)>g[i][j-1]+run(n-j+1,i+j)) 
				g[i][j]=g[i-1][j]+run(i,i+j);
			else g[i][j]=g[i][j-1]+run(n-j+1,i+j);
		}
	}
	int ans=-1000000;
	for(i=0;i<=n;i++){
		if(g[i][n-i]>ans)
			ans=g[i][n-i];
	}
	cout<<ans<<endl; 
	return 0;
}
