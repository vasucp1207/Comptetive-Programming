// Kill the Monster

#include<bits/stdc++.h>

#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

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

int main(){
	
	int t;
	cin >> t;
	while(t--){
		
		ll a, b, c, d, e, f, g;
		cin >> a >> b >> c >> d >> e >> f >> g;
	
		ll x = (c % b == 0)? c / b: c / b + 1;
		ll y = (a % d == 0)? a / d: a / d + 1;
		if(x <= y){
			cout << "YES" << endl;
			continue;
		}
		
		bool flag = false;
		ll u, v;
		ll a1, b1;
		for(ll i = 0; i <= e; i++){
			a1 = a + i * g;  // new health
			b1 = b + (e - i) * f; // new attack
			
			u = (a1 % d == 0)? a1 / d: a1 / d + 1;
			v = (c % b1 == 0)? c / b1: c / b1 + 1;
			if(u >= v){
				flag = true;
				break;
			}
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	} 
	
	

	return 0;
}
