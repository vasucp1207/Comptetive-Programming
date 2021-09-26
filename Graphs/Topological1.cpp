#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
vector<int>g[maxn];
bool visit[maxn];
vector<int>order;
int n,m,a,b;

void dfs(int node){

  visit[node]=1;

  for(int u:g[node]){
    if(!visit[u])
      dfs(u);
  }
  order.push_back(node);
}

int main(){

  cin>>n>>m;

  while(m--){
    cin>>a>>b;
    g[a].push_back(b);
  }

  for(int i=1;i<=n;i++){
    if(!visit[i])
      dfs(i);
  }

  reverse(order.begin(),order.end());
  for(int i=0;i<order.size();i++)
    cout<<order[i]<<" ";


  return 0;
}
