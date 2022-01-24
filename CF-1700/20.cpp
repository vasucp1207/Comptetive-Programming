/* C - Monsters And Spells */ 

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
		vector<int> k(n), h(n);
		for(int i = 0; i < n; i++) cin >> k[i];
		for(int i = 0; i < n; i++) cin >> h[i];

		int st, en, len, i = n - 1;
		ll ans = 0;
		while(i >= 0){

			en = k[i];
			st = k[i] - h[i] + 1;
			while(i >= 0 && st <= k[i]){
				st = min(st, k[i] - h[i] + 1);
				i--;
			}

			len = en - st + 1;
			ans += 1ll * len * (len + 1) / 2;
		}
		cout  << ans << endl;
	}


	return 0;
}
