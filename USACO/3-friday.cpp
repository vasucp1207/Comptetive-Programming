/*
ID: vasucp11
TASK: friday
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	ofstream fout ("friday.out");
	ifstream fin ("friday.in");
	
	int n;
	fin >> n;
	
	int freq[8] = {0};
	int cons = 1;
	
	for(int year = 1900; year <= (1900 + n - 1); year++){
		
		for(int i = 1; i <= 12; i++){  // month
			
			int friday_13th = (13 + cons - 1) % 7;
			if(friday_13th == 0) friday_13th = 7;  // mod => (0, 1, .....6) and sun = 1
			freq[friday_13th]++;
			
			if(i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12){
				cons = (32 + cons - 1) % 7;
			}
			else if(i == 4 || i == 6 || i == 9 || i == 11){
				cons = (31 + cons - 1) % 7;
			}
			else{  // february
				if(year == 1900 || year == 2100 || year == 2200){
					cons = (29 + cons - 1) % 7;
				}
				else if(year % 4 == 0){
					cons = (30 + cons - 1) % 7;
				}
				else{
					cons = (29 + cons - 1) % 7;
				}
			}
			if(cons == 0) cons = 7;  // for sunday
		}
	}
	
	fout << freq[6] << " " << freq[7] << " " << freq[1] << " " << freq[2] << " " << freq[3] << " " << freq[4] << " " << freq[5] << endl;

		
	


return 0;
}
