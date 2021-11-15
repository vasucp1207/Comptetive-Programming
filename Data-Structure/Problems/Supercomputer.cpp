#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, k;
	cin >> n >> k;
	
	int m = (int) sqrt (n + .0) + 1;
	
	vector<int>arr(n, 0);
	vector<int>buck(m, 0);
	
	for(int i = 0; i < k; i++){
		
		char op;
		cin >> op;
		if(op == 'F'){
			int x;
			cin >> x;
			x--;
			
			if(arr[x] == 0){
				arr[x] = 1;
				buck[x / m]++;
			}
			else{
				arr[x] = 0;
				buck[x / m]--;
			}
		}
		else{
			int l, r;
			cin >> l >> r;
			l--, r--;
			
			int sum = 0;
			for(int j = l; j <= r;){
				
				if(j % m == 0 && j + m - 1 <= r){
					sum += buck[j / m];
					j += m;
				}
				else{
					sum += arr[j];
					j++;
				}
			}
			cout << sum << endl;
		}
	}
	

return 0;
}
