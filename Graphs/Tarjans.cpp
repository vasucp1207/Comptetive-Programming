#include<bits/stdc++.h>

using namespace std;

const int maxn = 200005;
vector<int>g[maxn];
int n, m, a, b;
bool visit[maxn];
bool onSt[maxn];
int in[maxn], low[maxn];

int timer = 1, SCC = 0;
stack<int> st;

void dfs(int node){

  visit[node] = 1;
  in[node] = low[node] = timer++;
  onSt[node] = 1;
  st.push(node);

  for(int u : g[node]){
    if((visit[u]) && (onSt[u])){
      low[node] = min(low[node], in[u]);
    }
    else{
      if(visit[u] == false){
        dfs(u);

        if(onSt[u])
          low[node] = min(low[node], low[u]);
      }
    }
  }

  if(in[node] == low[node]){
    SCC++;
    cout<<"SCC #"<<SCC<<endl;

    int u;
    while(1){
      u = st.top();
      st.pop();
      onSt[u] = false;
      cout<<u<<" ";

      if(u == node)break;
    }
    cout<<endl;
  }
}

int main(){

    cin>>n>>m;

    while(m--){
      cin>>a>>b;
      g[a].push_back(b);
    }

    for(int i = 1; i <= n; i++){
      if(visit[i] == false)
          dfs(i);
    }



  return 0;
}
