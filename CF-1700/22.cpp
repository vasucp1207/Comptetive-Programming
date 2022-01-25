/* String Deletion */

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
		string s;
		cin >> s;

		vector<int> groups;
		int pt = 0;
		int sz = 1;
		for(int i = 1; i < n; i++){
			if(s[i] == s[pt]) sz++;
			else{
				pt = i;
				groups.pb(sz);
				sz = 1;
			}
		}
		groups.pb(sz);
		// for(int x: groups) cout << x << " ";
		// cout << endl;

		int ans = 0;
		sz = groups.size();
		pt = 0;

		for(int i = 0; i < sz; i++){

			while(pt < sz){
				if(groups[pt] >= 2){
					groups[pt]--;
					break;
				}
				pt++;
			}

			if(pt == sz){
				ans += ceil((pt - i) / 2.0);
				break;
			}
			while(pt <= i) pt++;
      // why pt = i + 1 getting TLE...  
			ans++;
		}
		cout << ans << endl;
	}


	return 0;
}
