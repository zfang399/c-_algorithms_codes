#include<iostream>
#include<cstring>
using namespace std;

bool b[4][31]={false};
int n;

int cover(int rem)
{
  if(rem==0) return 1;
  int sum=0;
  for(int i=1;i<=3;i++){
    for(int j=1;j<=n;j++){
      if(!b[i][j]){
        b[i][j]=1;
        if(i+1>=1 && i+1<=3 && !b[i+1][j]){
          b[i+1][j]=1;
          sum+=cover(rem-1);
          b[i+1][j]=0;
        }
        if(j+1>=1 && j+1<=n && !b[i][j+1]){
          b[i][j+1]=1;
          sum+=cover(rem-1);
          b[i][j+1]=0;
        }
        b[i][j]=0;
        return sum;
      }
    }
  }
  return 0;
}

int main()
{
  while(cin>>n){
    memset(b,false,sizeof(b));
    if(n==-1) break;
    if(n%2==1){
      cout<<0<<endl;
    }
    else{
      int num=(3*n)/2;
      cout<<cover(num);
    }
  }
  return 0;
}
