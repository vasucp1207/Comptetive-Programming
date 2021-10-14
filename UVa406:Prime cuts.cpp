/*First use the sieve of Eratosthenes to generate all primes under 1000. Use binary search to find the first prime
greater than or equal to N, and decrement the index until the prime is less than or equal to N. From here,
we look at the size of the prime list to determine the number of elements we should print out. After calculating
these, calculate the start and end indices. If the size of the center list is equal to or exceeds the size of the
total list, print all primes from 1 to N.*/

#include <bits/stdc++.h>

using namespace std;

#define long long ll 
#define push_back pb
#define pop_back po
const int maxn = 200005;

int sieve_size;
bitset<1000005>bs;
vector<int> primes;
int n, c;

void sieve(int upperbound){
	
	sieve_size = upperbound + 1;
	
	bs.set();
	bs[0] = bs[1] = 0;
	
	for(int i = 2; i <= sieve_size; i++){
		if(bs[i]){
			primes.pb(i);
			for(int j = i * i; j <= sieve_size; j += i)
				bs[j] = 0;
		}
	}
}

int main(){
	
	sieve(1000);
	
	while(cin >> n >> c){
		
		int sz = lower_bound(primes.begin(), primes.end(), n) - primes.begin();
		while(sz >= primes.size() || primes[sz] > n)sz--;
		
		sz = sz + 1; // size of the complete list
		
		int print_sz = sz % 2;
		if(print_sz == 0)print_sz = 2 * c;
		else print_sz = 2 * (c - 1);
		
		int st ,en;
		if((sz - print_sz) < 0)st = 0, en = sz;
		else st = (sz - print_sz) / 2, en = st - print_sz;	
		
		cout << n << " " << c <<":" << " ";
		for(int i = st; i < en; i++)cout << primes[i] << " ";
		cout << endl;
	}

	
	
	
	
	return 0;
}
