#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());} 

int main(){

	int id = 0, step, mod;
	
	while(cin >> step >> mod){
		
		bool vis[mod] = {0};
		bool bad = false;
		
		for(int i = 0; i < mod; i++){
			
			int x = (id + step) % mod;
			
			if(vis[x]){
				bad = true;
			}
			vis[x] = 1;
			id = x;
		}
		
		cout << setw(10) << step << setw(10) << mod << "    ";
		if(bad)cout << "Bad Choice\n\n";
		else cout << "Good Choice\n\n";
	}


return 0;
}
