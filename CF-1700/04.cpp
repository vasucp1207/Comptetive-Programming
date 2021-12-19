/* 1618E - Singers' Tour */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		ll n;
		cin >> n;
		vector<ll> b(n);
		ll sum = 0;
		for(int i = 0; i < n; i++) cin >> b[i], sum += b[i];
		
		ll d = 1ll * n * (n + 1) / 2;
		if(sum % d != 0){
			cout << "NO" << endl;
			continue;
		}
		
		sum /= d;    // a1 + a2 + a3 + ..... + an
		vector<ll> a(n);
		bool ok = false;
		for(int i = 0; i < n; i++){
		    ll temp;
			if(i == 0) temp = b[i] - b[n - 1];
			else temp = b[i] - b[i - 1];
			ll nele = sum - temp;  // --> (n * an)
			if(nele == 0 || nele < 0 || nele % n){
				ok = true;
				break;
			}
			nele /= n; // --> an
			a[i] = nele;
		}
		if(ok){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}	

	return 0;
}
