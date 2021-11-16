#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	int len = (int)sqrt(n + .0) + 1;  // sqrt(n) = size of each block, and the total blocks
	
	vector<int> bucket(len);
	for(int i = 0; i < n; i++){
		bucket[i / len] += a[i];
	}
	
	int q;
	cin >> q;
	while(q--){
		
		int l, r;
		cin >> l >> r;
		int sum = 0;
		
		for(int i = l; i <= r; ){
			if(i % len == 0 && i + len - 1 <= r){
				// if the whole block starting from i belongs to [l, r]
				sum += bucket[i / len];
				i += len;  // jump of sqrt(n)
			}
			else{
				sum += a[i];
				i++;
			}
		}
		cout << sum << endl;
	}
	

return 0;
}
