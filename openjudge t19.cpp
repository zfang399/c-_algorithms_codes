#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

string s1,s2;
int l1,l2;
int ans=0;
int lmax,lmin;

void search(string ss1, string ss2, int depth)
{
	if (depth>=lmax) return;
	int i,j;
	for (i=0; i<=lmax-lmin; i++)
	{
		int flag=1;
		for(j=i; j<i+lmin; j++)
			if(ss1[j]!=ss2[j-i])
			{
				flag=0;
				cout<<"aborted"<<endl;
				cout<<i<<j<<endl;
				break;
			}
		if(flag==1)
		{
			ans=1;
			return;
		}
	}
	if (ans==1) return;
	else search(ss1.substr(1,lmax-1)+ss1[0], ss2, depth+1);
}

int main()
{
	cin>>s1>>s2;
	l1=s1.size();
	l2=s2.size();
	lmax=max(l1,l2);
	lmin=min(l1,l2);
	int ans;
	if (l1>=l2) search(s1,s2,0);
	else search(s2, s1, 0);
	
	if (ans==1) cout<<"true"<<endl;
	else cout<<"false"<<endl;
}



