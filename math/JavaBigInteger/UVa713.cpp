import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in); 
		
		int t;
		t = sc.nextInt();
		BigInteger a, b;
		
		for(int i = 1; i <= t; i++){
			a = sc.nextBigInteger();
			b = sc.nextBigInteger();
			
			String aa = new StringBuffer(a.toString()).reverse().toString();
			String bb = new StringBuffer(b.toString()).reverse().toString();
			
			BigInteger new_a = new BigInteger(aa);
			BigInteger new_b = new BigInteger(bb);
			
			BigInteger sum = new_a.add(new_b);
			String final_N = new StringBuffer(sum.toString()).reverse().toString();
			BigInteger ans = new BigInteger(final_N);
			
			System.out.println(ans);
		}
	}
}
