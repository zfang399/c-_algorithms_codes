#include<iostream>
using namespace std;

int a[10005],n,len=0,t[10005]={0};

int half(int x)
{
	int mid,l=1,r=len;
	while(l<r-1){
		mid=(l+r)/2;
		if(t[mid]<x) l=mid;
		else r=mid;
	}
	if(r==len){
		if(len!=0 && t[r]>x){
			len--;
		}
		len++;
		r=len;
	}
	return r;
}

int main()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		t[half(a[i])]=a[i];
	}
	cout<<len<<endl;
	return 0;
}
