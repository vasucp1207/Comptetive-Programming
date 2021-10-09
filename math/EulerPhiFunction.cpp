#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int phi[1000005];
const int maxN = 1000000;

void initialise(){
	
	for(int i = 1; i <= maxN; i++)
		phi[i] = i;
		
	for(int i = 2; i <= maxN; i++){
		if(phi[i] == i){
			for(int j = i; j <= maxN; j += i){
				phi[j] /= i;
				phi[j] *= (i - 1);
			}
		}
	}
}

int main(){
	
	initialise();
	
	int t;
	cin >> t;
	
	while(t--){
		int x;
		cin >> x;
		
		cout << phi[x]<<endl;
	}	
	
	
	
	
	
	
	return 0;
}
