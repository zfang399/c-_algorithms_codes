#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n,s,a,b,na[10005],nb[10005];

int main()
{
  int p;
  cin>>n;
  for(int dm=1;dm<=n;dm++){
    memset(na,0,sizeof(na));
    memset(nb,0,sizeof(nb));
    cin>>s>>a;
    for(int i=1;i<=a;i++){
      cin>>p;
      na[p]++;
    }
    cin>>b;
    for(int i=1;i<=b;i++){
      cin>>p;
      nb[p]++;
    }
    int ans=0;
    for(int i=1;i<=s;i++){
      ans+=na[i]*nb[s-i];
    }
    cout<<ans<<endl;
  }
  return 0;
}
