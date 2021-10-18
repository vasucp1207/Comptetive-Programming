# An efficient approach is to use prime factorization method with the help of Sieve of Eratosthenes.
# First of all we will find the smallest prime divisor of all elements by pre-computed sieve.
# After that we will mark all the prime divisor of every element of arr[] by factorizing it 
# with the help of pre-computed prime[] array. Now we have all the marked 
# primes occurring in all the array elements. The last step is to find the maximum count of all such prime factors. 

# Time complexity: O( n*log(max(arr[i])) ) + MAX*log(log(MAX)) 
# Auxiliary space: O(MAX)

import math as mt

maxn = 100005

prime = [0] * maxn   
# prime for storing smallest prime divisor of an element
countdiv = [0] * maxn
# countdiv for storing the number of times a particular divisor occurs in a subsequence

def sieve():
	
	for i in range(2, mt.ceil(mt.sqrt(maxn))):
		
		if prime[i] == 0:
			for j in range(i * i, maxn, i):
				prime[j] = i
				
	# Prime number will have same divisor as itself
	for i in range(1, maxn):
		if prime[i] == 0:
			prime[i] = i
			
def largestGCD(arr, n):
	
	ans = 0
	for i in range(n):
		
		ele = arr[i]
		
		while ele > 1:
			div = prime[ele]
			
			countdiv[div] += 1
			ans = max(ans, countdiv[div])
			
			while ele % div == 0:
				ele = ele // div;		
			
	return ans
	
# Driver's code

sieve()

arr = []
n = int(input())
for i in range(0, n):
	
	x = int(input())
	arr.append(x)
	
print(largestGCD(arr, len(arr)))	
