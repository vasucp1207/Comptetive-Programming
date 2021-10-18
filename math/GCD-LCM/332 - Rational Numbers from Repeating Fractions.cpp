#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long

ll gcd(ll a, ll b){ return b == 0? a: gcd(b, a % b); }
ll lcm(ll a, ll b){ return a * (b / gcd(a, b)); }

int main(){
	
	ll i = 1;
	ll j;
	string d;
	while(cin >> j >> d){
		
		if(j == -1)break;
		
		ll k = d.size() - 2 - j;
		
		stringstream con(d);
		double n = 0;
		con >> n;
		
		ll neno = (ll)(n * (double)pow(10ll, (k + j)) - (double)n * pow(10ll, k));
		ll deno = pow(10ll, k + j) - pow(10ll, k);
		
		ll g = gcd(neno, deno);
		
		cout << "Case " << i++ << ": " << neno / g << "/" << deno / g << endl; 
	}
	
	
	
	
	
	
	
	return 0;
}
