#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int n;
string a[21],b[21];
int la[21],lb[21];
string aa,bb;
bool use[21];
int best=1000;

void search(int depth,int a1,int b1)
{
    if (depth >= best) return;

    if (depth > 0 && a1 == b1){
        if (depth < best){
        	best = depth;
            return;
		}
    }

    int i;
    for (i=1;i<=n;i++)
    if (!use[i]){
    	int asize=aa.size();
    	int bsize=bb.size();
        aa+=a[i];
        bb+=b[i];
        int from,to;
        if(a1<b1) from=a1;
        else from=b1;
        if(a1+la[i]<b1+lb[i]) to=a1+la[i];
        else to=b1+lb[i]; 
        to--;
        int flag = 1;
        for (int j=from;j<=to;j++)
            if(aa[j]!=bb[j]){
            	flag = 0;
                break;
            }
        if (flag){
            use[i]=1;
            search(depth+1,a1+la[i],b1+lb[i]);
            use[i]=0;
        }
        aa=aa.substr(0,asize);
        bb=bb.substr(0,bsize);
    }
}

int main()
{
    cin>>n;
    int i;
    for (i=1;i<=n;i++){
        cin>>a[i];
        la[i]=a[i].size();
	}
	for (i=1;i<=n;i++){
        cin>>b[i];
       lb[i]=b[i].size();
    }
    memset(use,0,sizeof(use));
    search(0,0,0);
    if (best==1000) cout<<0<<endl;
    else
    cout<<best<<endl;
}
