#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

ll gcd(ll a, ll b){
	return b == 0? a:gcd(b, a % b);
}

bool flag[10000];
vector<ll> primes;
void sieve(ll n){
	
	for(ll i = 2; i * i <= n; i++){
		if(!flag[i]){
			primes.push_back(i);
			for(ll j = i * i; j < n; j += i){
				flag[j] = 1;
			}
		}
	}
}

void solve(ll n){	
		
	ll ans = 0;
	bool f = 0;
	if(n < 0){
		n = -n;
		f = 1;	
	} 
	
	//sieve();
	
	for(ll i = 0; i < primes.size() && n > 1; i++){
		
		ll cnt = 0;
		if(n % primes[i] == 0){
			
			while(n % primes[i] == 0){
				cnt++;
				n /= primes[i];
			}
			ans = gcd(ans, cnt);
		}
	}
	
	if(n > 1) ans = 1;
	if(f){
		while(ans % 2 == 0) ans /= 2;
	}
	
	cout << ans << endl;
}

int main(){
	
	sieve(10000);
	
	ll n;
	
	while(cin >> n){
		
		if(n == 0) break;
		
		solve(n);
	}


return 0;
}
