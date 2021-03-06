//4x4 Magic Squares
//Count 4x4 magic squares that use numbers 1-16
//This version hardwires a 1 into a corner and an edge.
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

/* Indices - with + indicating placement of 1 in a[0]
+  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/

int main()
{
	int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int count = 0, begin, end;
	begin = clock();
	do
	{
		if(a[1] + a[2] + a[3] != 33)							//Row 1
			reverse(a+4, a+16);
		else if(a[4] + a[5] + a[6] + a[7] != 34)				//Row 2
			reverse(a+8, a+16);
		else if(a[8] + a[9] + a[10] + a[11] != 34)				//Row 3
			reverse(a+12, a+16);
		else if(a[3] + a[6] + a[9] + a[12] != 34)				//Back Diagonal
			reverse(a+13, a+16);
		else if(a[4] + a[8] + a[12] != 33)						//Col 1
			reverse(a+13, a+16);
		else if(a[1] + a[5] + a[9] + a[13] != 34)				//Col 2
			reverse(a+14, a+16);
		else if(
				a[2] + a[6] + a[10] + a[14] == 34 &&			//Col 3
				       a[5] + a[10] + a[15] == 33				//Diagonal
			   )
			count++;
	}while(next_permutation(a+1, a+16));

	//Note that a is back to its original order.

/* Indices - with + indicating placement of 1 in a[0]
1  +  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/
	do
	{
		if(a[1] + a[2] + a[3] != 33)							//Row 1
			reverse(a+4, a+16);
		else if(a[4] + a[5] + a[6] + a[7] != 34)				//Row 2
			reverse(a+8, a+16);
		else if(a[8] + a[9] + a[10] + a[11] != 34)				//Row 3
			reverse(a+12, a+16);
		else if(a[3] + a[6] + a[9] + a[12] != 34)				//Back Diagonal
			reverse(a+13, a+16);
		else if(a[1] + a[4] + a[8] + a[12] != 34)				//Col 1
			reverse(a+13, a+16);
		else if(a[5] + a[9] + a[13] != 33)						//Col 2
			reverse(a+14, a+16);
		else if(
				a[2] + a[6] + a[10] + a[14] == 34 &&			//Col 3
				a[1] + a[5] + a[10] + a[15] == 34				//Diagonal
			   )
			count++;
	}while(next_permutation(a+1, a+16));

	end = clock();

	cout << "Count: " << count << endl;
	cout << "Time : " << end - begin  << endl;

	system("pause");
	return 0;
}


