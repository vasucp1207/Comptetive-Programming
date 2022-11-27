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

bool solve() {
	ll n, m, k;
	cin >> n >> m >> k;
	vector<ll> a(k);
	for(ll i = 0; i < k; i++) {
		cin >> a[i];
	}
	
	ll curr = k;
	ll cells = n * m - 2;
	vector<ll> vis(k + 1);
	for(ll i = 0; i < k; i++) {
		if(a[i] == curr) {
			if(cells >= 2) {
				curr--;
				while(vis[curr]) {   // check if curr is not in the cell (0, 0)
					curr--;
					cells++;
				}
			}
			else {
				return false;
			}
		}
		else {
			vis[a[i]] = 1;
			cells--;
		}
	}
	return true;
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		if(solve()) cout << "YA" << endl;
		else cout << "TIDAK" << endl;
	}

    return 0;
}
