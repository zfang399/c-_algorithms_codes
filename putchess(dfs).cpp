#include<iostream>
#include<cstring>
using namespace std;

int n,k;
bool b[9][9]={false},visited[9][9]={false},r[9],c[9];

int put(int x, int y, int re)
{
  if(re==0) return 1;
  int sum=0;
  visited[x][y]=true;
  r[x]=true;
  c[y]=true;
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      if(b[i][j] && !visited[i][j] && !r[i] && !c[j]){
        sum+=put(i,j,re-1);
      }
    }
  }
  visited[x][y]=false;
  r[x]=false;
  c[y]=false;
  return sum;
}

int combi(int x)
{
  int fac=1;
  while(x!=0){
    fac=fac*x;
    x--;
  }
  return fac;
}

int main()
{
  while(cin>>n>>k){
    if(n==-1 && k==-1){
      break;
    }
    memset(b,0,sizeof(b));
    memset(visited,0,sizeof(visited));
    memset(r,0,sizeof(r));
    memset(c,0,sizeof(c));
    char t;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        cin>>t;
        if(t=='#') b[i][j]=1;
      }
    }
    cout<<put(0,0,k)/combi(k)<<endl;
  }
  return 0;
}
