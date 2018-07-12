package Sorting;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;

//ANAGRAMS
//SORT THEM - IF THEY ARE BOTH THE SAME = ANAGRAM
//O(Nlog(N))
public class Anagrams {
	class AnagramComparator implements Comparator<String>
	{
		public String sortChars(String s){
			char[] content = s.toCharArray();
			Arrays.sort(content);
			return new String(content);
		}
		
		void sort(String[] array)
		{
			HashMap<String,String> mapList = new HashMap<String,String>();
			
			for(String s:array){
				String key = sortChars(s);
				mapList.put(key,s);
			}		
			int index = 0;
			for(String key : mapList.keySet()){
				ArrayList<String> list = mapList.get(key);
				for(String t : list){
					array[index] = t;
					index++;
				}
			}
		}
		
		public int compare(String s1, String s2){
			return sortChars(s1).compareTo(sortChars(s2));
		}
	}
	
	
}
