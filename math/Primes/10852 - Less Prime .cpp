#include <bits/stdc++.h>

using namespace std;

#define ll long long 

vector<bool> flag(10000000);
vector<ll> primes;

void sievee(ll upperbound){
	
	for(ll i = 0; i < 10000000; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(ll i = 2; i < sqrt(upperbound); i++){
		if(flag[i]){
			for(ll j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

bool isPrime(ll n){
	if(n < 10000000)return flag[n];
	
	for(ll i = 0; i < primes.size(); i++){
		if(n % primes[i] == 0)return false;
	}
	
	return true;
}

int main(){
	
	sievee(10000000);
	
	int t;
	cin >> t;
	
	while(t--){
		
		ll n;
		cin >> n;
		
		for(ll i = n / 2 + 1; i <= n; i++){
			if(isPrime(i)){
				cout << i << endl;
				break;
			}
		}
	}
	
	
	
	
	
	
	return 0;
}
