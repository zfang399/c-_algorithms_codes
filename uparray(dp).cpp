#include<iostream>
using namespace std;

int a[1005],n,up[1005]={0};

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    up[i]=1;
  }
  for(int i=2;i<=n;i++){
    for(int j=1;j<i;j++){
      if(up[j]+1>up[i] && a[i]>a[j]) up[i]=up[j]+1;
    }
  }
  cout<<up[n]<<endl;
  return 0;
}
