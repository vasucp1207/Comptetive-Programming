/* Weights Assignment For Tree Edges: https://codeforces.com/problemset/problem/1611/D */

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

ll pwr(ll a, ll b) {a %= mod; ll res = 1; while (b > 0) {if (b & 1) res = res * a % mod; a = a * a % mod; b >>= 1;} return res;}
ll mod_mul(ll a, ll b) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}

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
		vector<int> b(n + 1), p(n + 1);
		for(int i = 1; i <= n; i++){
			cin >> b[i];
		}
		for(int i = 1; i <= n; i++){
			cin >> p[i];
		}

		vector<int> d(n + 1, -1);
		if(p[1] != b[p[1]]){
			cout << -1 << endl;
			continue;
		}

		d[p[1]] = 0;
		bool flag = 0;
		for(int i = 2; i <= n; i++){
			if(d[b[p[i]]] == -1){
				cout << -1 << endl;
				flag = 1;
				break;
			}
			d[p[i]] = d[p[i - 1]] + 1;
		}

		if(!flag) 
			for(int i = 1; i <= n; i++){
				cout << d[i] - d[b[i]] << " ";
			} cout << endl;
	}
	
	

    return 0;
}
