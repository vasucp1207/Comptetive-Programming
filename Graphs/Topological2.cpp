#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
vector<int>g[maxn];
bool visit[maxn];
vector<int>order;
int inDeg[maxn];
int n,m,a,b;

void topsort(){

  priority_queue<int,vector<int>, greater<int>>q; //for lexicographically smallest order
  for(int i=1;i<=n;i++){
    if(inDeg[i]==0)
      q.push(i);
  }

  while(!q.empty()){

    int v=q.top();
    order.push_back(v);
    q.pop();

    for(int u:g[v]){
      inDeg[u]--;
      if(inDeg[u]==0)
        q.push(u);
    }
  }

  if(order.size()<n){
    cout<<"IMPOSSIBLE";
    exit(0);
  }

  for(int i=0;i<order.size();i++){
    cout<<order[i]<<" ";
  }
}

int main(){

  cin>>n>>m;

  while(m--){
    cin>>a>>b;
    g[a].push_back(b);
    inDeg[b]++;
  }

  topsort();

  return 0;
}
