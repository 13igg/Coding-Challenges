package StringsArrays;

import java.util.HashMap;
//Create a dictionary as a HashMap
//O(1) to get the freq
//
//
public class WordFreq {
	public HashMap<String,Integer> createDict(String[] book)
	{
		HashMap<String,Integer> dict = new HashMap<String,Integer>();
		for(String word : book)
		{
			if(!dict.containsKey(word)){
				dict.put(word,  0);
			}
			dict.put(word, dict.get(word) + 1);
		}
		return dict;
	}
	
	public int getFrequency(HashMap<String,Integer> dict, String word)
	{
		if(dict == null || word == null) return -1;
		if(dict.containsKey(word))
			return dict.get(word);
		return 0;
	}
}
