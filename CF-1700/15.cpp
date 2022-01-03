/* Journey */

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
		int n;
		cin >> n;
		string s;
		cin >> s;
		
		vector<int> l(n + 1), r(n + 1);
		for(int i = 0; i <= n; i++){
			l[i] = r[i] = i;
		}
		
		for(int i = 1; i <= n; i++){
			if(i == 1 && s[i - 1] == 'L'){
				l[i] = i - 1; 
				continue;
			}
			else if(s[i - 1] == 'L' && s[i - 2] == 'R'){
				l[i] = l[i - 2];
			}
			else if(s[i - 1] == 'L'){
				l[i] = i - 1;
			}
		}
		for(int i = n - 1; i >= 0; i--){
			if(i == n - 1 && s[i + 1] == 'R'){
				r[i] = i + 1;
				continue;
			}
			else if(s[i] == 'R' && s[i + 1] == 'L'){
				r[i] = r[i + 2];
			}
			else if(s[i] == 'R'){
				r[i] = i + 1;
			}
		}
//		for(int i = 0; i <= n; i++) cout << l[i] << " ";
//		cout << endl;
//		for(int i = 0; i <= n; i++) cout << r[i] << " ";
		for(int i = 0; i <= n; i++){
			cout << r[i] - l[i] + 1 << " ";
		}
		cout << endl;
	}

	return 0;
}
