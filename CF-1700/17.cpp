/* Ceil Divisions */

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

using namespace std;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	#ifndef ONLINE_JUDGE
    freopen("inputcf.txt" , "r" , stdin);
    freopen("outputcf.txt", "w", stdout);
	#endif

	int t = 1;
    cin >> t;
	
	while(t--){

		int n;
		cin >> n;
		vector<pair<int, int>> ans;
		int steps = 0;

		if(n == 3){
			cout << 2 << endl;
			cout << 3 << " " << 2 << endl;
			cout << 3 << " " << 2 << endl;
		}

		else if(n <= 16){
			for(int i = 3; i < n; i++){
				ans.push_back({i, n});
				steps++;
			}

			int x = n;
			while(x > 1){
				x = ceil(x / 2.0);
				// cout << x << endl;
				ans.push_back({n, 2});
				steps++;
			}

			cout << steps << endl;
			for(int i = 0; i < ans.size(); i++)
				cout << ans[i].fi << " " << ans[i].se << endl;
		}

		else{
			for(int i = 3; i < n; i++){
				if(i == 16) continue;
				ans.push_back({i, n});
				steps++;
			}

			int x = n;
			while(x > 1){
				ans.push_back({n, 16});
				x = ceil(x / 16.0);
				steps++;
			}
			for(int i = 1; i <= 4; i++){
				ans.push_back({16, 2});
				steps++;
			}

			cout << steps << endl;
			for(int i = 0; i < ans.size(); i++)
				cout << ans[i].fi << " " << ans[i].se << endl;
		}
	}



	return 0;
}
