package StringsArrays;
//what is a difference?
//replace
//insert
//replace:
//loop through each char: if there are 2 diffs,  break 
//insert:
//two indexes, one on each string
//loop through each char: if they are both the same, increment both indexes
//if they are different, increment the longer string
//O(n)
public class OneAway {
	public boolean isOneAway(String one, String two)
	{
		if(one.length() == two.length())
			return oneEditReplace(one,two);
		else if(one.length() + 1 == two.length())
			return oneEditInsert(one,two);
		else if(one.length()- 1 == two.length())
			return oneEditInsert(two,one);
		return false;
	}
	
	//check each character, if one is different and different is true, break (2 diffs)
	boolean oneEditReplace(String s1, String s2)
	{
		boolean foundDifference = false;
		for(int i = 0; i < s1.length(); i ++)
			if(s1.charAt(i) != s2.charAt(i)){
				if(foundDifference) 
					return false;
				else
					foundDifference = true;
			}
		return true;
	}
	
	boolean oneEditInsert(String s1, String s2)
	{
		int index1 = 0;
		int index2 = 0;

		while(index2 < s2.length() && index1 < s1.length())
			if(s1.charAt(index1) != s2.charAt(index2)){
				if(index1 != index2)
					return false;				
				index2 ++; 
			}
			else
			{
				index1++;
				index2++;
			}
		
		return true;
	}
}
