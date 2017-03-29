#include<iostream>
using namespace std;

int b,x,p;

int ksm(int m)
{
	if(m==1) return b%p;
	int tmp=ksm(m/2);
	if(m%2) return (tmp*tmp*b)%p;
	else return (tmp*tmp)%p;
}

int main()
{
	cin>>b>>x>>p;
	int ans=ksm(x);
	cout<<ans<<endl;
	return 0;
}
