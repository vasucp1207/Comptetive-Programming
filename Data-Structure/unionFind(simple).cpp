#include<bits/stdc++.h>

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define popcount(x) __builtin_popcountll(x)
#define all(x) (x).begin(), (x).end()

using namespace std;

const int N = 2e5 + 5;
int parent[N];
int rnk[N];

void make_set(int v){
	parent[v] = v;
	rnk[v] = 0;
}

int find_set(int v){
	if(v == parent[v])
		return v;
	return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b){
	a = find_set(a);
	b = find_set(b);
	if(a != b){
		if(rnk[a] < rnk[b])
			swap(a, b);
		parent[b] = a;
		if(rnk[a] == rnk[b])
			rnk[a]++;
	}
}
 
int main() {
	
	std::ios::sync_with_stdio(false);
	cin.tie(NULL); 
	
	int n, m, k;
	cin >> n;
	for(int i = 1; i <= n; i++){
		make_set(i);
	}
	
	cin >> m;
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		union_sets(u, v);
	}
	
	cin >> k;
	for(int i = 1; i <= k; i++){
		int x;
		cin >> x;
		cout << find_set(x) << endl;
	}
		
	
	
 
	return 0;
}
