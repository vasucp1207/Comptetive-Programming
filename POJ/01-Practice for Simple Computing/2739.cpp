#include <iostream>
#include <vector>

using namespace std;

vector<int>primes;
bool flag[10000];

void sieve(){
	
	for(int i = 2; i < 10000; i++) flag[i] = 1;
	
	for(int i = 2; i < 10000; i++){
		if(flag[i]){
			primes.push_back(i);
			for(int j = i * i; j < 10000; j += i)
				flag[j] = 0;
		}
	}
}

int main(){
	
	sieve();

	int n;
	while(cin >> n){
		
		if(n == 0) break;
		
		int cnt = 0;
		for(int i = 0; i < primes.size(); i++){
			int sum = 0;
			for(int j = i; j < primes.size(); j++){
				sum += primes[j];
				if(sum == n){
					cnt++;
					break;
				}
				if(sum > n) break;
			}
		}
		
		cout << cnt << endl;
	}


return 0;
}
