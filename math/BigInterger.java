/*UVa 10925 - Krakovia*/

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
