#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second
// std::vector<int>::iterator it;

// why declaring arrays golbally don't cause TLE....
const int mx = 10000007;
ll d[mx] = {0};
int ans[mx] = {0};

int main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	int t = 1;
	cin >> t;
	
	for(int i = 1; i < mx; i++){
		for(int j = i; j < mx; j += i){
			d[j] += i;
		}
		if(d[i] <= mx && !ans[d[i]]){
			ans[d[i]] = i;
		}
	}
	
	while(t--){
		ll c;
		cin >> c;
		if(!ans[c]) cout << -1 << endl;
		else cout << ans[c] << endl; 
	}

	return 0;
}
