#include <bits/stdc++.h>

using namespace std;

vector<bool> flag(1000005);
vector<int> primes;

void sievee(int upperbound){
	
	for(int i = 0; i < 1000004; i++)flag[i] = true;
	flag[0] = flag[1] = false;
	
	for(int i = 2; i < sqrt(upperbound); i++){
		if(flag[i]){
			for(int j = i * i; j < upperbound; j += i)
				flag[j] = false;
			primes.push_back(i);
		}
	}
}

int main(){
	
	sievee(1000005);
	
	int t;
	cin >> t;
	
	while(t--){
		int l, u;
		cin >> l >> u;
		
		vector<int> v;
		for(int i = l; i <= u; i++)
			if(primes[i])v.push_back(i);
			
		if(v.size() < 2)cout << "NO jumping champion" << endl;
		
		else{
			vector<int> diff(1000, 0);
			for(int i = 0; i < v.size(); i++){
				diff[v[i + 1] - v[i]]++;
			}
					
			int maxn = 0;
			bool flag = true;
			for(int i = 1; i < 1000; i++){
				if(diff[i] > diff[maxn]) maxn = i;
			}
			
			int counter = 0;
			for(int i = 1; i < 1000; i++){
				if(diff[i] == diff[maxn])counter++;
				if(counter >= 2){
					flag = false;
					break;
				}
			}
			
			if(flag == false)cout << "No jumping champion" << endl;
			else cout << "The jumping champion is " << maxn << endl;
		}
	}
	
	
	
	
	
	
	
	
	return 0;
}
