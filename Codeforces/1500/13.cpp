/* Jeopardy of Dropped Balls: https://codeforces.com/problemset/problem/1575/J */

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

	int n, m, k;
	cin >> n >> m >> k;
	int a[n][m];
	vector<int> b(k);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < k; i++){
		cin >> b[i];
		b[i]--;
	}

	for(int i = 0; i < k; i++){
		int r = 0, c = b[i];
		int col = c;
		while(r < n && c >= 0 && c < m){
			int curr = a[r][c];
			int o_r = r;
			int o_c = c;
			if(curr == 1){
				c++;
			} else if(curr == 2){
				r++;
			} else {
				c--;
			}
			a[o_r][o_c] = 2;
			col = c;
		}
		cout << col + 1 << " ";
	} cout << endl;
	



    return 0;
}
