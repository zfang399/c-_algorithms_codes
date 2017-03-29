#include<iostream>
#include<cstdio>
using namespace std;

int fbnc(int n)
{
	if (n==1 || n==2) return 1;
	return fbnc(n-1)+fbnc(n-2);
}

int main()
{
	int n;
	cin>>n;
	cout<<fbnc(n)<<endl;
	return 0;
 } 
