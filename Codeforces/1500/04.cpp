/* Replace With the Previous, Minimize: https://codeforces.com/problemset/problem/1675/E */

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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;

		vector<int> a(n);
		int mx = 0;
		for(int i = 0; i < n; i++){
			a[i] = s[i] - 'a';
			mx = max(mx, a[i]);
		}

		if(mx <= k){
			for(int i = 0; i < n; i++){
				cout << "a";
			} cout << endl;
			continue;
		}

		int pos = 0;
		for(int i = 0; i < n; i++){
			if(a[i] > k){
				pos = i;
				break;
			}
		}

		int mxx = 0;
		for(int i = 0; i < pos; i++){
			s[i] = 'a';
			mxx = max(a[i], mxx);
		}
		for(int i = pos + 1; i < n; i++){
			if(a[i] <= mxx){
				s[i] = 'a';
			}
		}

		int t = a[pos];
		a[pos] -= k - mxx;
		s[pos] = a[pos] + 'a';
		cout << t << " " << a[pos] << " " << s[pos] << endl;
		for(int i = pos + 1; i < n; i++){
			if(a[i] > mxx && a[i] <= t){
				a[i] = min(a[i], a[pos]);
				s[i] = a[i] + 'a';
			}
		}

		cout << s << endl;
	}
	
	

    return 0;
}
