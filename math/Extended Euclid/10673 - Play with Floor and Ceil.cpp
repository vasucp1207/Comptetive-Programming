#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int t, x, k;
	cin >> t;
	while(t--){
		
		cin >> x >> k;
		if(x % k){
			cout << k - x % k << " " << x % k << endl;
		}
		else{
			cout << 0 << " " << k << endl;
		}
	}
	

return 0;
}
