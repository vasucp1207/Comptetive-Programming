#include <bits/stdc++.h>

using namespace std;
#define ll long long 
#define fi first
#define se second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int main(){
	
	int n, s;
	while(cin >> n >> s){
		
		int a[n];
		for(int i = 0; i < n; i++) cin >> a[i];
		
		int sum = 0;
		int j = 0;
		int len = 0, ans = 10000000;
		for(int i = 0; i < n; i++){
			
			sum += a[i];
			len++;
			
			if(sum > s){
				while(sum > s){
					if(sum > s) ans = min(len, ans);
					
					sum -= a[j++];
					len--;
				}
			}
			if(sum == s) ans = min(ans, len);
		}
		if(ans == 10000000) cout << 0 << endl;
		else cout << ans << endl;
	}
		
		

return 0;
}
