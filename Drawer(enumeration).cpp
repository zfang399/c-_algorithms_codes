#include<iostream>
#include<string>
#include<iomanip>
#include<cstring>
#include<cmath>
using namespace std;

int t;
int n;
bool brick[16][17]={false};
bool press[16][17]={false};

int guess(){
  int c,r,count=0;
  for(r=1;r<=n-1;r++){
    for(c=1;c<=n;c++){
      press[r+1][c]=(brick[r][c]+press[r-1][c]+press[r][c-1]+press[r][c+1]+press[r][c])%2;
      if(press[r+1][c]) count++;
    }
  }
  for(c=1;c<=n;c++){
    if((press[n][c]+press[n-1][c]+press[n][c-1]+press[n][c+1])%2!=brick[n][c]){
      return 225;
    }
  }
  return count;
}

int main()
{
  cin>>t;
  for (int nc=1;nc<=t;nc++){
    cin>>n;
    string tmp;
    memset(brick,0,sizeof(brick));
    memset(press,0,sizeof(brick));
    for(int i=1;i<=n;i++){
      cin>>tmp;
      for(int j=1;j<=n;j++){
        if(tmp[j-1]=='y'){
          brick[i][j]=0;
        }
        else{
          brick[i][j]=1;
        }
      }
    }
    int max=225,prev=0;
    int i;
    for(i=1;i<=int(pow(2,n));i++){
      int now=guess();
      if(now+prev<max){
        max=now+prev;
      }
      memset(press,0,sizeof(brick));
      int x=i;
      int lol;
      for(int y=n;y>=1;y--){
        lol=x%2;
        press[1][y]=lol;
        x=(x-lol)/2;
      }
      prev=0;
      for(int c=1;c<=n;c++){
        if(press[1][c]) prev++;
      }
    }
    if(max==225){
      cout<<"inf"<<endl;
    }
    else{
      cout<<max<<endl;
    }
  }
  return 0;
}
