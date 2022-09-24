/* Representative Edges: https://codeforces.com/problemset/problem/1616/C */

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
		int n;
		cin >> n;
		vector<int> a(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		if(n == 1 || n == 2){
			cout << 0 << endl;
			continue;
		}
		
		int ans = 1e9 + 5;
		for(int i = 0; i < n; i++){
			for(int j = i + 1; j < n; j++){
				int curr = 0;
				for(int k = 0; k < n; k++){
					if(((a[j] - a[i]) * (k - i)) == (a[k] - a[i]) *(j - i)) continue;
					else curr++;
				}
				ans = min(ans, curr);
			}
		}

		cout << ans << endl;
	}
	
	

    return 0;
}
