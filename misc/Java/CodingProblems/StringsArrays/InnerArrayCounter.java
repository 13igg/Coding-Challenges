package StringsArrays;
	public class InnerArrayCounter {	
		int[][]	sumZeroZeroToX; //cache
		int[][] arr; //given array
		int rowCount; 
		int colCount;
		//points are (r,c)
		public void InnerArrayCounter(int[][] arr, int rowCount, int colCount) 
		{
			sumZeroZeroToX = new int[rowCount][colCount];
			this.arr = new int[rowCount][colCount];
			this.arr = arr;
			this.rowCount = rowCount;
			this.colCount = colCount;
			fillCache();
		}
		
		//O(1)       			1      2        1      2
		public int sumInnerSquare(int r1, int r2, int c1, int c2)
		{	
			int totalSum = 0;
			int sumFromZeroZero = sumZeroZeroToX[r2][c2];
			int left = 0;
			int top = 0;
			int intersection = 0;
			
			if(r1 == 0 && c1 == 0)
				return sumFromZeroZero;
			
			if(r1 > 0)
				top = sumZeroZeroToX[r1-1][c2];
			
			if(c1 > 0)
				left = sumZeroZeroToX[r2][c1-1];
			
			if(c1 > 0 && r1 > 0)
				intersection = sumZeroZeroToX[r1-1][c1-1];

			return sumFromZeroZero - top - left + intersection;
			
		}

		//O(R*C)
		private void fillCache()
		{
			for(int r = 0; r < rowCount; r++)
				for(int c = 0; c < colCount; c++)
					{
						int sum = 0;
						for(int row = 0; row <= r; row ++)
							for(int col = 0; col <= c; col++)
								sum += arr[row][col];
						sumZeroZeroToX[r][c] = sum;
					}				
		}
}
