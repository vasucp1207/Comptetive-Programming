#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int numDiff[1000005];

void numDiff1(){
	
	for(ll i = 2; i < 1000005; i++){
		if(numDiff[i] == 0){
			for(ll j = i; j < 1000005; j += i)
				numDiff[j]++;
		}
	}
}

int main(){
	
	numDiff1();
	ll n;
	
	while(cin >> n){
		
		if(n == 0) break;
		
		cout << n << " : "<< numDiff[n] << endl;
	}
		

return 0;
}
