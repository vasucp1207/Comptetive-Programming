import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in); 
		BigInteger n;
		BigInteger x = new BigInteger("17");
		
		while(true){
			
			n = sc.nextBigInteger();
			int a = n.intValue();
			if(a == 0)break;
			
			BigInteger num = n.mod(x);
			if(num == BigInteger.ZERO)
				System.out.println(1);
			else
				System.out.println(0);
		}
	}
}
