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

const ll mod = 1e9 + 7;
const ll mod1 = 998244353;

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

using namespace std;

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t = 1; 
	// cin >> t; 
	while(t--) {
		ll n;
		cin >> n;
		ll a[n + 1][n + 1];
		ll sum = 0;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				cin >> a[i][j];
				sum += a[i][j];
			}
		}
		
		ll res = 0;
		for(ll i = 1; i <= n; i++) {
			for(ll j = 1; j <= n; j++) {
				res = max(res, sum - a[i][n - i + 1]);
			}
		}
		cout << res << endl;
	}

    return 0;
}
