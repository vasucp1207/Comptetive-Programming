import math

flag = [1] * 10000000
primes = []

def sieve(upper):
	
	for i in range(2, upper):
	
		if(flag[i]):
			primes.append(i)
			
			for j in range(i * i, upper - 1):
				flag[j] = 0
				
def isPrime(n):
	
	if n < 10000000:
		return flag[n]
		
	for i in primes:
		if n % i == 0:
			return false
			
	return true

def primeFac(n):

	fac = []
	for i in range(2, int(math.sqrt(n))):
		
		while n % i == 0:
			n /= i;
			fac.append(i)
			
		if n != 1:
			fac.append(n)
			
	return fac

sieve(10000000)

for i in range(0, 153):
	
	n = int(input())
	
	if n == 0:
		break;
	
	if isPrime(n):
		print(-1);
		continue
		
	fac = primeFac(n)
	print(fac[len(fac) - 1])
