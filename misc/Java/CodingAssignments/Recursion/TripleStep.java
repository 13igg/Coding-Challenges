package Recursion;

import java.util.Arrays;
//starting from the back
// n-1 + n-2 + n-2
//recursion
//DO IT LIKE THAT FIRST
//Then, add the memorization after

public class TripleStep {
	public TripleStep(int stairs)
	{
		int[] memorization = new int[stairs+1];
		Arrays.fill(memorization,-1);
		System.out.println(countWays(stairs, memorization));
	}
	private int countWays(int stairs, int[] memorization)
	{
		if(stairs < 0)
			return 0;
		if(stairs == 0)
			return 1;
		if(memorization[stairs] != -1)
			return memorization[stairs];
		memorization[stairs] = countWays(stairs-1, memorization) + countWays(stairs-2,memorization) + countWays(stairs-3,memorization);
		return memorization[stairs];
	}
}
