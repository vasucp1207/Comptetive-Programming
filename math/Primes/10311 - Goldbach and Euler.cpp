#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(100000000);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 100000000; i++)flag[i] = true;
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
	if(n < 100000000)return flag[n];
	
	for(int i = 0; i < primes.size(); i++){
		if(n % primes[i] == 0)return false;
	}
	
	return true;
}

int main(){
	
	sievee(100000000);
	
	int n;
	
	while(cin >> n){
		
		if(n % 2 == 1){
			if(flag[n - 2]){   
				// if n is odd then it is 2P sum, only if (n - 2) is prime because odd + odd != odd.
				cout << n << " is the sum of 2 and " << n - 2 << "." << endl;
			}
			else{
			cout << n << " is not the sum of two primes!" << endl;
			}
			continue;
		}
		
		bool flag1 = false;
		
		int a, b;
		
		// do not use-->for(int i = 0; i <= n / 2 + 1; i++) it gives TLE
		for(int i = n / 2 - 1; i >= 0; i--){
			if(isPrime(i) && isPrime(n - i)){
				cout << n << " is the sum of " << i << " and " << n - i << "." << endl;
                flag1 = true;
                break;
			}
		}
		
		if(flag1 == false){
			cout << n << " is not the sum of two primes!" << endl;
		}
	}
	
	
	
	return 0;
}
