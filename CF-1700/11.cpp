/* Another Problem About Dividing Numbers */

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define fi first
#define se second

//vector<int> primes;
vector<bool> flag(100005, 1);

void sieve(){
	for(int i = 2; i * i <= 40000; i++){
		if(flag[i]){
//			primes.push_back(i);
			for(int j = i * i; j <= 40000; j += i){
				flag[j] = 0;
			}
		}
	}
}

int gcd(int a, int b){
	if(b == 0) return a;
	else return gcd(b, a % b);
}

int main(){

	sieve();
	int t;
	cin >> t;
	
	while(t--){
		int a, b, k;
		cin >> a >> b >> k;
		if(k == 1){
			int g = gcd(a, b);
			if((g == a || g == b) && a != b) cout << "YES" << endl;
			else cout << "NO" << endl;
			continue;
		}
		if(a == 1 && b == 1){
			cout << "NO" << endl;
			continue;
		}
		if(a != b && k == 2 && a != 1 && b != 1){
			cout << "YES" << endl;
			continue;
		}
		
		int diva = 0, divb = 0;
		for(int i = 2; i < 40000; i++){
			if(flag[i]){
				while(a % i == 0){
					a /= i;
					diva++;
				}
			}
			if(a == 1) break;
		}
		if(a > 1) diva++;
		
		for(int i = 2; i < 40000; i++){
			if(flag[i]){
				while(b % i == 0){
					b /= i;
					divb++;
				}
			}
			if(b == 1) break;
		}
		if(b > 1) divb++;
		
		if(diva + divb >= k){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
		

	return 0;
}
