#include <bits/stdc++.h>

using namespace std;

#define ll long long 

int power(int a, int n, int m){
	
	int res = 1;
	while(n){
		
		if(n % 2) res = (res * a) % m;
		
		n /= 2;
		a = (a * a) % m;
	}
	
	return res;
}

int main(){
	
	int t, a, m;
	cin >> t;
	
	while(t--){
		
		cin >> a >> m;
		
		cout << "a^-1 = " << power(a, m - 2, m) << endl;
	}
	


return 0;
}
