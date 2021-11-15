#include <bits/stdc++.h>

using namespace std;

vector<int> seg_tree(1000000);
vector<int> arr(100000);

void recalculate(int node){
	seg_tree[node] = max(seg_tree[2 * node + 1], seg_tree[2 * node + 2]);
}

void build(int node, int l, int r){   // node is the idx in the array, while
                                      // l and r are the ends of the curr segment
	  if(l == r){
		seg_tree[node] = arr[l];  // leaf node
	  }
	  else{
		int mid = (l + r) / 2;
		build(2 * node + 1, l, mid);   // left son
		build(2 * node + 2, mid + 1, r);   // right son
		
		recalculate(node);
	  }                                 
}

void update(int node, int l, int r, int x, int y){
	
	if(l == r){
		seg_tree[node] = y;
	}
	else{
		int mid = (l + r) / 2;
		if(x <= mid)
			update(2 * node + 1, l, mid, x, y);
		else
			update(2 * node + 2, mid + 1, r, x, y);
			
		recalculate(node);
	}
}

int query(int node, int l, int r, int x, int y){
	 
	if(x <= l && y >= r){      //the segment of "node" is completely included in the query
		return seg_tree[node];
	}
	else{
		int ans = -10e9;
		int mid = (l + r) / 2;
		
		if(x <= mid){
			ans = max(ans, query(2 * node + 1, l, mid, x, y));
		}
		if(y >= mid + 1){
			ans = max(ans, query(2 * node + 2, mid + 1, r, x, y));
		}		
		return ans;
	}
}

int main(){
	
	

return 0;
}
