#include <bits/stdc++.h>

using namespace std;

int x, y;
void extendedEuclid(int a, int b){
	
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}
	extendedEuclid(b, a % b);
	int x1 = y;
	int y1 = x - (a / b) * y;
	x = x1;
	y = y1;
	return ;
}

int main(){
	
	int a, b;
	cin >> a >> b;
	
	extendedEuclid(a, b);
	
	cout << x << " " << y << endl;
	

return 0;
}
