//Count 4x4 Magic Squares
//This version fills rows with combinations that sum to 34.
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

int do_row1();
int do_row2();
int do_row3();
int do_end();

/*Indices
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/
int main()
{
  	int begin = clock(), end;
	int count = do_row1();
	end = clock();

	cout << "Count: " << count << endl;
	cout << "Time : " << end - begin << endl;
	system("pause");
	return 0;
}
int do_row1()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int h = 0; h <= 12; h++)
	{
		for(int i = h + 1; i <= 13; i++)
		for(int j = i + 1; j <= 14; j++)
		for(int k = j + 1; k <= 15; k++)
		{
			//Check if the corresponding triple of values sums correctly.
			if(a[h] + a[i] + a[j] + a[k] == 34)
			{
				//Swap the values into a[0..3]
				swap(a[0], a[h]);	swap(a[1], a[i]); 
				swap(a[2], a[j]);	swap(a[3], a[k]);
				
				//Generate all 4! orderings of a[0..3]
				for(int p = 1; p <= 24; p++)
				{
					count += do_row2();
					next_permutation(a, a+4);
				}

				//Swap values into original places
				//Note we must reverse the original swapping order.
				swap(a[3], a[k]); swap(a[2], a[j]); 
				swap(a[1], a[i]); swap(a[0], a[h]);
			}
		}
	}
	return count;
}
int do_row2()
{
	int count = 0;
	//Generate quadruples of indices from {4..15}
	for(int h = 4; h <= 12; h++)
	for(int i = h + 1; i <= 13; i++)
	for(int j = i + 1; j <= 14; j++)
	for(int k = j + 1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[h] + a[i] + a[j] + a[k] == 34)
		{
			//Swap the values into a[4..7]
			swap(a[4], a[h]);	swap(a[5], a[i]); 
			swap(a[6], a[j]);	swap(a[7], a[k]);
			
			//Generate all 4! orderings of a[4..7]
			for(int p = 1; p <= 24; p++)
			{
				count += do_row3();
				next_permutation(a+4, a+8);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[7], a[k]); swap(a[6], a[j]); 
			swap(a[5], a[i]); swap(a[4], a[h]);
		}
	}
	return count;
}
int do_row3()
{
	int count = 0;
	//Generate quadruples of indices from {8..15}
	for(int h = 8; h <= 12; h++)
	for(int i = h + 1; i <= 13; i++)
	for(int j = i + 1; j <= 14; j++)
	for(int k = j + 1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[h] + a[i] + a[j] + a[k] == 34)
		{

			//Swap the values into a[8..11]
			swap(a[8], a[h]);	swap(a[9], a[i]); 
			swap(a[10], a[j]);	swap(a[11], a[k]);
			
			//Generate all 4! orderings of a[8..11]
			for(int p = 1; p <= 24; p++)
			{
				count += do_end();
				next_permutation(a+8, a+12);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[11], a[k]); swap(a[10], a[j]); 
			swap(a[9], a[i]);  swap(a[8], a[h]);
		}
	}
	return count;
}
/*Indices
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/

int do_end()
{
	int return_value = 0;
	//The following two checks give huge savings
	if(a[0] + a[4] + a[8] != a[3] + a[6] + a[9])
		return 0;
	if(a[0] + a[5] + a[10] != a[3] + a[7] + a[11])
	  return 0;

	//Generate all 4! orderings of a[12..15]
	for(int p = 1; p <= 24; p++)
	{
		if(
		   a[0] + a[4] + a[8] + a[12] == 34 &&		//Column 1
		   a[1] + a[5] + a[9] + a[13] == 34 &&		//Column 2
		   a[2] + a[6] + a[10] + a[14] == 34)		//Column 3
		{
			return_value = 1;
		}
		next_permutation(a+12, a+16);
	}
	return return_value;
}
