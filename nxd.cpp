#include<iostream>
using namespace std;

int a[10005],b[10005],n,ans=0;

void nxd(int l, int r)
{
	if(l==r) return;
	int s=(l+r)/2;
	nxd(l,s);
	nxd(s+1,r);
	int i=l,j=s+1;
	while(i<=s && j<=r){
		if(a[i]<=a[j]){
			b[i+j-s-1]=a[i++];
			ans+=j-s-1;
		}
		else b[i+j-s-1]=a[j++];
	}
	while(i<=s){
		b[i+j-s-1]=a[i++];
		ans+=j-s-1;
	}
	while(j<=r) b[i+j-s-1]=a[j++];
	for(s=l;s<=r;s++) a[s]=b[s];
} 

int main()
{
	cin>>n;
	int i;
	for(i=1;i<=n;i++) cin>>a[i];
	nxd(1,n);
	cout<<ans<<endl;
	return 0;
}
