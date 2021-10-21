/*
ID: vasucp11
TASK: ride
LANG: C++
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

	ofstream fout ("ride.out");
	ifstream fin ("ride.in");

	string c;
	string g;
	fin >> c;
	fin >> g;
	
	int x = 1, y = 1;
	for(int i = 0; i < c.size(); i++) x *= ((c[i] - 'A') + 1);
	for(int i = 0; i < g.size(); i++) y *= ((g[i] - 'A') + 1);
	
	if(x % 47 == y % 47)fout << "GO" << endl;
	else fout << "STAY" << endl;
	


return 0;
}

