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
	ll q;
	cin >> q;
	
	bool otherA = 0, otherB = 0;
	ll sz1 = 1, sz2 = 1;
	while(q--) {
		ll op, k;
		string x;
		cin >> op >> k >> x;
		
		if(op == 2) {
			for(auto c: x) {
				if(c != 'a') otherA = 1;
			}
			sz1 += (k * x.size());
		}
		else {
			for(auto c: x) {
				if(c != 'a') otherB = 1;
			}
			sz2 += (k * x.size());
		}
	
		if(otherA) cout << "Yes" << endl;
		else if(!otherB && sz1 > sz2) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
	}



    return 0;
}
