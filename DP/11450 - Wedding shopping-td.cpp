#include <bits/stdc++.h>

using namespace std;
	
int m, c, price[22][22];
int memo[222][22];

int shop(int money, int g){
	
	if(money < 0) return -1e9;
	if(g == c) return m - money;
	
	if(memo[money][g] != -1) return memo[money][g];
	
	int ans = -1;
	for(int model = 1; model <= price[g][0]; model++)
		ans = max(ans, shop(money - price[g][model], g + 1));
		
	return memo[money][g] = ans;
}

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
		
		memset(memo, -1, sizeof memo);
		int score = shop(m, 0);
		if(score < 0) cout << "no solution" << endl;
		else cout << score << endl;
	}


return 0;
}
