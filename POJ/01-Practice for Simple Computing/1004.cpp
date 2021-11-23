#include <bits/stdc++.h>

using namespace std;

int main(){

	double ans = 0.0;
	double x;
	for(int i = 0; i < 12; i++){
		
		cin >> x;
		ans += x;
	}
	cout << "$" << ans / 12.0;



return 0;
}
