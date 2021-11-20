#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int n;
	
	while(cin >> n){
		
		if(n == 0) break;
		
		int a[n + 1];
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		int mx = a[1];
		for(int i = 2; i <= n; i++) mx = max(mx, a[i]);
		
		int cnt[mx + 1] = {0};
		int out[n + 1];
		
		for(int i = 1; i <= n; i++)
			cnt[a[i]]++;
			
		for(int i = 1; i <= mx; i++)
			cnt[i] += cnt[i - 1];
			
		for(int i = n; i >= 1; i--){
			out[cnt[a[i]]] = a[i];
			cnt[a[i]]--;
		}
		
		for(int i = 1; i <= n; i++) a[i] = out[i];
		
		cout << a[1];
		for(int i = 2; i <= n; i++) cout << " " << a[i];
		cout << endl;
	}
		
	

return 0;
}
