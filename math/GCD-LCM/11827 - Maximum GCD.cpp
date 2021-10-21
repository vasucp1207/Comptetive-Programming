#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());} 

int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x, int y){return x * (y / gcd(x, y));}

int main(){

	int t;
	cin >> t;
	
	while(t--){
		
		string s;
		getline(cin, s);
		stringstream str(s);
		
		int n = 0;
		int num[101] = {0};
		while(str >> num[n])
			n++;
			
		int ans = 0;
		for(int i = 0; i < n; i++)
			for(int j = i + 1; j < n; j++)
				ans = max(ans, gcd(num[i], num[j]));
				
		cout << ans << endl;
	}


return 0;
}
