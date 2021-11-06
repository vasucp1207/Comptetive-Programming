/* My method is wrong */


#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		int cases = 0; string s;
		cin >> s;
		
		int m = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '!') m++;
		}
		
		int c[3000] = {0};
		
		string str = s.substr(0, m);
		int n = stoi(str);
		
		for(int i = n; i >= 0; i -= m){
			int num = n;
			for(int j = 2; j <= num; j++){
				
				while(num % j == 0){
					num /= j;
					c[j]++;
				}
			}
		}
		
		ll res = 1;
		double sum = 0;
		for(int i = 0; i <= n; i++){
			res *= c[i] + 1;
			sum += log10(c[i] + 1);
		}
		cout << "Case " << ++cases << ": ";
		if(ceil(sum) > 18)
			cout << "Infinity" << endl;
		else cout << res << endl;
	}


return 0;
}
