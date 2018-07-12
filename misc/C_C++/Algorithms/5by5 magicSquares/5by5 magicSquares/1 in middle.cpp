//Count 5x5 Magic Squares having top row 1,2,13,24,25
#include <iostream>
#include <iomanip>
#include <ctime>
#include <algorithm>
using namespace std;

//Order of Function Calls
int do_row1();
int do_diag();
int do_diag2();
int do_col2();
int do_col4();
int do_row5();
int do_col3();
int do_row2();
int do_row3();
int do_col1();
void print();

/*Indices
0,  1,  2,  3,  4,
18, 5, 16,  8, 19, 
20, 11, +, 13, 21,
22, 9, 17,  6, 23,
10, 12, 15, 14,  7
*/
int a[24] = {2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

int main()
{
	int begin, end, count = 0;
	cout << "5x5 Magic Squares having 1 in the center";

	begin = clock();
	count += do_row1();
	end = clock();

	cout <<endl<< "  Count: " << count << endl;
	cout << "  Time : " << end - begin << endl << endl;
	system("pause");
	return 0;
}
int do_row1()
{
	int count = 0, s = 0;
	//Generate quadruple of indices from {s..}
	for(int h = s; h <= 19; h++)
	for(int i = h + 1; i <= 20; i++)
	for(int j = i + 1; j <= 21; j++)
	for(int k = j + 1; k <= 22; k++)
	for(int l = k + 1; l <= 23; l++)
	{
		if(a[l] + a[h] + a[i] + a[j] + a[k] == 65)
			{
				swap(a[s], a[h]);	
				swap(a[s+1], a[i]); 
				swap(a[s+2], a[j]);
				swap(a[s+3], a[k]);
				swap(a[s+4], a[l]);
			
				for(int p = 1; p <= 120; p++, next_permutation(a+s, a+s+5))
					count += do_diag();

	    		swap(a[s+4], a[l]);
				swap(a[s+3], a[k]);	
				swap(a[s+2], a[j]);	
				swap(a[s+1], a[i]);
				swap(a[s], a[h]);	
			}
	}
	return count;
}
int do_diag()
{
	int count = 0, s = 5;
	//Generate quadruple of indices from {s..}

	for(int i = s; i <= 21; i++)
	for(int j = i + 1; j <= 22; j++)
	for(int k = j + 1; k <= 23; k++)
	{
			if(a[0] + a[i] + a[j] + a[k] == 64)
			{
				swap(a[s], a[i]);	
				swap(a[s+1], a[j]); 
				swap(a[s+2], a[k]);	

				for(int p = 1; p <= 6; p++, next_permutation(a+s, a+s+3))
					count += do_diag2();

				swap(a[s+2], a[k]);
				swap(a[s+1], a[j]);
				swap(a[s], a[i]);	
 			}
		}
	return count;
}
int do_diag2()
{
	int count = 0, s = 8;
	//Generate triple of indices from {s..}
	for(int i = s; i <= 21; i++)
	for(int j = i + 1; j <= 22; j++)
	for(int k = j + 1; k <= 23; k++)
		if(a[4] + a[i] + a[j] + a[k] == 64)
		{
			swap(a[s], a[i]);	
			swap(a[s+1], a[j]); 
			swap(a[s+2], a[k]);	

			for(int p = 1; p <= 6; p++, next_permutation(a+s, a+s+3))
				count += do_col2();

			swap(a[s+2], a[k]);
			swap(a[s+1], a[j]);
			swap(a[s], a[i]);	
 		}
	return count;
}
int do_col2()
{
	int count = 0, s = 11;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)

		if(a[1] + a[5] + a[i] + a[9] + a[j] == 65)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_col4(); swap(a[s],a[s+1]);
			count += do_col4(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	   swap(a[s], a[i]);
 		}
	return count;
}

int do_col4()
{
	int count = 0, s = 13;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	{
		if(a[3] + a[8] + a[i] + a[6] + a[j] == 65)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_row5(); swap(a[s],a[s+1]);
			count += do_row5(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	swap(a[s], a[i]);
 		}
	}
	return count;
}
int do_row5()
{
	int count = 0, s = 15;
	int t = 65 - a[10] - a[12] - a[14] - a[7];
	for(int i = s; i <= 23; i++)
	{
		if(a[i] == t)  //meaning a[11] + a[13] + a[i] + a[15] + a[8] == 65
		{
			swap(a[s], a[i]);
			count += do_col3();
			swap(a[s], a[i]);
		}
	}
	return count;
}
int do_col3()
{
	int count = 0, s = 16;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	{
		if(a[2] + a[i] + a[j] + a[15] == 64)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_row2(); swap(a[s],a[s+1]);
			count += do_row2(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	swap(a[s], a[i]);
 		}
	}
	return count;
}
int do_row2()
{
	int count = 0;
	int s = 18;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	{
		if(a[i] + a[5] + a[16] + a[8] + a[j] == 65)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_row3(); swap(a[s],a[s+1]);
			count += do_row3(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	swap(a[s], a[i]);
 		}
	}
	return count;
}
int do_row3()
{
	int count = 0;
	int s = 20;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	{
		if(a[i] + a[11] + a[13] + a[j] == 64)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_col1(); swap(a[s],a[s+1]);
			count += do_col1(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	swap(a[s], a[i]);
 		}
	}
	return count;
}
int do_col1()
{
	if(a[0] + a[18] + a[20] + a[22] + a[10] == 65)
	{
		//if(rand()%1000 == 0)
			//print();
		return 1;
	}
	if(a[0] + a[18] + a[20] + a[23] + a[10] == 65)
		return 1;
	return 0;
}


//Ouput a magic square
#define W3 setw(3)
void print()
{
	cout << W3 << a[0]  << W3 << a[1]  << W3 << a[2]  << W3 << a[3]  << W3 << a[4]  << endl;
	cout << W3 << a[18] << W3 << a[5]  << W3 << a[16] << W3 << a[8]  << W3 << a[19] << endl;
	cout << W3 << a[20] << W3 << a[11] << W3 << "1"  << W3 << a[13] << W3 << a[21] << endl;
	cout << W3 << a[22] << W3 << a[9] << W3 << a[17] << W3 << a[6]  << W3 << a[23] << endl;
	cout << W3 << a[10] << W3 << a[12] << W3 << a[15] << W3 << a[14] << W3 << a[7]  << endl;
	cout << endl;
}