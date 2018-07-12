package Recursion;

public class RecursiveMultiply {
	//simple count every square
	public int multiply(int a, int b)
	{
		if(b == 0)
			return 0;
		if(b>0)
			return (a + multiply(a, b-1));
		return -multiply(a,-b);	//for negatives
	}
	
	//grab the smaller 
	public int minProducts(int a, int b){
		int large = a<b?b:a;
		int small = a<b?a:b;
		return minProductHelper(small,large);
	}
	
	//take half the squares, double it
	//recurse, take half the squares, double it
	//recurse, take half the squares, double it
	//if odd -> double it + larger
	private int minProductHelper(int a, int b)
	{
		if(a == 0)
			return 0;
		else if(a == 1)
			return b;
		
		int s = a >> 1; //divide by 2
		int half = minProductHelper(s, b);
		 
		if(a % 2 == 0)
			return half + half;
		else 
			return half + half + b;
	}
}
