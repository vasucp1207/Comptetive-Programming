#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long

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
	
	int n, c;
	
	while(cin >> n >> c){
		
		vector<int> list;
		
		printf("%d %d:", n, c);
		
		list.push_back(1);
		for(int i = 2; i <= n; i++){
			if(flag[i]){
				list.push_back(i);
			}
		}
		
		int len = list.size();
		if(len % 2){
			int C = 2 * c - 1;
			if(C >= len){
				for(int i = 0; i < len; i++)
					printf(" %d", list[i]);
			}
			else{
				for(int i = (len - C) / 2; i < (len + C) / 2; i++)
					printf(" %d", list[i]);
			}
		}
		
		else{
			int C = 2 * c;
			if(C >= len){
				for(int i = 0; i < len; i++)
					printf(" %d", list[i]);
			}
			else{
				for(int i = (len - C) / 2;i< (len + C) / 2; i++)
					printf(" %d", list[i]);
			}
		}
		
		printf("\n\n");
	}
	
	
	
	
	
	return 0;
}
