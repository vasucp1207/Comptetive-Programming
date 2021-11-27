#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		vector<string> a;
		string s;
		cin >> s;
		int n = s.size();
		a.push_back(s);
		
		for(int i = 0; i < n - 1; i++){
			cin >> s;
			a.push_back(s);
		}
		
		int arr[n][n];
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(a[i][j] == '1') arr[i][j] = 1;
				else a[i][j] = 0;
			}
		}
		
		int mx = 0;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				for(int k = i; k < n; k++)
					for(int l = j; l < n; l++){
						int cnt = 0;
						bool flag = true;
						for(int m = i; m <= k; m++)
							for(int n = j; n <= l; n++){
								if(arr[m][n] == 1) cnt++;
								else  flag = false;
							}
						if(flag)
							mx = max(mx, cnt);
					}
		
		cout << mx << endl;
		if(t) cout << endl;
	}
	
	
	
	

return 0;
}
