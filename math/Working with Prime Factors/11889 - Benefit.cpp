/* my sol runtimerror */

#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

vector<int> primes;
bool flag[10000000];

void sieve(int n){
	
	for(int i = 2; i < n - 1; i++) flag[i] = 1;
	
	for(int i = 2; i * i < n; i++){
		if(flag[i]){
			primes.push_back(i);
			for(int j = i * i; j < n - 1; j += i)
				flag[j] = 0;
		}
	}
}

int main(){
	
	sieve(10000000);
	
	int t;
	cin >> t;
	
	while(t--){
		
		ll a, c;
		cin >> a >> c;
		
		if(c % a != 0){
			cout << "NO SOLUTION" << endl;
			continue;
		}
		
		ll ans = 1;
		for(int i = 0; i < 3000 && primes[i] <= a && primes[i] <= c; i++){
			
			int cnta = 0;
			int cntc = 0;
			
			while(a % primes[i] == 0){
				a = a / primes[i];
				cnta++;
			}
			while(c % primes[i] == 0){
				c = c / primes[i];
				cntc++;
			}
			if(cntc > cnta){
				for(int j = 1; j <= cntc; j++){
					ans = ans * primes[i];
				}
			}
		}
		if(c > 1 && a == 1) ans = ans * c;
		cout << ans << endl;
	}
		
		

return 0;
}
