#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
	
	int n;
	cin >> n;
	int a[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
			
	int sum[n][n];
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) sum[i][j] = 0;
		
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++){
			
			if(i == 0 && j == 0) sum[i][j] = a[i][j];
			else if(i == 0) sum[i][j] += sum[i][j - 1] + a[i][j];
			else if(j == 0) sum[i][j] += sum[i - 1][j] + a[i][j];
			else sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
		
	int mx = -10000000;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			for(int k = i; k < n; k++)
				for(int l = j; l < n; l++){
					if(i == 0 && j == 0) mx = max(mx, sum[k][l]);
					else if(i == 0) mx = max(mx, sum[k][l] - sum[k][j - 1]);
					else if(j == 0) mx = max(mx, sum[k][l] - sum[i - 1][l]);
					else mx = max(mx, sum[k][l] - sum[k][j - 1] - sum[i - 1][l] + sum[i - 1][j - 1]);
				}
				
	cout << mx << endl;	

return 0;
}
