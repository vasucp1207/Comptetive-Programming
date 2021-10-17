#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long

vector<bool> flag(10000000);
vector<ll> primes;

void sievee(ll upperbound){
	
	for(ll i = 0; i < 10000000; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(ll i = 2; i < sqrt(upperbound); i++){
		if(flag[i]){
			for(ll j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

bool isPrime(ll n){
	if(n < 10000000)return flag[n];
	
	for(ll i = 0; i < primes.size(); i++){
		if(n % primes[i] == 0)return false;
	}
	
	return true;
}

void solve(){
	
	ll l, u;
	cin >> l >> u;
	
	vector<ll> list;
	for(ll i = l; i <= u; i++)
		if(flag[i])
			list.push_back(i);
			
	vector<ll> diff(10000, 0);
	
	for(ll i = 1; i < list.size(); i++){
		diff[list[i] - list[i - 1]]++;
	}
	
	ll ans = 0;
	ll maxn = 0;
	for(ll i = 0; i < 10000; i++){
		if(diff[i] > ans){
			ans = diff[i];
			maxn = i;
		}
	}
	
	ll cnt = 0;
	for(ll i = 0; i < 10000; i++){
		if(diff[i] == ans)cnt++;
	}
	
	if(cnt > 1)
		cout << "No jumping champion" << endl;
		
	else{
		if(ans == 0)
			cout << "No jumping champion" << endl;
		else
			cout << "The jumping champion is " << maxn << endl;	
	}
}

int main(){
	
	sievee(10000000);
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
	
		
	
	
	
	
	
	return 0;
}
