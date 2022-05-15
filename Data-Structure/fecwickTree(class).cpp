#include<bits/stdc++.h>

using namespace std;

class FenwickTree{
	
private:
	vector<int> ft;
	
public:
	FenwickTree(int n){
		ft.assign(n + 1, 0);
	}
	
	int rsq(int b){
		int sum = 0;
		for(; b; b -= b & -b) sum += ft[b];
		return sum;
	}
	
	int rsq(int a, int b){
		return rsq(b) - (a == 1? 0: rsq(a - 1));
	}
	
	// update value of k-th element by v
	void update(int k, int v){
		for(; k < (int)ft.size(); k += k & -k) ft[k] += v;
	}
};
 
int main() {
	
	int f[] = {2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9};
	FenwickTree ft(10);
	
	for(int i = 0; i < 11; i++){
		ft.update(f[i], 1);
	}
	
	cout << ft.rsq(1, 2) << endl;        // 1
	cout << ft.rsq(1, 6) << endl;        // 7
	cout << ft.rsq(3, 6) << endl;        // 6
	cout << ft.rsq(1, 10) << endl;       // 11
	ft.update(5, 2);
	cout << ft.rsq(1, 10) << endl;       // 13
	

	return 0;
}
