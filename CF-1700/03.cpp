// 1598D - Training Session

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

void solve(){
	
	int n;
	cin >> n;
	
	vector<int> a(n + 1), b(n + 1), cnta(n + 1, 0), cntb(n + 1, 0);
	for(int i = 1; i <= n; i++){
		cin >> a[i] >> b[i];
		cnta[a[i]]++, cntb[b[i]]++;
	}
	
	ll cnt = 0;
	for(int i = 1; i <= n; i++){
		cnt += (1ll * (cnta[a[i]] -1)  * (cntb[b[i]] - 1));
	}
	
	ll total = 1ll * n * (n - 1) * (n - 2) / 6;
	cout << total - cnt << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		solve();
	}
	
	
	

	return 0;
}
