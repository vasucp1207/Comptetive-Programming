#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second
// std::vector<int>::iterator it;

const int mx = 1000005;
int BIT[mx];
int a[mx];
int n;

void update(int x, int delta){
	
	for(; x <= n; x += x & -x) BIT[x] += delta;
}

int query(int x){
	
	int sum = 0;
	for(; x > 0; x -= x & -x) sum += BIT[x];
	
	return sum;
}

int main(){
	
	int t = 1;
	cin >> t >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		update(i, a[i]);
	}
	while(t--){
		int x;
		cin >> x;
		cout << query(x) << endl;
	}

	return 0;
}
