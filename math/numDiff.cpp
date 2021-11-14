#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int numDiff(ll n){
	
	ll ans = 1;
	ll cnt;
	for(ll i = 2; i * i <= n; i++){
		
		if(n % i == 0){
			cnt = 0;
			while(n % i == 0){
				cnt++;
				n /= i;
			}
		}
		ans *= (cnt + 1);
	}
	if(n != 1) ans *= 2;       // lase factor + 1
	
	return ans;
}

int main(){
	
	ll t;
	cin >> t;
	
	while(t--){
		
		ll n;
		cin >> n;
		
		cout << numDiff(n) << endl;
	}
		

return 0;
}
