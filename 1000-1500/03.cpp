// And Matching

#include<bits/stdc++.h>

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
#define all(x) (x).begin(), (x).end()

// const int mod = 1e9 + 7;

using namespace std;

void solve(){
	
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>>a(n / 2);
	
	for(int i = 0; i < n / 2; i++){
		a[i].fi = i;
		a[i].se = n - i - 1;
	}
	
	if(n == 4 && k == 3){
		cout << -1 << endl;
		return ;
	}
	if(k == 0){
		for(int i = 0; i < n / 2; i++){
			cout << a[i].fi << " " << a[i].se << endl;
		}
		cout << endl;
	}
	else if(k < n - 1){
		a[0].fi = k;
		int tar = k;
		for(int i = 1; i < n / 2; i++){
			int x = a[i].fi;
			int y = a[i].se;
			if(x == tar) a[i].fi = 0;
			if(y == tar) a[i].se = 0;
		}
		for(int i = 0; i < n / 2; i++){
			cout << a[i].fi << " " << a[i].se << endl;
		}
		cout << endl;
	}
	else if(k == n - 1){
		a[0].fi = k - 1;
		a[1].se = 2;
		a[1].fi = 0;
		a[2].fi = 1;
		for(int i = 0; i < n / 2; i++){
			cout << a[i].fi << " " << a[i].se << endl;
		}
		cout << endl;
	}
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		
		solve();
	} 
	
	

	return 0;
}
