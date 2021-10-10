import java.util.Scanner;
import java.math.BigInteger;

class Main{
	public static void main(String[] args){
		
		Scanner sc = new Scanner(System.in);
		
		int n;
		BigInteger a = BigInteger.ZERO;
		
		while(sc.hasNext()){
			BigInteger sum = BigInteger.ZERO;
			n = sc.nextInt();
			a = sc.nextBigInteger();
			
			for(int i = 1; i <= n; i++){
				BigInteger temp = a.pow(i);
				temp = temp.multiply(new BigInteger(Integer.toString(i)));
				sum = sum.add(temp);
			}
			System.out.println(sum);
		}
	}
}
