#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		
		vector<int> res;
		
		for(int i = 9; i >= 2; i--){
			while(n % i == 0){
				res.push_back(i);
				n /= i;
			}
		}
		
		if(n > 9) cout << -1 << endl;
		else{
			sort(res.begin(), res.end());
			for(int i = 0; i < res.size(); i++){
				cout << res[i];
			}
			cout << endl;
		}
	}


return 0;
}
