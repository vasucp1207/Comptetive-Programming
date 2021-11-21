#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int t;
	cin >> t;
	int r = 1;
	while(t--){
		
		int s;
		cin >> s;
		
		int max_sum, max_here, i, i_here, max_i, max_j;
		max_here = max_here = i_here = max_i = max_j = 0;
		for(i = 0; i < s - 1; i++){
			
			int x;
			cin >> x;
			max_here += x;
			
			if(max_here < 0){
				max_here = 0;
				i_here = i + 1;
			}
			if(max_here > max_sum || (max_here == max_sum && i - i_here > max_j - max_i)){
				max_sum = max_here;
				max_i = i_here;
				max_j = i;
			}
		}
		if(max_sum == 0){
			cout << "Route " << r++ <<  " has no nice parts" << endl;
		}
		else{
			cout << "The nicest part of route " << r++ << " is between stops " << max_i + 1 << " and " << max_j + 2 << endl;
		}
	}
		
	

return 0;
}
