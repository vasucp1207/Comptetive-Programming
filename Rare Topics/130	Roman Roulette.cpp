#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int josephus(int n, int k){
	
	if(n == 1)return 1;
	
	else return (josephus(n - 1, k) + k - 1) % n + 1;
}

int main(){

	int n, k;
	
	while(cin >> n >> k){
		
		if(n == 0 && k == 0) break;
		
		int ans = josephus(n, k);
		cout << ans << endl;
	}


return 0;
}
