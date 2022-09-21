/* Garage: https://codeforces.com/problemset/problem/1725/G */

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

	int n;
	cin >> n;

	if(n == 1){
		cout << 3 << endl;
	}
	else if(n % 3  == 0){
		cout << (n / 3) * 4 + 3 << endl;
	}
	else if(n % 3 == 1){
		cout << (n / 3) * 4 + 4 << endl;
	}
	else{
		cout << (n / 3) * 4 + 5 << endl;
	}
	
	

    return 0;
}
