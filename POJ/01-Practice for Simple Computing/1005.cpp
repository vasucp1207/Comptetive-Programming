#include <iostream>
#include <vector>
#include <climits>
#include <math.h>

using namespace std;

int main(){
	
	int t;
	cin >> t;
	int cnt = 1;
	while(t--){
		
		float x, y;
		cin >> x >> y;
		
		float ans = 3.14159265 * (x * x + y * y) / 2;
		ans = ans / (float)50;
		
		ans = floor(ans) + 1;
		cout  << "Property " << cnt++ << ": This property will begin eroding in year " << ans << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;


return 0;
}
