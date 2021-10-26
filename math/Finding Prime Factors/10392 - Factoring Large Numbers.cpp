#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x, ll y){return x * (y / gcd(x, y));}

vector<ll> primeFactors(ll n){
	
	vector<ll> fac;
	
	for(ll i = 2; i * i <= n; i++){
		while(n % i == 0){
			n /= i;
			fac.push_back(i);
		}
	}
	if(n != 1)fac.push_back(n);
	return fac;
}

int main(){

	sieve(10000000ll);
	ll n;
	
	while(cin >> n){
		
		if(n < 0)break;
		
		vector<ll> fac = primeFactors(n);
		
		if(n > 0){
			for(ll i = 0; i < fac.size(); i++)
				cout << fac[i] << endl;
		}
		else{
			for(ll i = 0; i < fac.size(); i++)
				cout << fac[i] << endl;
		}
		cout << endl;
	}


return 0;
}
