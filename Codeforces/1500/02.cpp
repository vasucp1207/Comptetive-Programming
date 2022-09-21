/* Even-Odd XOR: https://codeforces.com/problemset/problem/1722/G */

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

		vector<ll> a(n, 0);
		int j = 1;

		if(n == 3){
			cout << 2 << " " << 1 << " " << 3 << endl;
			continue;
		}
		if(n % 2){
			for(int i = 1; i < n; i += 2){
				a[i] = j++;
			}
			j = 1;
			for(int i = 2; i < n; i += 2){
				a[i] = j++;
			}
		}
		else{
			for(int i = 0; i < n; i += 2){
				a[i] = j++;
			}
			j = 1;
			for(int i = 1; i < n; i += 2){
				a[i] = j++;
			}
		}

		if(n % 2){
			if(((n + 1) / 2) % 2){
				for(int i = 1; i < n; i += 2){
					a[i] |= (1ll << 30);
				}
			}
			else{
				for(int i = 1; i < n - 2; i += 2){
					a[i] |= (1ll << 30);
				}
				for(int i = 3; i < n; i += 2){
					a[i] |= (1ll << 29);
				}
			}
		}

		else{
			if(n / 2 % 2){
				for(int i = 1; i < n - 2; i += 2){
					a[i] |= (1ll << 30);
				}
				for(int i = 3; i < n; i += 2){
					a[i] |= (1ll << 29);
				}
			}
			else{
				for(int i = 1; i < n; i += 2){
					a[i] |= (1ll << 30);
				}
			}
		}

		for(int i = 0; i < n; i++) cout << a[i] << " ";
		cout << endl;
	}
	
	

    return 0;
}
