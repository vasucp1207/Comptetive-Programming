#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);} 

ll cnt = 1;
void solve(ll n){
	
	ll sum = 0;
	ll orig = n;
	ll flag = 0;
	
	for(int i = 2; i <= sqrt(orig) + 2; i++){
		if(n % i == 0){
			
			flag++;
			ll pr = 1;
			while(n % i == 0){
				n /= i;
				pr *= i;
			}
			sum += pr;
		}
	}
	if(n == orig) sum = n + 1;    // if n is prime
	else if(n != 1 || flag == 1) sum += n;  // 16 = 2 * 2 * 2 * 2
	
	cout << "Case " << cnt << ": " << sum << endl;
	cnt++;
}

int main(){
	
//	sieve(1000000);

	ll n;
	
	while(cin >> n){
		
		if(n == 0) break;
		
		solve(n);
	}


return 0;
}
