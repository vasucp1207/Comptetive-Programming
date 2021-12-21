/* Omkar and Determination */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

int main(){

	int t;
	t = 1;
	
	while(t--){
		
		ll n, m;
		cin >> n >> m;
		ll a[n + 1][m + 1] = {0};
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= m; j++){
				char c;
				cin >> c;
				if(c == 'X') a[i][j] = 1;
			}
		}
		
		ll p[m + 1] = {0};
		for(ll i = 2; i <= n; i++){
			for(ll j = 2; j <= m; j++){
				if(a[i - 1][j] && a[i][j - 1]) p[j] = 1;
			}
		}
		
		for(ll i = 2; i <=m; i++){
			p[i] += p[i - 1];
		}
		
		ll q;
		cin >> q;
		while(q--){
			ll l, r;
			cin >> l >> r;
			if(p[r] - p[l]) cout << "NO" << endl;
			else cout << "YES" << endl;
		}	
	}
		

	return 0;
}
