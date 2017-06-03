#include<iostream>
#include<vector>
using namespace std;

int n,r,k;
int mindis=-1;
bool visited[105]={false};
vector <int> ga[105];
vector <int> gm[105];
vector <int> gl[105];

void dfs(int cit, int dis, int mon)
{
  if(dis>mindis && mindis!=-1) return;
  if(visited[cit]) return;
  if(mon<0) return;
  if(cit==n){
    if(dis<mindis || mindis==-1) mindis=dis;
    return;
  }
  visited[cit]=true;
  for(int i=0;i<ga[cit].size();i++){
    dfs(ga[cit][i],dis+gl[cit][i],mon-gm[cit][i]);
  }
  visited[cit]=false;
}

int main()
{
  cin>>k>>n>>r;
  int s,f,l,m;
  for(int i=1;i<=r;i++){
    cin>>s>>f>>l>>m;
    ga[s].push_back(f);
    gl[s].push_back(l);
    gm[s].push_back(m);
  }
  dfs(1,0,k);
  cout<<mindis<<endl;
  return 0;
}
