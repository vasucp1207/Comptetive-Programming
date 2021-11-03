/*
ID: vasucp11
TASK: beads
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

string make(string st, int n){
	
	string str = "";
	str += st.substr(n);
	if(n != 0) str += st.substr(0, n);
	
	return str;
}

int cnt(string str){
	
	int sum = 0;
	
	char ch;
	// forward
	for(int i = 0; i < str.size(); i++){
		
		if(str[i] == 'w') sum++;  // if first bead is white
		else{
			ch = str[i];
			for(int j = i; j < str.size(); j++){
				
				if(str[j] == ch || str[j] == 'w') sum++;
				else break;
			}
			break;
		}
	}
	
	// backward
	for(int i = str.size() - 1; i >= 0; i--){
		
		if(str[i] == 'w') sum++;
		else{
			ch = str[i];
			for(int j = i; j >= 0; j--){
				
				if(str[j] == ch || str[j] == 'w') sum++;
				else break;
			}
			break;
		}
	}
	// wwwwwwwwwwwwwwwwww
	// bbbbbbbbbbbbbbbbb
	// rrrrrrrrrrrrrrrr 
	if(sum > str.size()) sum = str.size();
	
	return sum;
}

int main(){

	ofstream fout ("beads.out");
	ifstream fin ("beads.in");
	
	int n;
	fin >> n;
	string neclace;
	fin >> neclace;
	
	int mx = -1;
	
	for(int i = 0; i < neclace.size(); i++){
		
		// try out every position
		string new_str = make(neclace, i);
		
		int m = cnt(new_str);
		if(m > mx) mx = m; 
	}
	
	fout << mx << endl;
	


return 0;
}
