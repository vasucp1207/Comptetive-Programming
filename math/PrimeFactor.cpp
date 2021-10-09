#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int sieve_size;
bitset<100005>bs;
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

vector<int> primeFactor(int n){
	
	vector<int> factors;
	
	int PF_idx = 0, PF = primes[PF_idx];
	
	while(PF * PF <= n){
		while(n % PF == 0){
			n /= PF;
			factors.push_back(PF);
		}
		PF = primes[++PF_idx];
	}
	
	if(n != 1)
		factors.push_back(n);
	
	return factors;
}

int main(){
	
	cin >> sieve_size;
	sieve(sieve_size);
	
	int n;
	cin >> n;
	
	vector<int> res = primeFactor(n);
	
	for(int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
		
	
	
	
	
	
	
	return 0;
}
