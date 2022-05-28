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

#define lb lower_bound
#define ub upper_bound
#define ll long long
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

const int mod = 1e9 + 7;

using namespace std;
    
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input1.txt" , "r" , stdin);
    freopen("output1.txt", "w", stdout);
    #endif

    int sum1 = 0;
    int sum2 = 0;
    int sum3 = 0;

    int a[3][3] = {{3, 7, 9,},
                {3, 6, 7},
                {9, 23, 5}
            };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j <= i; j++){
            sum1 += a[i][j];
        }
    }

    for(int j = 0; j < 3; j++){
        for(int i = j; i < 3; i++){
            sum2 += a[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = i; j < 3; j++){
            sum3 += a[j][i];
        }
    }

    cout << sum1 << " " << sum2 << " " << sum3 << endl;
    

    return 0;
}
