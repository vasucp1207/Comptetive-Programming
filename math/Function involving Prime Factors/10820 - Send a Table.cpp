#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

ll phi[50005];
ll dp[50005];

void init(int n){
	
	for(int i = 0; i < n; i++) phi[i] = i;
	
	for(int i = 2; i < n; i++){
		if(phi[i] == i){
			for(int j = i; j < n; j += i)
				phi[j] -= phi[j] / i;
		}
	}
}

void calc(int n){
	
	dp[1] = 1;
	for(int i = 2; i < n; i++) dp[i] = dp[i - 1] + 2 * phi[i];
}

int main(){
	
	init(50005);
	calc(50005);
	
	int n;
	while(cin >> n){
		
		cout << dp[n] << endl;
	}
		

return 0;
}
