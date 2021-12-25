/* MEX and Increments */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

int main(){

	ll t;
	cin >> t;
	
	while(t--){
		ll n;
		cin >> n;
		vector<ll> a(n), f(n + 1, 0), ans(n + 1, -1);
		for(ll i = 0; i < n; i++) cin >> a[i], f[a[i]]++;
		
		ans[0] = f[0];
		stack<ll> s;
		ll prev = 0;
		
		for(ll i = 1; i <= n; i++){
			if(f[i - 1] == 0){
				if(s.empty()){
					break;
				}
				int j = s.top();
				s.pop();
				f[j]--;
				prev += i - 1 - j;
			}
			ans[i] = prev + f[i];
			while(f[i - 1] > 1){
				s.push(i - 1);
				f[i - 1]--;
			}
		}
		
		for(ll i = 0; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
	}
		

	return 0;
}
