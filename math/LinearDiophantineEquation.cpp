#include <bits/stdc++.h>
#include <bitset>

using namespace std;

int gcd(int a, int b, int &x, int &y){
	
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	
	int x1, y1;
	int d = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - y1 * (a / b);
	return d;
}

bool find_sol(int a, int b, int c, int &x, int &y){
	
	int x1, y1;
	int g = gcd(abs(a), abs(b), x1, y1);
	
	if(c % g)
		return false;
	
	x = x1 * c / g;
	y = y1 * c / g;
	
	if(a < 0)x = -x;
	if(b < 0)y = -y;
	
	return true;
}

int main(){
	
	int t, a, b, c, x, y;
	
	cin >> t;
	
	while(t--){
		cin >> a >> b >> c;
		
		if(find_sol(a, b, c, x, y) == false){
			cout << "No solution exist" << endl;
		} 
		else{
			cout << "x = " << x << " , y = " << y <<endl;
		}
	}
	
	
	
	
	return 0;
}
