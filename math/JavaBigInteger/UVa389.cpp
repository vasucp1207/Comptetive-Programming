import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
	
		Scanner sc = new Scanner(System.in); 
		
		BigInteger n;
		int base, to_base;

		while(sc.hasNext()){

			String s = sc.next();
			base = sc.nextInt();
			to_base = sc.nextInt();

			n = new BigInteger(s, base);

			String val = n.toString(to_base);
			if(val.length() > 7){
				System.out.println("  ERROR");
				continue;
			}
			
			for(int i = 0; i < 7 - val.length(); i++)System.out.print(" ");
				System.out.println(val.toUpperCase());
		}
	}
}
