/* Line Empire: https://codeforces.com/problemset/problem/1659/C */

#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define ln "\n"
#define all(x) (x).begin(), (x).end()
const int mod = 1e9 + 7;

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	#ifndef ONLINE_JUDGE
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt", "w", stdout);
	#endif

	int t;
	cin >> t;
	while(t--){
		int n, a, b;
		cin >> n >> a >> b;
		vector<ll> x(n);
		vector<ll> pref(n, 0);
		for(int i = 0; i < n; i++){
			cin >> x[i];
		}

		pref[0] = x[0];
		for(int i = 1; i < n; i++){
			pref[i] = pref[i - 1] + x[i];
		}

		ll ans = b * pref[n - 1];
		ll prev = b * x[0];
		for(int i = 0; i < n; i++){
			ans = min(ans, prev + (x[i] * a) + (pref[n - 1] - pref[i] - ((n - i - 1) * x[i])) * b);
			if(i + 1 != n){
				prev += b * (x[i + 1] - x[i]);
			}
		}

		cout << ans << endl;
	}
	
	

    return 0;
}
