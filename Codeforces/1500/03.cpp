/* Color the Picture: https://codeforces.com/problemset/problem/1710/A */

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

bool solve(int n, int m, vector<int> &a){

	vector<ll> c_fill;
	ll t_col = 0;
	ll o_col = 0;
	ll extra = 0;

	for(int i = 0; i < a.size(); i++){
		if(a[i] / n >= 2) c_fill.pb(a[i] / n);
	}

	for(int i = 0; i < c_fill.size(); i++){
		t_col += c_fill[i];
		if(c_fill[i] % 2) o_col = 1;
		if(c_fill[i] > 3 && c_fill[i] % 2 == 0) extra = 1;
	}

	if(t_col < m){
		return false;
	}

	else{
		if(m % 2 == 0){
			// cout << m <<  " ";
			return true;
		}
		else{
			if(o_col){
				// cout << "o_col";
				return true;
			}
			else{
				if(extra){
					// cout << "extra";
					return true;
				}
				else{
					return false;
				}
			}
		}
	}
}

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
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(k);
		for(int i = 0; i < k; i++){
			cin >> a[i];
		}
		bool aa = solve(n, m, a);
		bool bb = solve(m, n, a);

		if(aa || bb) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	
	

    return 0;
}
