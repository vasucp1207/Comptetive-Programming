#include <bits/stdc++.h>
#include <bitset>

using namespace std;

void gcd(int a, int b, int &x, int &y){
	
	if(b == 0){
		x = 1;
		y = 0;
		return ;
	}
	
	int x1, y1;
	gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return ;
}

int main(){
	
	int a, b;
	cin >> a >> b;
	
	int x, y;
	gcd(a, b, x, y);
	
	cout << x << " , " <<  y;
	
	
	
	
	return 0;
}
