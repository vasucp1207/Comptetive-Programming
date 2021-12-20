/* Game Master */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

vector<int>g[200005];
vector<int>visit;

void dfs(int id){
	
	visit[id] = 1;
	for(int x: g[id]){
		if(visit[x] != 1){
			dfs(x);
		}
	}
}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		vector<pair<int,int>>a;
		vector<pair<int,int>>b;
		pair<int, int> mx = {-1, -1};
		
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			x--;
			if(x > mx.fi){
				mx = {x, i};
			}
			a.push_back({x, i});
		}
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			x--;
			if(x > mx.fi){
				mx = {x, i};
			}
			b.push_back({x, i});
		}
		
		sort(a.begin(), a.end());	
		sort(b.begin(), b.end());
		
		for(int i = 0; i < n; i++) g[i].clear();
		visit.assign(n, 0);
		for(int i = a.size() - 2; i >= 0; i--){
			g[a[i].se].push_back(a[i + 1].se);
			g[b[i].se].push_back(b[i + 1].se);
		}
		
		dfs(mx.se);	
		for(int i = 0; i < n; i++){
			if(visit[i]) cout << 1;
			else cout << 0;
		}
		cout << endl;
	}
		

	return 0;
}
