/* Array Destruction */

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

vector<int> result(vector<int>& a, int x, int n){

	multiset<int> s;
	for(auto v: a){
		s.insert(v);
	}

	vector<int> res;
	for(int i = 0; i < n; i++){
		auto it1 = s.end();
		it1--;

		int u = x - *it1;
		s.erase(it1);
		auto it2 = s.find(u);

		if(it2 == s.end()){
			return {};
		}

		res.pb(x - u);
		res.pb(u);

		x = max(u, x - u);
// 		cout << *it1 << " " << *it2 << endl;
		s.erase(it2);
	}

	return res;
}

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt" , "r" , stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif

	int t = 1;
    cin >> t;
	
	while(t--){

		int n;
		cin >> n;
		vector<int> a(2 * n);
		for(int i = 0; i < 2 * n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        
        bool flag = false;
		for(int i = 0; i < 2 * n - 1; i++){
			int x = a[i] + a[2 * n - 1];
			// largest is fixed

			vector<int> res = result(a, x, n);
			if(res.size()){
			    flag = true;
				cout << "YES" << endl;
				cout << x << endl;
				for(int j = 0; j < n; j++){
					cout << res[ 2 * j] << " " << res[2 * j + 1] << endl;
				}
				break;
			}
		}
		if(!flag)
			cout << "NO" << endl;
	}

	return 0;
}
