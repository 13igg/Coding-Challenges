package Recursion;

import java.util.ArrayList;

public class PermutationWithoutDups {
	
	ArrayList<String> getPermsEasy(String str)
	{
		ArrayList<String> result = new ArrayList<String>();
		getPermsEasy("", str, result);
		return result;
	}
	//push prefix down stack
	//prefix will hold a full permutation
	void getPermsEasy(String prefix, String remainder, ArrayList<String> result)
	{
		if(remainder.length()==0) result.add(prefix);
		
		int len = remainder.length();
		for(int i = 0; i < len; i++)
		{
			String before = remainder.substring(0,i);
			String after = remainder.substring(i+1, len);
			char c = remainder.charAt(i);
			getPermsEasy(prefix+c, before + after, result);
		}
	}
	
	
	//*****************************************************************	
	ArrayList<String> getPerms(String str){
		if(str == null) return null;
		ArrayList<String> permutations = new ArrayList<String>();
		
		//base case
		if(str.length() == 0){
			permutations.add("");
			return permutations;
		}
		
		char first = str.charAt(0);
		String remainder = str.substring(1);
		ArrayList<String> words = getPerms(remainder);
		for(String word : words)
		{
			for(int i = 0; i < word.length(); i++){
				String s = insertCharAt(word,first,i);
				permutations.add(s);
			}
		}
		return permutations;
	}
	
	String insertCharAt(String word, char c, int i)
	{
		String start = word.substring(0,i);
		String end = word.substring(i);
		return start + c + end;
	}
}
