#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int main(){
	
	int n;
	while(cin >> n){
		
		if(n == 0) break;
		if(n == 1) {
			cout << 0 << endl;
			continue;
		}
		ll res = n;
		for(int i = 2; i * i <= n; i++){
			
			if(n % i == 0){
				res *= (i - 1);
				res /= i;
				
				while(n % i == 0){
					n /= i;
				}
			}
		}
		if(n != 1) res *= (n - 1), res /= n;
		
		cout << res << endl;
	}
		

return 0;
}
