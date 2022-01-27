/* Grid Xor(very easy 2300) */

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

// #include "ext/pb_ds/assoc_container.hpp"
// #include "ext/pb_ds/tree_policy.hpp"
// using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second

const int mod = 1e9 + 7;

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("inputcf.txt" , "r" , stdin);
    freopen("outputcf.txt", "w", stdout);
	#endif

	int t;
	cin >> t;

	while(t--){

		int n;
		cin >> n;
		int g[n + 2][n + 2];
		for(int i = 0; i <= n + 1; i++){
			for(int j = 0; j <= n + 1; j++){
				g[i][j] = 0;
			}
		}

		int ans = 0;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				int x;
				cin >> x;
				if(!g[i][j - 1] && !g[i - 1][j] && !g[i][j + 1] && !g[i + 1][j]){
					ans ^= x;
					g[i - 1][j] = 1;
					g[i + 1][j] = 1;
					g[i][j - 1] = 1;
					g[i][j + 1] = 1;
				}
			}
		}
		cout << ans << endl;
	}


	return 0;
}
