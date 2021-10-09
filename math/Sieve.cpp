#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int sieve_size;
bitset<1000005>bs;
vector<int> primes;

void sieve(int upperbound){
	
	sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(int i = 2; i <= sieve_size; i++){
		if(bs[i]){
			primes.push_back(i);
			for(int j = i * i; j <= sieve_size; j += i)
				bs[j] = 0;
		}
	}
}

int main(){
	
	cin >> sieve_size;
	sieve(sieve_size);
	
	int n;
	cin >> n;
	
	for(int i = 0; i < n; i++)
		cout << primes[i] << " ";	
	
	
	
	
	
	return 0;
}
