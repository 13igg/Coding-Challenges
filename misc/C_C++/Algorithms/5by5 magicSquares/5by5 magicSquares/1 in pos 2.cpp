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
1,  2,  +,  3,  4,
19, 5, 17,  9, 20, 
21, 12,  6, 14, 22,
23, 10, 18,  7, 24,
11, 13, 16, 15,  8*/
int a[25] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25};

int main()
{
	int begin, end, count = 0;
	cout << "5x5 Magic Squares having 1 in pos 2";

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
	int count = 0, s = 1;
	//Generate quadruple of indices from {s..}
	for(int h = s; h <= 21; h++)
	for(int i = h + 1; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	for(int k = j + 1; k <= 24; k++)
	{
		if(a[h] + a[i] + a[j] + a[k] == 64)
		{
			swap(a[s], a[h]);	swap(a[s+1], a[i]); 
			swap(a[s+2], a[j]);	swap(a[s+3], a[k]);
			
			for(int p = 1; p <= 24; p++, next_permutation(a+s, a+s+4))
				count += do_diag();

			swap(a[s+3], a[k]);	swap(a[s+2], a[j]);	
			swap(a[s+1], a[i]); swap(a[s], a[h]);	
		}
	}
	return count;
}
int do_diag()
{
	int count = 0, s = 5;
	//Generate quadruple of indices from {s..}

	for(int h = s; h <= 21; h++)
	for(int i = h + 1; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	for(int k = j + 1; k <= 24; k++)
	{
		if(a[1] + a[h] + a[i] + a[j] + a[k] == 65)
		{
			swap(a[s], a[h]);	swap(a[s+1], a[i]); 
			swap(a[s+2], a[j]);	swap(a[s+3], a[k]);
			
			for(int p = 1; p <= 24; p++, next_permutation(a+s, a+s+4))
				count += do_diag2();

			swap(a[s+3], a[k]);	swap(a[s+2], a[j]);	
			swap(a[s+1], a[i]); swap(a[s], a[h]);	
		}
	}
	return count;
}
int do_diag2()
{
	int count = 0, s = 9;
	//Generate triple of indices from {s..}
	for(int i = s; i <= 22; i++)
	for(int j = i + 1; j <= 23; j++)
	for(int k = j + 1; k <= 24; k++)
		if(a[4] + a[i] + a[6] + a[j] + a[k] == 65)
		{
			swap(a[s], a[i]);	swap(a[s+1], a[j]); 
			swap(a[s+2], a[k]);	

			for(int p = 1; p <= 6; p++, next_permutation(a+s, a+s+3))
				count += do_col2();

			swap(a[s+2], a[k]);
			swap(a[s+1], a[j]);
			swap(a[s], a[i]);	
 		}
	return count;
}
/*Indices
1,  2,  0,  3,  4,
19, 5, 17,  9, 20, 
21, 12,  6, 14, 22,
23, 10, 18,  7, 24,
11, 13, 16, 15,  8*/
int do_col2()
{
	int count = 0, s = 12;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 23; i++)
	for(int j = i + 1; j <= 24; j++)

		if(a[2] + a[5] + a[i] + a[10] + a[j] == 65)
		{
			//Swap values into a[s] & a[s+1] and try both ways
			swap(a[s], a[i]);		swap(a[s+1], a[j]); 

			count += do_col4(); swap(a[s],a[s+1]);
			count += do_col4(); swap(a[s],a[s+1]);	//Back to beginning of cycle

			//Swap values into original places, reversing original swapping order.
			swap(a[s+1], a[j]);	swap(a[s], a[i]);
 		}
	return count;
}

int do_col4()
{
	int count = 0, s = 14;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 23; i++)
	for(int j = i + 1; j <= 24; j++)
	{
		if(a[3] + a[9] + a[i] + a[7] + a[j] == 65)
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
	int count = 0, s = 16;
	int t = 65 - a[11] - a[13] - a[15] - a[8];
	for(int i = s; i <= 24; i++)
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
	int count = 0, s = 17;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 23; i++)
	for(int j = i + 1; j <= 24; j++)
	{
		if(a[i] + a[6] + a[j] + a[16] == 64)
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
	int s = 19;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 23; i++)
	for(int j = i + 1; j <= 24; j++)
	{
		if(a[i] + a[5] + a[17] + a[9] + a[j] == 65)
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
	int s = 21;
	//Generate pair of indices from {s..}
	for(int i = s; i <= 23; i++)
	for(int j = i + 1; j <= 24; j++)
	{
		if(a[i] + a[12] + a[6] + a[14] + a[j] == 65)
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
	if(a[1] + a[19] + a[21] + a[23] + a[11] == 65)
	{
		if(rand()%5000 == 0)
			print();
		return 1;
	}
	if(a[1] + a[19] + a[21] + a[24] + a[11] == 65)
		return 1;
	return 0;
}


//Ouput a magic square
#define W3 setw(3)
void print()
{
	cout << W3 << a[1]  << W3 << a[2]  << W3 << a[0]  << W3 << a[3]  << W3 << a[4]  << endl;
	cout << W3 << a[19] << W3 << a[5]  << W3 << a[17] << W3 << a[9]  << W3 << a[20] << endl;
	cout << W3 << a[21] << W3 << a[12] << W3 << a[6]  << W3 << a[14] << W3 << a[22] << endl;
	cout << W3 << a[23] << W3 << a[10] << W3 << a[18] << W3 << a[7]  << W3 << a[24] << endl;
	cout << W3 << a[11] << W3 << a[13] << W3 << a[16] << W3 << a[15] << W3 << a[8]  << endl;
	cout << endl;
}