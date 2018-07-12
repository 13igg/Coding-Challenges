package Random;
//Paint 1 post, k ways
//Paint the next post k - 1
//paint 1 = k
//paint 2 = k * k
//          | last | last 2|
//paint p =  (p-1) + (p-2) * (k-1)
//Total number ^^^^^ is k * (k - 1)
//Add a post, check if previous is same color
//Add a post, check if previous is same color
//if we use a different color, we have k-1 options
//if we use the same color, there is only one option
//
public class FencePainting {
	public int paintFence(int n, int k)
	{
		int first = k;
		int second = k*k;
		if(n==0)return 0;
		if(n==1)return first;
		if(n==2)return second;
		
		int sum = 0;
		for(int i = 3; i <= n; i ++)
		{
			sum = (first+second) * (k-1);
			first = second;
			second = sum;					
		}
		return sum;
	}
}
