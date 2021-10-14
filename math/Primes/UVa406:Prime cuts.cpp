#include<algorithm>
#include<bitset>
#include<cstdio>
#include<vector>
 
using namespace std;
 
int N, C;
bitset<10000010> bs;
vector<int> primes;
 
void sieve(long long upper_bound) {
    bs.set();
    bs[0] = bs[1] = 0;
    primes.push_back(1);
    for(long long i = 2; i <= upper_bound + 1; i++) {
        if(bs[i]) {
            for(long long j = i * i; j <= upper_bound + 1; j += i)
                bs[j] = 0;
            primes.push_back((int) i);
        }
    }
}
 
int main() {
    sieve(1000);
    while(scanf("%d %d", &N, &C) == 2) {
        int i = lower_bound(primes.begin(), primes.end(), N) - primes.begin();
        while(i >= primes.size() || primes[i] > N) i--;
 
        i++; // increment index to represent size
        int c = (i % 2)? C * 2 - 1 : C * 2; // get size of printed list
 
        int s = (i - c) > 0? (i - c) / 2 : 0; // calc start index
        int e = (i - c) > 0? s + c : i; // calc end index
 
        printf("%d %d:", N, C);
        for(int j = s; j < e; j++)
            printf(" %d", primes[j]);
        printf("\n\n");
    }
}
