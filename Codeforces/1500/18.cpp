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
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

using namespace std;

void solve() {
	ll n, c, d;
	cin >> n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ll> ans;
	ll curr = 0;
	for(ll i = 0; i < min(n, 31ll); i++) {
		ll idx = -1;   // best index for curr bi
		ll temp = curr;

		for(ll j = 0; j < n; j++) {
			if(a[j] == -1) continue;

			if((curr | a[j]) >= temp) {
				idx = j;
				temp = curr | a[j];
			}
		}

		curr |= a[idx];
		ans.pb(a[idx]);
		a[idx] = -1;
	}

	for(ll i = 0; i < n; i++) {
		if(a[i] != -1) ans.pb(a[i]);    // ans not affect after the 31 iterations
	}

	for(ll i = 0; i < n; i++) {
		cout << ans[i] << " ";
	} cout << endl;
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
	while(t--) {
		solve();
	}



    return 0;
}
