/*
ID: vasucp11
TASK: gift1
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	
	int n;
	fin >> n;
	
	vector<string> name;
	for(int i = 0; i < n; i++){
		string s;
		fin >> s;
		name.push_back(s);
	}
	
	string giver, receiver;
	int money, peoples;
	vector<int> final(n, 0);
	
	for(int i = 0; i < n; i++){
		
		fin >> giver;
		fin >> money >> peoples;
		if(money == 0) continue;
		
		int div = money / peoples;
		for(int j = 0; j < n; j++){
			if(giver == name[j]) final[j] -= (div * peoples);
		}
		
		for(int j = 0; j < peoples; j++){
			fin >> receiver;
			for(int k = 0; k < n; k++){
				if(receiver == name[k]) final[k] += div;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		fout << name[i] << " " << final[i] << endl;
	}
		
	


return 0;
}
