package StringsArrays;
//loop through each keeping count of consequetive
//while its same char
//append the character then the count, 
//reset the count
//
public class StringCompression {
	public String compress(String s)
	{
		int consecCount = 0;
		StringBuilder compressed = new StringBuilder();
		
		for(int i = 0; i < s.length(); i ++)
		{
			consecCount ++;
			if (i + 1 >= s.length() || s.charAt(i) != s.charAt(i+1))
			{
				compressed.append(s.charAt(i));
				compressed.append(consecCount);
				consecCount = 0;
			}
		}
				
		return compressed.length() < s.length() ? compressed.toString() : s;
	}
}
