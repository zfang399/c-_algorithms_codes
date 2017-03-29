#include<iostream>
#include<cstdio>
using namespace std;

int a[100],n;
void heap(int n, int i)
{
	int j=2*i;
	while (j<=n)
	{
		if (j<n && a[j]<a[j+1]) j++;
		if (a[i]<a[j])
		{
			swap(a[i], a[j]);
			i=j;
			j=2*i;
		}
		else break;
	}
}

int main()
{
	cin>>n;
	int i;
	for(i=1; i<=n; i++) cin>>a[i];
	for(i=n/2; i>=1; i--) heap(n,i);
	for(i=n; i>=1; i--)
	{
		swap(a[i],a[1]);
		heap(i-1,1);
	}
	for (i=1; i<=n; i++) cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}
