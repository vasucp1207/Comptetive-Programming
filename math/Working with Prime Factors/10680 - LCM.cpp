#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

bool flag[1000005];
vector<int> primes;

void sieve(int n = 1000005){
	
	for(int i = 2; i < n; i++) flag[i] = 1;
	
	for(int i = 2; i < n; i++){
		if(flag[i]){
			primes.push_back(i);
			
			for(int j = i * i; j < n; j += i){
				flag[j] = 0;
			}
		}
	}
}

int Exp(int n, int p){
	
	int exp = 0;
	
	while(n / p){
		
		++exp;
		n /= p;
	}
	return exp;
}

int main(){
	
	sieve();
	
	int n;
	while(n == 1){
		
		if(n == 0) break;
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		
		int i = 0;
		vector<pair<int, int> > fac;
		int p = primes[0];
		int exp = Exp(n, p);
		
		while(exp){
			fac.push_back({p, exp});
			p = primes[++i];
			exp = Exp(n, p);
		}
		
		if(n >= 5){
			fac[0].se -= fac[2].se;
			fac[2].se = 0;
		}
		
		int d = 1;
		for(int i = 0; i < fac.size(); i++){
			int exp = fac[i].se;
			int p = fac[i].fi;
			for(int j = 0; j < exp; j++){
				d = (d * p) % 10;
			}
		}
		cout << d << endl;
	}



return 0;
}
