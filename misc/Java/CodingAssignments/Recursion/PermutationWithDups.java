package Recursion;
import java.util.HashMap;

public class PermutationWithDups {
	
	HashMap<Character, Integer> freqTable(String s)
	{
		HashMap<Character, Integer> map = new HashMap<Character, Integer>();
		for(char c : s.toCharArray())
		{
			if(!map.containsKey(c))
				map.put(c, 0);
			map.put(c, map.get(c)+1);
		}
		return map;
	}
}
