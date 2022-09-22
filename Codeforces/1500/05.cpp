/* Price Maximization: https://codeforces.com/problemset/problem/1690/E */

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
		vector<int> a(n);
		ll sum = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i] / k;
			a[i] = a[i] % k;
		}

		sort(a.begin(), a.end());
		int l = 0;
		int r = n - 1;
		while(l < r){
			if((a[l] + a[r]) < k){
				l++;
			}
			else{
				sum++;
				l++;
				r--;
			}
		}

		cout << sum << endl;
	}
	
	

    return 0;
}
