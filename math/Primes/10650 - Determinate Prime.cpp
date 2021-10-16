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

vector<int> v[32000];
int fun(int a, int b){
	
}

void seq(int x, int y){
	
	for(int i = x; i <= y; i++){
		cout << primes[i] << " ";
	}
	cout << endl;
}

int main(){
	
	sievee(10000000);
	
	ll x, y;
	while(cin >> x >> y){
		
		if(x == 0 && y == 0)
			break;
			
		if(x > y)swap(x, y);
			
		int i = 0;
		
		while(primes[i] < x) i++;   // first prime greater than x
		
		while(primes[i + 2] <= y){
			
			if(primes[i + 2] - primes[i + 1] == primes[i + 1] - primes[i]){
			
				int st = i;
				int en = i + 2;
				int diff = primes[i + 1] - primes[i];
				
				while(i + 3 < primes.size() && primes[i + 3] - primes[i + 2] == diff){
					en++;
					i++;
				}
					
				if(primes[en] <= y){
					if(st = 0 || primes[st] - primes[st - 1] != diff){
						seq(st, en);
					}
				} 
				else{
					break;
				}
			}
			i++;
		}
	}
	
	
	
	
	
	
	
	return 0;
}
