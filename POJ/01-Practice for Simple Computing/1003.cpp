#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int main(){
	
	double c;
	while(cin >> c){
		
		if(c == 0) break;
		
		double sum = 0;
		int ans; 
		for(double i = 2.00; i < 500.00; i++){
			sum = sum + 1.00 / i;
			if(sum >= c){
				ans = (int)i - 1;
				break;
			}
		}
		
		cout << ans << " card(s)" << endl;
	}


return 0;
}
