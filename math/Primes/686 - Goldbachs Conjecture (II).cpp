#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(1000000);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 1000000; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(int i = 2; i < sqrt(upperbound); i++){
		if(flag[i]){
			for(int j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

bool isPrime(int n){
	if(flag[n])return true;
	else return false;
}

int findPairs(int n){
	
	int c = 0;
	for(int i = 2; i < n/2 + 1; i++){
		if(isPrime(i) && isPrime(n - i)){
			c++;
		}
	}
	return c;
}

int main(){
	
	sievee(1000000);
	
	int n;
	
	while(true){
		
		cin >> n;
		if(n == 0)break;
		
		int cnt = findPairs(n);
		cout << cnt << endl;
	}
	
	
	
	return 0;
}
