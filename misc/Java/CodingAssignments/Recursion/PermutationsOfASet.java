package Recursion;

import java.util.ArrayList;

//break out the first character
//add the next character to a copy of it
//2^n subset
//
public class PermutationsOfASet {
	public ArrayList<ArrayList<Integer>> getSubsets(ArrayList<Integer> set, int index)
	{
		ArrayList<ArrayList<Integer>> allsubsets;
		if(set.size() == index) 
		{//base case empty set
			allsubsets = new ArrayList<ArrayList<Integer>>();
			allsubsets.add(new ArrayList<Integer>());
		}
		else
		{
			allsubsets = getSubsets(set, index+1);
			int item = set.get(index);
			ArrayList<ArrayList<Integer>> moresubsets = new ArrayList<ArrayList<Integer>>();
			for(ArrayList<Integer> subset : allsubsets)
				{
					ArrayList<Integer> newsubset = new ArrayList<Integer>();
					newsubset.addAll(subset);
					newsubset.add(item);
					moresubsets.add(newsubset);
				}
			allsubsets.addAll(moresubsets);						
		}
		return allsubsets;
	}
}
/*
hello

h
{}
h

he
{}
h
e
he


hel
{}
h
e
he
l
hl
el
hel*/