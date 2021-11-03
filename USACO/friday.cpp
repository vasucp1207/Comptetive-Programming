/*
ID: vasucp11
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

//	freopen("friday.in", "r", stdin);
//	freopen("friday.out", "w", stdout);

	int n;
	cin >> n;
	
//	string days[7] = {'mon', 'tue', 'wed', 'th', 'fri', 'sat', 'sun'};
	int freq[7] = {0};
	int c = 0;

	for(int i = 1; i < n; i++){
		int year = 1900;
		
		for(int j = 0; j < 12; j++){
			
			int date13 = (13 + c) % 7;
			freq[date13]++;
			
			if(j == 0 || j == 2 || j == 4 || j == 6 || j == 7 || j == 9 || j == 11)
				c = (31 + c) % 7;
			else if(j == 1){
				
				if(year < 2100 && year >= 2000){
					if(year % 4 == 0) c = (29 + c) % 7;
					else c = (28 + c) % 7;
				}
				else{
					c = (28 + c) % 7;
				}
			}
			else{
				c = (30 + c) % 7;
			}
		}
		year++;
	}
	
	for(int i = 0; i < 7; i++){
		cout << freq[(i + 5) % 7] << " ";
	}
	


return 0;
}
