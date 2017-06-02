#include<iostream>
using namespace std;

int n,a[10000],b[10000];;

void mst(int f,int r)
{
  if(f==r){
    return;
  }
  int mid=(f+r)/2;
  mst(f,mid);
  mst(mid+1,r);
  int p=f,q=mid+1;
  while(p<=mid && q<=r){
    if(a[p]<=a[q]){
      b[p+q-mid-1]=a[p];
      p++;
    }
    else{
      b[p+q-mid-1]=a[q];
      q++;
    }
  }
  while(p<=mid){
    b[p+q-mid-1]=a[p];
    p++;
  }
  while(q<=r){
    b[p+q-mid-1]=a[q];
    q++;
  }
  for(int i=f;i<=r;i++){
    a[i]=b[i];
  }
}

int main()
{
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  mst(1,n);
  for(int i=1;i<=n;i++){
    cout<<a[i]<<' ';
  }
  return 0;
}
