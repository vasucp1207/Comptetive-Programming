#include <bits/stdc++.h>

using namespace std;

vector<int> arr;
vector<int> seg_tree;

void recalculate(int node){
	
	seg_tree[node] = max(seg_tree[2 * node + 1], seg_tree[2 * node + 2]);
}

void build(int node, int l, int r){   //"node" is the index in the array
	
	if(l == r){
		seg_tree[node] = arr[l];
	}
	else{
		int mid = (l + r) / 2;
		build(2 * node + 1, l, mid);
		build(2 * node + 2, mid + 1, r);
		
		recalculate(node);
	}
}

void update(int node, int l, int r, int x, int y){
	
	if(l == r){     //we are in the xth leaf
		seg_tree[node] = y;
	}
	else{
		int mid = (l + r) / 2;
		if(x <= mid){
			update(2 * node + 1, l, mid, x, y);
		}
		else{
			update(2 * node + 2, mid + 1, r, x, y);
		}
		recalculate(node);
	}
}

int query(int node, int l, int r, int x, int y){
	
	if(x <= l && y >= r){  //the segment of "node" is completely included in the query
		return seg_tree[node];
	}
	else{
		int ans = -10e9;
		int mid = (l + r) / 2;
		if(x <= mid){
			//the query segment and the left son segment,
			//have at least one element in common
			ans = max(ans, query(2 * node + 1, l, mid, x, y));
		}
		if(y >= mid + 1){
			ans = max(ans, query(2 * node + 2, mid + 1, r, x, y));
		}
		
		return ans;
	}
}

int main(){
	
	int n;
	cin >> n;
	
	arr.resize(n);
	seg_tree.resize(2 * n - 1);
	for(int i = 0; i < n; i++) cin >> arr[i];
	
	build(0, 0, n - 1);
	
	int t;
	cin >> t;
	
	while(t--){
		
		int x, y, st, en;
		cin >> x >> y >> st >> en;
		
		update(0, 0, n - 1, x, y);
		cout << query(0, 0, n - 1, st, en) << endl;
	}
	
	
	

return 0;
}
