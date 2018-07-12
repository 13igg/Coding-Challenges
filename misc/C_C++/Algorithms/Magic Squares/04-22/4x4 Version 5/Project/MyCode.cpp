//4x4 Magic Squares
//Count 4x4 magic squares that use numbers 1-16
//This version will be the baseline for future improvements.
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

/*Indices
	//0   1   2   3
	//12  4   9   13
	//14  7   5   15
	//11  8  10   6
*/

int main()
{
	int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	int count = 0, begin, end;
	begin = clock();
	do
	{
		if(a[0] + a[1] + a[2] + a[3] != 34)		  //row 1
			reverse(a+4, a+16);
		else if(a[0] + a[4] + a[5] + a[6] != 34)  //diagonal
			reverse(a+7, a+16);
		else if(a[1] + a[4] + a[7] + a[8] != 34)  //col 2
			reverse(a+9, a+16);
		else if(a[2] + a[9] + a[5] + a[10] != 34)  //col 3
			reverse(a+11, a+16);
		else if(a[3] + a[9] + a[7] + a[11] != 34)  //back diagonal
			reverse(a+12, a+16);
		else if(a[11] + a[8] + a[10] + a[6] != 34)  //row 4
			reverse(a+12, a+16);
		else if(a[12] + a[4] + a[9] + a[13] != 34)  //row 2
			reverse(a+14, a+16);
		else if(a[0] + a[12] + a[14] + a[11] == 34)  //col 1
			count++;
	}while( next_permutation(a, a+16));
	end = clock();

	cout << "Count: " << count << endl;
	cout << "Time : " << end - begin  << endl;

	system("pause");
	return 0;
}


