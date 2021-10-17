/* Check why this code is not worked for big values */

#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(10000000);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 10000000; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(int i = 2; i < sqrt(upperbound); i++){
		if(flag[i]){
			for(int j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

bool primeCheck(int n){
	
	if(n < 10000000)return flag[n];
	for(int i = 0; i < primes.size(); i++){
		if(n % primes[i] == 0)return false;
	}
	return true;
}

int main(){
	
	sievee(10000000);
	
	int n, m;
	while(cin >> n >> m){
		
		vector<int> list;
		for(int i = n; i <= m; i++){
			if(primeCheck(i))
				list.push_back(i);
		}
		
		int a, b, c, d;
		int dis = 0;
		int mn = 1000000000;
		int mx = -1;
		
		for(int i = 1; i < list.size(); i++){
			
			dis = list[i] - list[i - 1];
			if(dis < mn){
				mn = dis;
				a = list[i - 1];
				b = list[i];
			}
			if(dis > mx){
				mx = dis;
				c = list[i - 1];
	            d = list[i];
			}
		}
		
		if(list.size() < 2)
			cout << "There are no adjacent primes." << endl;
		else
			cout << a << "," << b << " are closest, " << c << "," << d << " are most distant." << endl;
			
	}
	
	
	
	
	
	
	
	return 0;
}
