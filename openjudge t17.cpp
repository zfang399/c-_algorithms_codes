#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int i,j;
	for (i=0, j=0; i<a.size(), j<b.size();)
	{
		while (a[i]==' ')
		{
			i++;
		}
		while (b[j]==' ')
		{
			j++;
		}
		if (a[i]==b[j] || a[i]-b[j]==32 || b[j]-a[i]==32)
		{
			i++;
			j++;
		}
		else
		{
			cout<<"NO"<<endl;
			return 0;
		}
	}
	
	cout<<"YES"<<endl;
	return 0;
}
