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
	cin >> n >> c >> d;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(all(a));
	reverse(all(a));

	ll l = 0, r = d - 1;
	while(l < r) {
		ll m = l + (r - l  + 1) / 2;
		ll sum = 0;

		for(ll i = 0; i < d; i++) {
			if(i % m < n) {
				sum += a[i % m];
			}
		}
		if(sum >= c) {
			l = m;
		} else {
			r = m - 1;
		}
	}
	if(l == 0) cout << "Impossible" << endl;
	else if(l == d - 1) cout << "Infinity" << endl;
	else cout << l - 1 << endl;
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
