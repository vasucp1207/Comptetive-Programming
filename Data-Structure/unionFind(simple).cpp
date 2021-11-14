#include <bits/stdc++.h>

using namespace std;

struct union_find{
	
	vector<int> parent;
	union_find(int n){
		
		parent = vector<int>(n);
		for(int i = 0; i < n; i++)
			parent[i] = i;             // initially all items is in diff set,
			                           // and itself representative of that set
	}
};

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
