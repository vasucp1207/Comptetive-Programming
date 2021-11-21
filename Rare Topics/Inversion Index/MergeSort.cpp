#include <bits/stdc++.h>

using namespace std;
#define ll long long

void display(int a[], int n){
	
	for(int i = 0; i < n; i++) cout << a[i] << " ";
	cout << endl;
}

void merge(int a[], int l, int m, int r){
	
	int i, j, k, nl, nr;
	nl = m - l + 1;   // left array size
	nr = r - m;       // right array size
	
	int left[nl], right[nr];
	
	for(i = 0; i < nl; i++){
		left[i] = a[l + i];
	}
	for(i = 0; i < nr; i++){
		right[i] = a[m + 1 + i];
	}
	
	i = j = 0, k = l;
	
	while(i < nl && j < nr){
		if(left[i] <= right[j]){
			a[k] = left[i];
			i++;
		}
		else{
			a[k] = right[j];
			j++;
		}
		k++;
	}
	
	while(i < nl){
		a[k] = left[i];
		i++, k++;
	}
	while(j < nr){
		a[k] = right[j];
		j++; k++;
	}
}

void mergeSort(int a[], int l, int r){
	
	if(l < r){
		int m = l + (r - l) / 2;
		
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a, l, m, r);
	}
}

int main(){
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];
	
	mergeSort(a, 0, n - 1);
	display(a, n);
		
		
	

return 0;
}
