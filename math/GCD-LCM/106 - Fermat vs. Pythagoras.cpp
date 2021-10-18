#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ull unsigned long long

int gcd(int a, int b){ return b == 0? a: gcd(b, a % b); }
int lcm(int a, int b){ return a * (b / gcd(a, b)); }

int main(){
	
	int n;
	int pri, npri, a, b, c;
	bool vis[1000005];
	while(cin >> n){
		
		pri = 0;
		npri = 0; 
			
		memset(vis, 0, sizeof(vis));
			
		for(int r = 1; r * r <= n; r++){
				
			int x = min((n - r * r), r - 1);
			for(int s = 1; s <= x; s++){
					
				a = r * r - s * s;
				b = 2 * r * s;
				c = r * r + s * s;
					
				if(a * a + b * b == c * c && c <= n){
						
					if(gcd(a, b) == 1){
							
						pri++;
						for(int k = 1; k * c <= n; k++){
							vis[k * a] = 1;
							vis[k * b] = 1;
							vis[k * c] = 1;
						}
					}
				}
			}	
		}
			
		for(int i = 1; i <= n; i++){
			if(vis[i] == 0)npri++;
		}
			
		cout << pri << " " << npri << endl;
	}
	
	
	
	
	
	
	
	return 0;
}
