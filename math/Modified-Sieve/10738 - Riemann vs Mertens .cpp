/* 2 to 1000000, this time update the squareFree flags,
instead of deleting multiples of 2, mark squareFree of multiples of 4 (2*2) as false
and then go on to 3, mark squareFree of multiples of 9 (3*3) as false
and then go on to 5, mark squareFree of multiples of 25 (5*5) as false
until 1000 (1000*1000 = 1000000).
At the end, for each number i, I will know whether this number is squareFree or not. */

#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

bool sqFree[1000005];
ll numDiv[1000005];
ll mu[1000005];
ll M[1000005];

void sieve(){
	
	for(ll i = 2; i < 1000005; i++){
		if(numDiv[i] == 0)
			for(ll j = i; j < 1000005; j += i){
				numDiv[j]++;
			}
	}
	
	for(ll i = 2; i < 1000005; i++){
		if(!sqFree[i])
			for(ll j = i; j < 1000005; j += i)
				if(i * j < 1000005)
					sqFree[i * j] = 1;
	}
	
	mu[1] = 1;
	M[1] = 1;
	for(ll i = 2; i < 1000005; i++){
		if(sqFree[i]) mu[i] = 0;
		else if(numDiv[i] % 2) mu[i] = -1;
		else mu[i] = 1;
	}
	
	for(ll i = 2; i < 1000005; i++)
		M[i] = M[i - 1] + mu[i];
}

int main(){
	
	ll n;
	sieve();
	
	while(cin >> n){
		
		if(n == 0) break;
		
		cout << setw(8) << n << setw(8) << mu[n] << setw(8) << M[n] << endl;
	}
		

return 0;
}
