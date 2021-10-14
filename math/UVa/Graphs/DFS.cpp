#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
vector<int>g[maxn];
bool visit[maxn];
int n,m,a,b;
int comp;

void dfs(int node){

  visit[node]=1;
  //cout<<node<<" ";
  for(int u:g[node]){
    if(!visit[u])
      dfs(u);
  }
}

int main(){

  cin>>n>>m;

  while(m--){
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int i=1;i<=n;i++){
    if(!visit[i]){
      comp++;
      dfs(i);
    }
  }

  cout<<"Components: "<<comp<<endl;



  return 0;
}
