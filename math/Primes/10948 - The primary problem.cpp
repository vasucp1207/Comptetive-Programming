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

bool ok;
void findPrimes(ll n){
	
	for(ll i = 2; i < n / 2 + 1; i++){
		
		if(isPrime(i) && isPrime(n - i)){
			cout << i << "+" << n - i << endl;
			ok = false;
			break;
		}
	}
	return ;
}

int main(){
	
	sievee(10000000);
	
	while(true){
		
		ll n;
		cin >> n;
		
		if(n == 0)break;
		
		ok = true;
		
		cout << n << ":" <<endl;
		
		findPrimes(n);
		if(ok)
			cout << "NO WAY!" << endl;
	}
	
	
	
	
	
	
	return 0;
}
