package StringsArrays;

public class RotateSquare {
	public boolean Rotate(int matrix[][])
	{
		if(matrix.length != matrix[0].length || matrix.length == 0)
		{
			return false;
		}

		int n = matrix.length;
		for(int layer = 0; layer < n / 2; layer ++)
		{
			int left = layer;  // 0
			int right = n - 1 - left; //3
			for(int i = left; i < right; i ++)
			{
				//do swapping
				int temp = matrix[left][i];
				int offset = i - left;
				
				//top -> left
				matrix[left][i] = matrix[right-offset][left];				
			
				//left -> bottom
	 			matrix[right-offset][left] = matrix[right][right-offset];

				//bottom -> right
				matrix[right][right-offset] = matrix[i][right];

				//right -> temp
				matrix[i][right] = temp;
			}	
		}	
		return true;
	}
}

		
		
		
		
		
		
		
		
		
		










