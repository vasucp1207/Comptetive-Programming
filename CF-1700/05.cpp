/* Bakry and Partitioning */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

vector<int> xoor;
vector<int> visit;
vector<int> a;
vector<int> parent;
vector<int> g[200005];
void dfs(int node){
	
	visit[node] = true;
	xoor[node] = a[node];
	for(int x: g[node]){
		if(!visit[x]){
			parent[x] = node;
			dfs(x);
			xoor[node] ^= xoor[x]; 
		}
	}
}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		int n, k;
		cin >> n >> k;
		
		a.assign(n, 0);
		for(int i = 0; i< n ;i++) cin >> a[i];

        for(int i = 0; i < n; i++) g[i].clear();
		for(int i = 0; i < n - 1; i++){
			int u, v;
			cin >> u >> v;
			u--, v--;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		xoor.assign(n, 0);
		visit.assign(n, 0);
		parent.assign(n, 0);
		parent[0] = -1;
		dfs(0);
		
		if(xoor[0] == 0){
			cout << "YES" << endl;
			continue;
		}
		
		int idx = -1;
		vector<int> path(n, 0);
		for(int i = 1; i < n; i++){
			if(xoor[i] == xoor[0]){
				idx = i;
			}
		}
		
		for(int i = idx; i != -1; i = parent[i]){
			path[i] = 1;
		}
		
		if(idx == -1){
			cout << "NO" << endl;
			continue;
		}
		
		bool flag = false;
		for(int i = 1; i < n; i++){
			if(i == idx) continue;
			if(xoor[i] == xoor[0] && !path[i]){
				flag = true;
				break;
			}
			if(xoor[i] == 0 && path[i]){
				flag = true;
				break;
			}
		}
		if(flag && k > 2) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
		

	return 0;
}
