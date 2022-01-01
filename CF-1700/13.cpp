#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second
// std::vector<int>::iterator it;

int main(){

	int t = 1;
	cin >> t;
	
	while(t--){
		
		int n;
		cin >> n;
		if(n % 2){
			cout << "Bob" << endl;
			continue;
		}
		
		int cnt = 0;
		while(n % 2 == 0){
			cnt++;
			n /= 2;
		}
		if(n > 1){
			cout << "Alice" << endl;
			continue;
		}
		else{
			if(cnt % 2){
				cout << "Bob" << endl;
			}
			else{
				cout << "Alice" << endl;
			}
		}
	}
		

	return 0;
}
