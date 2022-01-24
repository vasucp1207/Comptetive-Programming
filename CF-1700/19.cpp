/* Navigation System */

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second

const int mod = 1e9 + 7;

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("inputcf.txt" , "r" , stdin);
    freopen("outputcf.txt", "w", stdout);
	#endif

	int n, m;
	cin >> n >> m;
	vector<int> g[n + 1], rev[n + 1];
	
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		rev[v].pb(u);
	}	

	int k;
	cin >> k;
	vector<int> path(n + 1);
	for(int i = 1; i <= k; i++) cin >> path[i];

	vector<int> dis(n + 1, 1e9);
	dis[path[k]] = 0; // source node
	queue<int> q;
	q.push(path[k]);

	while(q.size()){

		int v = q.front();
		q.pop();
		for(int u: rev[v]){
			if(dis[v] + 1 < dis[u]){
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
	}

	int mn = 0, mx = 0;
	for(int i = 2; i < k; i++){
		if(dis[path[i]] != dis[path[i - 1]] - 1) mn++;
	}
	cout << mn << " ";

	for(int i = 2; i < k; i++){
		if(dis[path[i]] != dis[path[i - 1]] - 1) mx++;
		else{
			for(int x: g[path[i - 1]]){
				if(dis[x] == dis[path[i - 1]] - 1 && x != path[i]){
					mx++;
					break;
				}
			}
		}
	}
	cout << mx << endl;



	return 0;
}
