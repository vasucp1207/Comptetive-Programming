/* Fault-tolerant Network: https://codeforces.com/problemset/problem/1651/C */

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
		vector<ll> a(n), b(n);
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}

		ll ans = abs(a[0] - b[0]) + abs(a[n - 1] - b[n - 1]);
		ans = min(ans, abs(a[0] - b[n - 1]) + abs(a[n - 1] - b[0]));

		ll m_a, m_b, m_an, m_bn;
		m_a = m_b = m_an = m_bn = 2e9 + 5;
		for(int i = 0; i < n; i++){
			// min diff fro each end to other array
			m_a = min(m_a, abs(a[0] - b[i]));
			m_an = min(m_an, abs(a[n - 1] - b[i]));
			m_b = min(m_b, abs(b[0] - a[i]));
			m_bn = min(m_bn, abs(b[n - 1] - a[i]));
		}

		ans = min(ans, abs(a[0] - b[0]) + m_an + m_bn);
		ans = min(ans, abs(a[n - 1] - b[n - 1]) + m_a + m_b);
		ans = min(ans, m_a + m_an + m_b + m_bn);
		ans = min(ans, abs(a[0] - b[n - 1]) + m_an + m_b);
		ans = min(ans, abs(b[0] - a[n - 1]) + m_a + m_bn);

		cout << ans << endl;
	}
	
	

    return 0;
}
