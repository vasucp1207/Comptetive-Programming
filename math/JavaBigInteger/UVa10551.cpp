import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in); 
		
		int base;
		BigInteger p, m;

		while(true){

			base = sc.nextInt();
			if(base == 0)break;

			p = sc.nextBigInteger(base);
			m = sc.nextBigInteger(base);

			BigInteger val = p.mod(m);
			String ans = val.toString(base);
			System.out.println(ans);
		}
	}
}
