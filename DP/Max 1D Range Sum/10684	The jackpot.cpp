#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	while(true){
		
		int n;
		cin >> n;
		if(n == 0) break;
		
		int sum = 0;
		int mx = -1;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			sum += x;
			
			if(sum < 0){
				sum = 0;
			}
			mx = max(sum, mx);
		}
		if(mx == 0) cout << "Losing streak." << endl;
		else cout << "The maximum winning streak is " << mx << "." << endl;
	}
		
	

return 0;
}
