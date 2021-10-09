/*UVa 10925 - Krakovia*/
/*UVa 10551 - Basic Remains*/
/*UVa 10814 - Simplifying Fractions */
/*UVa 1230 - MODEX*/


import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		int caseNo = 1;
		
		while(true){
			int n = sc.nextInt();
			int f = sc.nextInt();
			
			if(n == 0 && f == 0)break;
			
			BigInteger sum = BigInteger.ZERO;
			for(int i = 0; i < n; i++){
				BigInteger x = sc.nextBigInteger();
				sum = sum.add(x);
			}
			
			System.out.println("Bill #" + (caseNo++) + " costs " + sum + ": each friend should pay " + sum.divide(BigInteger.valueOf(f)));
			System.out.println();
		}	
	}
}

class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int b = sc.nextInt();
			if(b == 0)break;
			
			BigInteger p = sc.nextBigInteger(b);
			BigInteger m = sc.nextBigInteger(b); 
			System.out.println((p.mod(m)).toString(b));
		}	
	}
}

class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		int t = sc.nextInt();
		for(int i = 0; i < t; i++){
			BigInteger p = sc.nextBigInteger();
			String ch = sc.next();
			BigInteger q = sc.nextBigInteger();
			
			BigInteger gcd = p.gcd(q);
			
			System.out.println(p.divide(gcd) + " / " + q.divide(gcd));
		}	
	}
}

class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		
		for(int i = 0; i < n; i++){
			BigInteger x = sc.nextBigInteger();
			BigInteger y = sc.nextBigInteger();
			BigInteger m = sc.nextBigInteger();
			
			System.out.println(x.modPow(y, m));
		}
	}
}
