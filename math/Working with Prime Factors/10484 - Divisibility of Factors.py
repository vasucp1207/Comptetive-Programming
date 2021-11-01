import sys

def prime_pow_fac(n, p):
	
	ret = 0
	
	while n:
		n //= p
		ret += n
	
	return ret

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97] 

def cnt_fac_divD(n, d):
	
	ret = 1
	for p in primes:
		q = prime_pow_fac(n, p)
		r = 0
		
		while d % p == 0:
			r += 1
			d /= p
		
		if r > q:
			ret = 0
			break
			
		ret *= (q - r + 1)
	if d != 1: ret = 0
		
	return ret

while True:	
	n, d = map(int, input().split())

	if n == 0 and d == 0:
		sys.exit()
		
	ans = cnt_fac_divD(n, d)
	print(ans)
