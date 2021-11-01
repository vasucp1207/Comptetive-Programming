#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

void solve(int n){
	
	int primes[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
	vector<int> fac(100, 0);
	
	int orignal = n;
	
	while(n != 1){
		
		int num = n;
		int i = 0;
		while(num != 1){
			
			while(num % primes[i] == 0){
					
				fac[primes[i]]++;
				num /= primes[i];
			}
			i++;
		}
		n--;
	}
	
	int flag = 0;
	cout << setw(3) << orignal << "! =";
	
	int i;
	for(i = 0; i < fac.size(); i++) 
		if(fac[i] != 0){
			
			flag++;
			if(flag > 15){
				cout << endl;
				break;
			}
			cout << setw(3) << fac[i];
		}
		
	if(flag > 15){
//		cout << "yes";   
		cout << setw(6) << " ";
		for(int j = i; j < fac.size(); j++){
			if(fac[j] != 0)
				cout << setw(3) << 1;
		}
	} 
			
	cout << endl;
}

int main(){
	
	int n;
	
	while(cin >> n){
		
		if(n == 0) break;
		
		solve(n);
	}


return 0;
}
