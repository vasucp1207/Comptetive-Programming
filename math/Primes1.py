import sys

primes = []
bs = []

def sieve(upperbound):
	
	global sieve_size, bs, primes
	
	bs = [True] * 10000005
	bs[0] = bs[1] = False
	
	for i in range(2, upperbound):
		if bs[i]:
			for j in range(i * i, upperbound, i):
				bs[j] = False
			primes.append(i)

def isPrime(n):
	
	if n <= 10000005:
		return bs[n]
	
	for i in primes:
		if i * i >= n:
			break
			
		if n % p == 0:
			return False
	
	return True			

sieve(10000005)
#for i in range(0, 20, 1):
#	print(primes[i])

# n = int(input(""))
# print(isPrime(n))












