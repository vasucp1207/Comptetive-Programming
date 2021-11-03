#include <bits/stdc++.h>

using namespace std;

int price[22][22];
int reachable[22][222];
int m, c, g, money;

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		
		cin >> m >> c;
		for(int i = 0; i < c; i++){
			cin >> price[i][0];        // store k in price[i][0]
			for(int j = 1; j <= price[i][0]; j++){
				cin >> price[i][j];
			}
		}
		
		memset(reachable, false, sizeof reachable);
		
		for(g = 1; g <= price[0][0]; g++){
			if(m - price[0][g] > 0) 
				reachable[0][m - price[0][g]] = true;
		}
		
		for(g = 1; g < c; g++){
			for(money = 0; money < m; money++){
				if(reachable[g - 1][money]){
					for(int k = 1; k <= price[g][0]; k++){
						if(money - price[g][k] >= 0)
							reachable[g][money - price[g][k]] = true;
					}
				}
			}
		}
		
		for(money = 0; money <= m && !reachable[c - 1][money]; money++);
			
		if(money == m + 1) cout << "no solution" << endl;
		else cout << m - money << endl;
	}



return 0;
}
