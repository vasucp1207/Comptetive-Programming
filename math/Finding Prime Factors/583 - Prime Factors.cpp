#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x, ll y){return x * (y / gcd(x, y));}

bool flag[10000000];
vector<int> primes;

void sieve(int upper){
	
	for(int i = 0; i < upper; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(int i = 2; i * i <= upper; i++){
		if(flag[i]){
			primes.push_back(i);
			for(int j = i * i; j < upper; j += i){
				flag[j] = false;
			}
		}
	}
}

vector<int> primeFactors(int n){
	
	if(n < 0)n = -1 * n;
	vector<int> fac;
	
	int idx = 0;
	int pf = primes[idx];
	
	while(pf * pf <= n){
		while(n % pf == 0){
			
			n /= pf;
			fac.push_back(pf);
		}
		pf = primes[++idx];
	}
	
	if(n != 1)fac.push_back(n);
	
	return fac;
}

int main(){

	sieve(10000000);
	int n;
	
	while(cin >> n){
		
		if(n == 0)break;
		
		vector<int> fac = primeFactors(n);
		
		if(n > 0){
			cout << n << " = ";
			for(int i = 0; i < fac.size() - 1; i++)
				cout << fac[i] << " x ";
		}
		else{
			cout << "-" << -1 * n << " = " << "-1 x ";
			for(int i = 0; i < fac.size() - 1; i++)
				cout << fac[i] << " x ";
		}
		cout << fac[fac.size() - 1];
		cout << endl;
	}


return 0;
}
