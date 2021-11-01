// CPP program to find the number of trailing
// zeroes in base B representation of N!
#include <bits/stdc++.h>
using namespace std;

int getDigits(int n, int b){
	
	double d = 0;
	if(n <= 1) return n;
	
	for(int i = 1; i <= n; i++){
		d += (log10(i) / log10(b));
	}
	
	return floor(d) + 1;
}

// To find the power of a prime p in
// factorial N
int findPowerOfP(int N, int p)
{
	int count = 0;
	int r = p;
	while (r <= N) {

		// calculating floor(n/r)
		// and adding to the count
		count += (N / r);

		// increasing the power of p
		// from 1 to 2 to 3 and so on
		r = r * p;
	}
	return count;
}

// returns all the prime factors of k
vector<pair<int, int> > primeFactorsofB(int B)
{
	// vector to store all the prime factors
	// along with their number of occurrence
	// in factorization of B
	vector<pair<int, int> > ans;

	for (int i = 2; B != 1; i++) {
		if (B % i == 0) {
			int count = 0;
			while (B % i == 0) {
				B = B / i;
				count++;
			}

			ans.push_back(make_pair(i, count));
		}
	}
	return ans;
}

// Returns largest power of B that
// divides N!
int largestPowerOfB(int N, int B)
{
	vector<pair<int, int> > vec;
	vec = primeFactorsofB(B);
	int ans = INT_MAX;
	for (int i = 0; i < vec.size(); i++)

		// calculating minimum power of all
		// the prime factors of B
		ans = min(ans, findPowerOfP(N,
									vec[i].first)
						/ vec[i].second);

	return ans;
}

// Driver code
int main()
{
	int n, b;
	
	while(cin >> n >> b){
		
		cout << largestPowerOfB(n, b) << " ";
		cout << getDigits(n, b) << endl;
	}
	return 0;
}
