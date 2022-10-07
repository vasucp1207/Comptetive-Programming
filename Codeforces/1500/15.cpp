/* Interesting Story: https://codeforces.com/problemset/problem/1551/C */

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
const ll mod1 = 998244353;

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

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
		vector<string> s(n);
		for(int i = 0; i < n; i++){
			cin >> s[i];
		}

		int res = 0;
		for(char c = 'a'; c <= 'e'; c++){
			vector<int> vals;
			for(int i = 0; i < n; i++){
				int cnt = count(all(s[i]), c);
				vals.pb(cnt - (s[i].size() - cnt));
			}

			sort(all(vals));
			int sum = 0;
			int mx = 0;
			for(int i = n - 1; i >= 0; i--){
				sum += vals[i];
				if(sum <= 0) break;
				mx++;
			}
			res = max(res, mx);
		}
		cout << res << endl;
	}
	



    return 0;
}
