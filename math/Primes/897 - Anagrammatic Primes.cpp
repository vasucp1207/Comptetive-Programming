#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(1005);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 1005; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(int i = 2; i < upperbound; i++){
		if(flag[i]){
			for(int j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

int main(){
	
	sievee(1005);
	
	int isAnag[22] = {2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, 97, 
					  113, 131, 199, 311, 337, 733, 919, 991};
					  
	int n;
	while(cin >> n){
		
		if(n == 0)break;
		
		int m = n;
		int u = 1;
		bool flag = true;
		
		while(m){
			m /= 10;
			u *= 10; 
		}
		
		for(int i = 0; i < 22; i++){
			if(isAnag[i] > n && isAnag[i] < u){
				cout << isAnag[i] << endl;
				flag = false;
				break;
			}
		}
		if(flag)cout << 0 << endl;
	}
	
	
	
	
	
	
	
	return 0;
}
