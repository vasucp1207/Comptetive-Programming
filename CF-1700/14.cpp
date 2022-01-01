/* Square-free division (easy version) */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second
// std::vector<int>::iterator it;

int mx = 10000005;
vector<int> primes;
vector<int> flag(mx, 0);

void sieve(){
	
	for(int i = 2; i < mx; i++){
		if(flag[i] == 0){
			primes.push_back(i);
			flag[i] = i;
		}
		for(int j = 0; j < primes.size() && primes[j] * i < mx; j++){
			flag[primes[j] * i] = primes[j];
			if(i % primes[j] == 0) break;
		}
	}
}

int main(){

	sieve();
	int t = 1;
	cin >> t;
	
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> a(n, 1);
		
		for(int i = 0; i < n; i++){
			
			int x;
			cin >> x;
			int cnt;
			while(x > 1){
				cnt = 0;
				int curr = flag[x];
				while(x % curr == 0){
					cnt++;
					x /= curr;
				}
				if(cnt % 2) a[i] *= curr;
			}
		}
		
		// don't use vector because search in vector is of O(n), while in set
		// it is of O(logn) avoid TLE....
		set<int> ans;
		int res = 1;
		
		for(int i = 0; i < n; i++){
			if(ans.find(a[i]) != ans.end()){
				res++;
				ans.clear();
			}
			ans.insert(a[i]);
		}
		
		cout << res << endl;
	}
		

	return 0;
}
