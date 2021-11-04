/*
ID: vasucp11
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

//	freopen("gift1.in", "r", stdin);
//	freopen("gift1.out", "w", stdout);

	int n;
	cin >> n;
	
	string name[n];
	for(int i = 0; i < n; i++) cin >> name[i];
	
	int money[n] = {0};
	for(int i = 0; i < n; i++){
		
		string donor;
		cin >> donor;
		int mon, peoples;
		cin >> mon, peoples;
		
		if(mon == 0 || peoples == 0) continue;
		
		int profit = mon / peoples;  // money each person gets
		
		for(int j = 0; j < n; j++){
			if(donor == name[j]) money[j] = money[j] - peoples * profit;
		}
		
		for(int j = 0; j < peoples; j++){
			
			string str;
			cin >> str;
			
			for(int k = 0; k < n; k++){
				if(str == name[k]){
					money[k] += profit;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++) cout << name[i] << " " << money[i] << endl;


	


return 0;
}
