// 339D - Xenia and Bit Operations.cpp

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

vector<int>arr;
vector<int>seg(1000000);

void recalculate(int node, bool op){
	if(op == 0){
		seg[node] = (seg[2 * node + 1] ^ seg[2 * node + 2]);
	} else{
		seg[node] = (seg[2 * node + 1] | seg[2 * node + 2]);
	}
}

void build(int node, int l, int r, bool op){
	if(l == r){
		seg[node] = arr[l];
	}
	else{
		int mid = (l + r) / 2;
		build(2 * node + 1, l, mid, !op);
		build(2 * node + 2, mid + 1, r, !op);
		recalculate(node, op);
	}
}

void update(int node, int l, int r, int x, int y, bool op){
	if(l == r){
		seg[node] = y;
	}
	else{
		int mid = (l + r) / 2;
		if(x <= mid){
			update(2 * node + 1, l, mid, x, y, !op);
		}
		else{
			update(2 * node + 2, mid + 1, r, x, y, !op);
		}
		recalculate(node, op);
	}
}

int main(){
	
	int n, m;
	cin >> n >> m;
	
	for(int i = 0; i < (pow(2, n)); i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	
	bool op;
	if(n % 2){
		op = 1;
	} else{
		op = 0;
	}
	
	build(0, 0, arr.size() - 1, op);
//	for(int i = 0; i < seg.size() - 1; i++) cout << seg[i] << " ";
	
	while(m--){
		int x, y;
		cin >> x >> y;
		x--;y;
		update(0, 0, arr.size() - 1, x, y, op);
		cout << seg[0] << endl;
	}

	

	return 0;
}
