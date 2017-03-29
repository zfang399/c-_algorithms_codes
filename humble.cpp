#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m,n;
	cin>>m>>n;
	int a[101],aindex[101],hum[100002];
	hum[1]=1;
	for (int i=1; i<=m; i++)
	{
		cin>>a[i];
		aindex[i]=1;
	}
	
	int nhum=1; nhum++;
	while(nhum<=n+1)
	{
		int min=2000000000;
		int minp=-1;
		
		for (int i=1; i<=m; i++)
		{
			while (hum[nhum-1]==a[i]*hum[aindex[i]])
			{
				aindex[i]++;
			}
		}
		
		for (int i=1; i<=m; i++)
		{
			if (a[i]*hum[aindex[i]]<min)
			{
				min=a[i]*hum[aindex[i]];
				minp=i;
			}
		}
		
		hum[nhum]=min;
		nhum++;
		aindex[minp]++;
	}
	
	cout<<hum[n+1]<<endl;
	
	return 0;
}
