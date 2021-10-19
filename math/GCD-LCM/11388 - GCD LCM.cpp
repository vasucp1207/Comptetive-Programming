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

	int t;
	cin >> t;
	
	while(t--){
		
		int g, l;
		cin >> g >> l;
		
		if(l % g == 0)cout << g << " " << l << endl;
		else cout << -1 << endl;
	}


return 0;
}
