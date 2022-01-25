/* Bargain */

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

	string s;
	cin >> s;

	vector<ll> a(s.size());
	for(int i = 0; i < s.size(); i++){
		a[i] = s[i] - '0';
	}

	ll ans = 0;
	ll sum = 0;
	ll pow = 1;

	for(ll i = s.size() - 1; i >= 0; i--){

		ll k = (i * (i + 1) / 2 % mod * pow % mod + sum) % mod;
		sum = (sum + pow * (s.size() - i) % mod) % mod;
		pow = pow * 10 % mod;
		ans = (ans + a[i] * k % mod) % mod;
	}
	cout << ans << endl;

	return 0;
}
