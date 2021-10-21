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

	int n;
	
	while(cin >> n){
		
		if(n == 0)break;
		
		int g = 0;
		for(int i = 1; i < n; i++)
			for(int j = i + 1; j <= n; j++)
				g += gcd(i, j);
				
		cout << g << endl;
	}


return 0;
}
