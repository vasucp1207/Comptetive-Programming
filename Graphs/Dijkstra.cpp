#include<bits/stdc++.h>

using namespace std;

#define ll long long
vector<pair<ll,ll>>adj[100005]; //node and edge(distance)
bool visit[100005];
ll n, m, a, b, w;

int main(){

    cin >> n >> m;
    while(m--){
      cin >> a >> b >> w;
      adj[a].push_back({b, w});
      adj[b].push_back({a, w});
    }
    // priority_queue<pair<ll,ll>>pq;                                               //with max heap algo is correct but we get TLE
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;         //min heap

    vector<ll>path(n+1);
    vector<ll>dist(n+1, 1e17);
    
    pq.push({0, 1});                 //distance of node from the source node and, the node
    dist[1] = 0;
    visit[1] = 1;

    while(!pq.empty()){
        
      ll curr = pq.top().second;             //top element which is smallest by weight
      ll curr_dist = pq.top().first;           // curr distance of the node form the source
      pq.pop();

      for(pair<ll, ll>edge: adj[curr]){
          
        if(curr_dist + edge.second < dist[edge.first]){
            
          dist[edge.first] = curr_dist + edge.second;
          pq.push({dist[edge.first], edge.first});
          path[edge.first] = curr;
        }
      }
    }

    //for(int i=1;i<=n;i++)cout<<dist[i]<<" ";

    vector<ll>restore_path;

    if(dist[n] == 1e17){ //path from 1->n is not possible
      cout << -1;
      return 0;
    }
    for(ll i = n; i != 1; i = path[i]){
      restore_path.push_back(i);
    }

    restore_path.push_back(1);

    for(ll i = restore_path.size()-1; i >= 0 ;i--){
      cout << restore_path[i] << " ";
    }


  return 0;
}
