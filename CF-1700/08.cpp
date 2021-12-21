/* The Number of Imposters */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

vector<pair<int, int>> g[200005];
int cnt[2];
vector<int> color;
bool flag;

void dfs(int node){
	
	cnt[color[node]]++;
	
	for(auto x: g[node]){
		if(color[x.fi] == -1){
			color[x.fi] = color[node] ^ x.se;
			dfs(x.fi);
		}
		else if(color[x.fi] != color[node] ^ x.se){
			flag = false;
		}
	}
}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		int n, m;
		cin >> n >> m;
		
		color.assign(n, -1);
		for(int i = 0; i < n; i++) g[i].clear();
		for(int i = 0; i < m; i++){
			int u, v;
			cin >> u >> v;
			u--; v--;
			string s;
			cin >> s;
			if(s[0] == 'c'){  // same team
				g[u].push_back({v, 0});
				g[v].push_back({u, 0});
			}
			else{
				g[u].push_back({v, 1});
				g[v].push_back({u, 1});				
			}
		}
		
		// 0 --> C, 1 --> I
		int ans = 0;
		flag = true;
		for(int i = 0; i < n; i++){
			if(color[i] == -1){
				cnt[0] = cnt[1] = 0;
				color[i] = 0;  // assume for crewmate
				dfs(i);
				ans += max(cnt[0], cnt[1]);  // no need for 2nd dfs just reverse the C and I for when 1 == I
			}
		}
		if(!flag){
		  cout << -1 << endl; continue;  
		} 
		cout << ans << endl;
	}
		

	return 0;
}
