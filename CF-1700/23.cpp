/* Peculiar Movie Preferences */

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
#define all(x) (x).begin(), (x).end()

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
		vector<string> s(n);
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}

		bool flag = false;
		for(int i = 0; i < n; i++){
			// check for palindrome....
			if(s[i][0] == s[i].back()){
				flag = true;
				break;
			}
		}

		if(flag){
			cout << "YES" << endl;
			continue;
		}

		set<string> ss;
		for(int i = 0; i < n; i++){
			string curr = s[i];
			reverse(all(curr));
			// check for reverse....
			if(ss.find(curr) != ss.end()){
				flag = true;
				break;
			}
			ss.insert(s[i]);
		}

		if(flag){
			cout << "YES" << endl;
			continue;
		}

		ss.clear();
		// check for ab, cba....
		for(int i = n - 1; i >= 0; i--){
			if(s[i].size() == 2){
				string curr = s[i];
				reverse(all(curr));
				if(ss.find(curr) != ss.end()){
					flag = true;
					break;
				}
			}
			if(s[i].size() == 3){
				string curr = s[i];
				ss.insert(curr.substr(1, 2));
			}
		}

		if(flag){
			cout << "YES" << endl;
			continue;
		}

		ss.clear();
		// check for abc, ba....
		for(int i = 0; i < n; i++){
			if(s[i].size() == 2){
				string curr = s[i];
				reverse(all(curr));
				if(ss.find(curr) != ss.end()){
					flag = true;
					break;
				}
			}
			if(s[i].size() == 3){
				string curr = s[i];
				ss.insert(curr.substr(0, 2));
			}
		}

		if(flag){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}


	return 0;
}
