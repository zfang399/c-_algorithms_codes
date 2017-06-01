#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector <int> moves[10];
vector <int> c;
vector <int> nouse;
queue <vector<int> >q;
queue <vector<int> > step;
vector <int> u;


int main()
{
  c.push_back(0);
  int tmp;
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      cin>>tmp;
      c.push_back(tmp);
    }
  }
  moves[1].push_back(1),moves[1].push_back(2),moves[1].push_back(4),moves[1].push_back(5);
  moves[2].push_back(1),moves[2].push_back(2),moves[2].push_back(3);
  moves[3].push_back(2),moves[3].push_back(3),moves[3].push_back(5),moves[2].push_back(6);
  moves[4].push_back(1),moves[4].push_back(4),moves[4].push_back(7);
  moves[5].push_back(2),moves[5].push_back(4),moves[5].push_back(5),moves[5].push_back(6),moves[5].push_back(8);
  moves[6].push_back(3),moves[6].push_back(6),moves[6].push_back(9);
  moves[7].push_back(4),moves[7].push_back(5),moves[7].push_back(7),moves[7].push_back(8);
  moves[8].push_back(7),moves[8].push_back(8),moves[8].push_back(9);
  moves[9].push_back(5),moves[9].push_back(6),moves[9].push_back(8),moves[9].push_back(9);
  q.push(c);
  step.push(nouse);
  while(!q.empty()){
    vector <int> t=q.front();
    u=step.front();
    vector <int> tt=t;
    vector <int> uu=u;
    step.pop();
    q.pop();
    bool success=true;;
    for(int i=1;i<=9;i++){
      if(t[i]!=0){
        success=false;
      }
    }
    if(success){
      break;
    }
    for(int i=1;i<=9;i++){
      u.push_back(i);
      for(int j=0;j<moves[i].size();j++){
        t[moves[i][j]]++;
        if(t[moves[i][j]]==4){
          t[moves[i][j]]=0;
        }
      }
      q.push(t);
      step.push(u);
      t=tt;
      u=uu;
    }
  }
  for(int i=0;i<u.size();i++){
    cout<<u[i]<<" ";
  }
  cout<<endl;
  return 0;
}
