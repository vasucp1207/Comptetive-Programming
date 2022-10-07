/* Running for Gold: https://codeforces.com/problemset/problem/1552/B */

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

int n;
int a[50005][6];
bool sup(int i, int j){
	int cnt = 0;
	for(int k = 1; k <= 5; k++){
		if(a[i][k] > a[j][k]) cnt++;
	}

	return cnt >= 3;
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
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 5; j++){
				cin >> a[i][j];
			}
		}

		int ans = 1;
		for(int i = 2; i <= n; i++){
			if(sup(ans, i)){
				ans = i;
			}
		}


		bool flag = true;
		for(int i = 1; i <= n; i++){
			if(i != ans){
				if(sup(ans, i)){
					flag = false;
					break;
				}
			}
		}

		if(flag) cout << ans << endl;
		else cout << -1 << endl;
	}
	



    return 0;
}
