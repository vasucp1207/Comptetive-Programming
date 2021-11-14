#include <bits/stdc++.h>

using namespace std;

vector<int> no_Internet;

struct union_find{
	
	vector<int> parent;
	union_find(int n){
		
		parent = vector<int>(n);
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}

	int find(int x){
		
		if(parent[x] == x)
			return x;
		
		else{
			parent[x] = find(parent[x]);
			return parent[x];
		}
	}
	
	void unite(int x, int y){
		parent[find(x)] = find(y);
	}
};

int main(){

	int n, m;
	cin >> n >> m;
	
	union_find myUnion(n);
	
	for(int i = 1; i <= m; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		myUnion.unite(u, v);
	}
	
	for(int i = 0; i < n; i++){
		int rep = myUnion.find(i);
		int par = myUnion.find(0);
		if(rep != par) no_Internet.push_back(i);
	}
	
	if(!no_Internet.size()){
		cout << "Connected" << endl;
	}else{
		for(int i = 0; i < no_Internet.size(); i++)
			cout << no_Internet[i] + 1 << endl;
	}cout << endl;


return 0;
}
