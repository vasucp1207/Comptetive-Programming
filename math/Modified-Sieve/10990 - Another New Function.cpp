#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll phi[2000005];
const ll maxN = 2000005;
ll dep[2000005];

void initialise(){
	
	for(ll i = 1; i < maxN; i++)
		phi[i] = i;
		
	for(ll i = 2; i < maxN; i++){
		if(phi[i] == i){
			for(ll j = i; j < maxN; j += i){
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
	
	dep[0] = 0, dep[1] = 1, dep[2] = 1;
	for(ll i = 3; i < 2000005; i++){
		dep[i] = dep[phi[i]] + 1;
	}
	
	for(int i = 1; i < 2000005; i++){
		dep[i] += dep[i - 1];   
	}	
}

int main(){
	
	initialise();
	
	ll t;
	cin >> t;
	
	while(t--){
		ll n, m;
		cin >> n >> m;
		
		cout << dep[m] - dep[n - 1] << endl;

	}	
	
	
	return 0;
}
