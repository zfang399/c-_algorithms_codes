#include<iostream>
using namespace std;

int a[10005],b[10005],n;

void msort(int l, int r)
{
	if(l==r) return;
	int s=(l+r)/2;
	msort(l,s);
	msort(s+1,r);
	int i=l,j=s+1;
	while(i<=s && j<=r){
		if(a[i]<=a[j]) b[i+j-s-1]=a[i++];
		else b[i+j-s-1]=a[j++];
	}
	while(i<=s) b[i+j-s-1]=a[i++];
	while(j<=r) b[i+j-s-1]=a[j++];
	for(s=l;s<=r;s++) a[s]=b[s];
} 


int main()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>a[i];
	msort(1,n);
	for(i=1;i<=n;i++) cout<<a[i]<<" ";
	return 0;
}
