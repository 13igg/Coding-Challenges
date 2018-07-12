package StringsArrays;
//O(n)
//A permuation of a palindrome has even count, except for one
//create a hash of characters
//need to getCharNumber for them - do this by getting the numeric values
//loop through each character
//As you are looping, keep count of characters
//everytime you find them, increment one on the hash, 
//it mod 2 == 1, its a new character
// if it mod 2 == 0 it was a duplicate, and --

public class PalindromePermutation {
	public boolean isPermutationOfPalindrome(String phrase)
	{
		int countOdd = 0;
		int[] table = new int[Character.getNumericValue('z') - Character.getNumericValue('a') + 1];
		
		for(char c : phrase.toCharArray())
		{
			int x = getCharNumber(c);
			System.out.println("CharacterNumber: " + x);
			if(x != -1)
			{
				table[x]++;			
				if(table[x] %2 == 1)
					countOdd++;
				else 
					countOdd--;
				System.out.println("OddCount: "+countOdd);
			}
			System.out.println();
		}
		return countOdd <= 1;
	}
	
	int getCharNumber(Character c)
	{
		int a = Character.getNumericValue('a');
		int z = Character.getNumericValue('z');
		int val = Character.getNumericValue(c);
		if(a <= val && val <= z) {
			return val - a;
		}
		return -1;
	}

}

