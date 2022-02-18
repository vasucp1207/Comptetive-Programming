// Fun with Even Subarrays

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
	
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	reverse(a.begin() + 1, a.end());
	int ans = 0;
	int x = 1;
	while(x < n){
		
		if(a[x + 1] != a[1]){
			ans++;
			x *= 2;
			continue;
		}
		x++;
	}
	cout << ans << endl;
}

int main(){
	
	int t;
	cin >> t;
	while(t--){
		
		solve();
	} 
	
	

	return 0;
}
