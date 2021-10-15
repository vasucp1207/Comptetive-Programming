/*solving this problem i have learnt a new rule which is proved by Euclid, a well-known mathematician.
 the rule is that  2^(p-1)(2^p - 1) is a perfect number whenever 2^p - 1 is prime. where p is an integer.*/

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
	
	ll n;
	while(true){
		
		cin >> n;
		if(n == 0)break;
		
		if(isPrime(n)){
			
			ll p = pow(2, n) - 1;
			if(isPrime(p)){
				p = pow(2, n - 1) * p;
				cout << "Perfect: " << p << "!" << endl;
			}
			else{
				cout << "Given number is prime. But, NO perfect number is available." << endl;
			}
		}
		else{
			cout << "Given number is NOT prime! NO perfect number is available." << endl;
		}
	}
	
	
	
	
	
	return 0;
}
