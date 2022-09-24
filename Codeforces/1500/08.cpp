/* Integers Shop: https://codeforces.com/problemset/problem/1621/B */

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
		int ml = 1e9 + 5, mr = 0, mlen = 0, mcl, mcr, mclen;

		for(int i = 0; i < n; i++){
			int l, r, c;
			cin >> l >> r >> c;

			if(l < ml) ml = l, mcl = c;
			if(l == ml) mcl = min(mcl, c);

			if(r > mr) mr = r, mcr = c;
			if(r == mr) mcr = min(mcr, c);

			if(mlen < r - l + 1) mlen = r - l + 1, mclen = c;
			if(mlen == r - l + 1) mclen = min(mclen, c);

			int ans = mcl + mcr;
			if(mlen == mr - ml + 1) ans = min(mclen, ans);
			cout << ans << endl;
		}
	}
	
	

    return 0;
}
