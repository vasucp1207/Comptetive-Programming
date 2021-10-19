#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());} 

ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
ll lcm(ll x, ll y){return x * (y / gcd(x, y));}

int main(){

	ll n;
	
	while(true){
		
		cin >> n;
		if(n == 0)break;
		
		vector<ll> div;
		
		for(ll i = 1; i * i <= n; i++){
			if(n % i == 0){
				div.push_back(i);   // for duplicacy of n as a divisor (1, n) & (n, n)
				if(n / i != i)div.push_back(n / i);
			}
		}
		
		int cnt = 0;
		for(ll i = 0; i < div.size(); i++)
			for(ll j = i; j < div.size(); j++)
				if(lcm(div[i], div[j]) == n)cnt++;
				
		cout << n << " " << cnt << endl;
	}


return 0;
}
