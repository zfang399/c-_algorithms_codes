#include<iostream>
#include<algorithm>
using namespace std;

struct point{
  int x,y,h;
}p[10005];

bool cmp(point a, point b)
{
  return a.h<b.h;
}

int m[505][505]={0},level[505][505]={0},n;

int main()
{
  cin>>n;
  int t;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      cin>>m[i][j];
      p[(i-1)*n+j].x=i;
      p[(i-1)*n+j].y=j;
      p[(i-1)*n+j].h=m[i][j];
      level[i][j]=1;
    }
  }
  sort(p+1,p+n*n+1,cmp);
  int xn,yn;
  int maxm=-1;
  for(int i=1;i<=n*n;i++){
    xn=p[i].x;
    yn=p[i].y;
    if(xn+1<=n){
      if(m[xn][yn]>m[xn+1][yn]) level[xn][yn]=max(level[xn][yn],level[xn+1][yn]+1);
    }
    if(xn-1>=1){
      if(m[xn][yn]>m[xn-1][yn]) level[xn][yn]=max(level[xn][yn],level[xn-1][yn]+1);
    }
    if(yn+1<=n){
      if(m[xn][yn]>m[xn][yn+1]) level[xn][yn]=max(level[xn][yn],level[xn][yn+1]+1);
    }
    if(yn-1>=1){
      if(m[xn][yn]>m[xn][yn-1]) level[xn][yn]=max(level[xn][yn],level[xn][yn-1]+1);
    }
    if (level[xn][yn]>maxm) maxm=level[xn][yn];
  }
  cout<<maxm;
  return 0;
}
