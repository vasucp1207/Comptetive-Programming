#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define f first
#define s second
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

int p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

void solve(int n){
	
	vector<int> a(25, 0);
	int orignal = n;
	
	while(n != 1){
		
		int i = n;
		int j = 0;
		
		while(i != 1){
			
			int cnt = 0;
			while(i % p[j] == 0){
				
				i /= p[j];
				cnt++;
			}
			a[j] += cnt;
			j++;
		}
		n--;
	}
	
	int last;
	int i;
	for(i = 24; i >= 0; i--)
		if(a[i] != 0)break;
		
	last = i;
	
	cout << setw(3) << orignal << "! =";
	
      for(int i = 0; i <= last; i++) {
        if (i > 0 && i % 15 == 0) cout << endl << "      ";
        cout << setw(3) << a[i];
      }
      cout << endl;
   	
}

int main(){
	
	int n;
	while(true){
		
		cin >> n;
		if(n == 0)break;
		
		solve(n);
	}


return 0;
}
