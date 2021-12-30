/* Two Hundred Twenty One (easy version) */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second
// std::vector<int>::iterator it;

int main(){

	int t = 1;
	cin >> t;
	
	while(t--){
		
		int n, q;
		cin >> n >> q;
		string s;
		cin >> s;
		
		vector<int> a(n + 1);
		for(int i = 1; i <= n; i++){
			if(s[i - 1] == '-') a[i] = -1;
			else a[i] = 1;
		}
		
		vector<int> p(n + 1, 0);
		for(int i = 1; i <= n; i++){
			p[i] = p[i - 1];
			if(i % 2) p[i] += a[i];
			else p[i] += -a[i];
		}
		
		while(q--){
			int l, r;
			cin >> l >> r;
			int sum = p[r] - p[l - 1];
			
			if(sum == 0) cout << 0 << endl;
			else if(sum % 2) cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
		

	return 0;
}
