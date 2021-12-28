/* Array Stabilization (AND version) */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

int main(){

	int t = 1;
	cin >> t;
	
	while(t--){
		
		int n, d;
		cin >> n >> d;
		
		vector<int> dis(n, 100000000);
		queue<int> q;
		
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x == 0){
				dis[i] = 0;
				q.push(i);
			}
		}
		
		while(!q.empty()){
			int v = q.front();
			q.pop();
			int u = (v + d) % n;
			if(dis[u] > dis[v] + 1){
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
		
		int res = 0;
		for(int i = 0; i < n; i++){
			res = max(res, dis[i]);
		}
		if(res >= 100000000) cout << -1 << endl;
		else cout << res << endl;
	}
		

	return 0;
}
