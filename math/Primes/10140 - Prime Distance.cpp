#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(1000000);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 1000000; i++)flag[i] = true;
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
	
	if(n < 1000000)return flag[n];
	for(int i = 0; i < primes.size(); i++){
		if(n % primes[i] == 0)return false;
	}
	return true;
}

int main(){
	
	sievee(1000000);
	
	int n, m;
	while(cin >> n >> m){
		
		int mn = 10000000, mx = -1;
		bool flag = false;
		int p1, p2, x1, x2, x3, x4, dis;
		int cnt = 0;
		
		for(int i = n; i <= m; i++){
			if(primeCheck(i)){
				if(!flag){
					p1 = i;
					flag = true;
				}
				else{
					p2 = i;
					dis = p2 - p1;
					if(dis < mn){
						mn = dis;
						cnt++;
						x1 = p1;
						x2 = p2;
					}
					if(dis > mx){
						mx = dis;
						cnt++;
						x3 = p1;
						x4 = p2;
					}
					p1 = p2;
				}
			}
		}
		if(cnt == 0)cout << "There are no adjacent primes.\n";
		else cout << x1 << "," << x2 << " are closest, " << x3 << "," << x4 << " are most distant.\n";
	}
	
	
	
	
	
	
	
	
	return 0;
}
