package Recursion;

//USE BINARY SEARCH
//
public class MagicIndex {
	//This is good! but its sorted so there must be an easier way::
	public int magicSlow(int[] arr)
	{
		for(int i = 0; i <arr.length; i++)
			if(arr[i] == i)
				return i;
		return -1;
	}
	
	//Since its sorted, go ahead adn binary search it.
	public int binaryMagicIndex(int[] array, int start, int end)
	{
		if(end < start)	return -1;		
		int mid = (start + end) / 2;
		
		if(array[mid] == mid) return mid;
		else if(array[mid] > mid)
			return binaryMagicIndex(array,start,mid-1);
		else
			return binaryMagicIndex(array, mid+1, end);
	}
//**************************************************************************	
	
	//duplicates
	public int binaryDUPLICATEMagicIndex(int[] array, int start, int end)
	{
		if(end < start)	return -1;	
		int mid = (start + end) / 2;	
		int midVal = array[mid];
		if(midVal == mid)
			return mid;

		int left = Math.min(mid - 1, midVal);
		int leftVal = binaryDUPLICATEMagicIndex(array, start, left);
		if(leftVal >= 0) return left;
		
		
		int right = Math.max(mid+1,  midVal);
		int rightVal = binaryDUPLICATEMagicIndex(array, right, end);
		
		return right;
		//if(midVal < mid)						
		//if(midVal > mid)
		
	}
}
