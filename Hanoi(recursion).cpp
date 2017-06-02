#include<iostream>
using namespace std;

void Hanoi(int n,char f,char mid,char r)
{
  if(n==1){
    cout<<f<<"->"<<r<<endl;
    return;
  }
  Hanoi(n-1,f,r,mid);
  cout<<f<<"->"<<r<<endl;
  Hanoi(n-1,mid,f,r);
}

int main()
{
  int n;
  cin>>n;
  Hanoi(n,'A','B','C');
  return 0;
}
