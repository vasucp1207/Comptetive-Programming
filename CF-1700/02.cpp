// 1611E1 - Escape The Maze (easy version)

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

void solve(){
	
	int n, k;
	cin >> n >> k;
	
	queue<int> q;
	vector<int> color(n, -1);
	for(int i = 0; i < k; i++){
		int x;
		cin >> x;
		x--;
		q.push(x);
		color[x] = 0;
	}
	
	q.push(0);
	color[0] = 1;
	
	vector<int> g[n];
	for(int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	while(!q.empty()){
		int v = q.front();
		q.pop();
		
		for(int u: g[v]){
			if(color[u] == -1){
				color[u] = color[v];
				q.push(u);
			}
		}
	}
	
	// start from 1
	for(int i = 1; i < n; i++){
		if(g[i].size() == 1 && color[i] == 1){
			cout << "YES" << endl;
			return ;
		}
	}
	cout << "NO" << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		solve();
	}
	
	
	

	return 0;
}
