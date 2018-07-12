//4x4 Magic Squares
//Count 4x4 magic squares that use numbers 1-16
//There are 7040 of them total, or 880 distinct ones.
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

/* Indices

0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/

int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

int main()
{
	int count = 0, begin, end;
	begin = clock();
	do
	{
		if(a[0] + a[1] + a[2] + a[3] != 34)
			reverse(a+4, a+16);
		else if(a[4] + a[5] + a[6] + a[7] != 34)
			reverse(a+8, a+16);
		else if(a[8] + a[9] + a[10] + a[11] != 34)
			reverse(a+12, a+16);
		//pre-check back diagonal
		else if(a[3] + a[6] + a[9] != a[0] + a[4] + a[8])
			reverse(a + 12, a + 16);
		else if(a[0] + a[4] + a[8] + a[12] != 34)
			reverse(a+13, a+16);
		else if(a[3] + a[6] + a[9] + a[12] != 34)
			reverse(a+13, a+16);
		else if(a[1] + a[5] + a[9] + a[13] != 34)
			reverse(a+14, a+16);
		else if(
				a[2] + a[6] + a[10] + a[14] == 34 &&
				a[0] + a[5] + a[10] + a[15] == 34
			   )
			count++;
	}while(next_permutation(a, a+16));
	end = clock();

	cout << "Count: " << count << endl;
	cout << "Time : " << end - begin  << endl;

	system("pause");
	return 0;
}


