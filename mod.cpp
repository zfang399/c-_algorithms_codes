#include<cstdio>
#include<iostream>
using namespace std;
int a,c,i,j,m,n;
long long b,p,k;
long long ksm(long long p){
	if(p==1)return b%k;
	long long t;
	t=ksm(p/2);
	t%=k;
	if(p%2==0){
		return (((t%k)*(t%k))%k);
	}
	else {
		return (((t%k)*(t%k)*b)%k);
	}
}
int main()
{
	cin>>b>>p>>k;
    cout<<ksm(p);
    cout<<endl;
	return 0;
}
