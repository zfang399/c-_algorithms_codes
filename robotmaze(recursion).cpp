#include<iostream>
using namespace std;

int r,c;
bool maze[1000][1000]={false};

bool recur(int x, int y)
{
  if(x==1 && y==1){
    cout<<'('<<x<<','<<y<<')'<<endl;
    return true;
  }
  if(x-1>=1){
    bool tryone=recur(x-1,y);
    if(tryone){
      cout<<'('<<x<<','<<y<<')'<<endl;
      return true;
    }
  }
  if(y-1>=1){
    bool trytwo=recur(x,y-1);
    if(trytwo){
      cout<<'('<<x<<','<<y<<')'<<endl;
      return true;
    }
  }
  return false;
}

int main()
{
  cin>>r>>c;
  int t;
  for(int i=1;i<=r;i++){
    for(int j=1;j<=c;j++){
      cin>>t;
      if(!t){
        maze[i][j]=true;
      }
    }
  }
  bool k=recur(r,c);
  return 0;
}
