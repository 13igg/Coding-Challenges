/*
.if(a[1] + a[2] + a[3] != 33)		  //row 1
			reverse(a+4, a+16);
		else if(a[4] + a[5] + a[6] != 33)  //diagonal
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
		else if(a[12] + a[14] + a[11] == 33)  //col 1
			count++;
*/
/*
*********
*********
**************
*************
***********
*********
********
*****
************
****
****              THIS IS WITH 1 HARDCODED IN THE EDGES!!!!!!!
***
***/
//Count 4x4 Magic Squares
//This version fills rows with combinations that sum to 34.
#include <iostream>
#include <ctime>
#include <algorithm>
using namespace std;

//int a[16] = {1,2,3,4,13,5,10,14,15,8,6,16,12,9,11,7};
int a[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};


int c_do_row1();
int c_do_diag1();
int c_do_col2();
int c_do_col3();
int c_do_backDiag();
int c_do_end();

int do_row1();
int do_diag1();
int do_col2();
int do_col3();
int do_backDiag();
int do_end();

/*
	//0   1   2   3
	//12  4   9   13
	//14  7   5   15
	//11  8  10   6

Indices
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
	int y,q;
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int h = 0; h <= 12; h++)
	for(int i = h + 1; i <= 13; i++)
	for(int j = i + 1; j <= 14; j++)
	for(int k = j + 1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[h] + a[i] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[0], a[h]);	swap(a[1], a[i]); 
			swap(a[2], a[j]);	swap(a[3], a[k]);
				
			//Generate all 4! orderings of a[0..3]
			for(int p = 1; p <= 24; p++)
			{
				count += do_diag1();
				//next_permutation(a, a+4);
				 	for(y = 2; y >=0 && (a[y] > a[y+1]); y --);
					if(y != -1)
					{				
						for(q = 3; (a[q] < a[y]); q --);
						swap(a[y],a[q]);
						reverse(a+y+1,a+4);
					}
					else				
						reverse(a+y+1,a+4);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[3], a[k]); swap(a[2], a[j]); 
			swap(a[1], a[i]); swap(a[0], a[h]);
		}
	}

	return count;
}


	//0   1   2   3
	//12  4   9   13
	//14  7   5   15
	//11  8  10   6

int do_diag1()
{
	int count = 0,y,q;
	//Generate quadruples of indices from {0..15}
	for(int i = 4; i <= 13; i++)
	for(int j = i+1; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[0] + a[i] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[4], a[i]); 
			swap(a[5], a[j]);	swap(a[6], a[k]);
				
			//Generate all 3! orderings of a[0..3]
			for(int p = 1; p <= 6; p++)
			{
				count += do_col2();
				next_permutation(a+4, a+7);
				 	/*for(y = 5; y >=5 && (a[y] > a[y+1]); y --);
					if(y != 3)
					{				
						for(q = 6; (a[q] < a[y]); q --);
						swap(a[y],a[q]);
						reverse(a+y+3,a+6);
					}
					else				
						reverse(a+y+3,a+6);*/
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[6], a[k]); swap(a[5], a[j]); 
			swap(a[4], a[i]);
		}
	}

	return count;
}

int do_col2()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int j = 7; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[1] + a[4] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[7], a[j]);	swap(a[8], a[k]);
				
			//Generate all 2! orderings of a[0..3]
			for(int p = 1; p <= 2; p++)
			{
				count += do_col3();
				swap(a[7],a[8]);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[8], a[k]); swap(a[7], a[j]);
		}
	}

	return count;
}

int do_col3()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int j = 9; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[2] + a[5] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[9], a[j]);	swap(a[10], a[k]);
				
			//Generate all 2! orderings of a[0..3]
			for(int p = 1; p <= 2; p++)
			{
				count += do_backDiag();
				swap(a[9],a[10]);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[10], a[k]); swap(a[9], a[j]);
		}
	}

	return count;
}

int do_backDiag()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int k = 11; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[3] + a[9] + a[7] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
		    swap(a[11], a[k]);
				
	//0   1   2   3
	//12  4   9   13
	//14  7   5   15
	//11  8  10   6

			//PRECHECKS
	
	if(a[0] + a[12] + a[14] == a[7] + a[3] + a[9])
		count += do_end();
	if(a[3] + a[15] + a[13] != a[0] + a[4] + a[5])
		count += do_end();

				

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[11], a[k]);
		}
	}

	return count;
}


/*Indices
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/


	//c1
	//c4
	//r2
	//r4
	//12-16;

int do_end()
{
	int return_value = 0;
	//The following two checks give huge savings
	//

	//Generate all 4! orderings of a[12..15]
	for(int p = 1; p <= 24; p++)
	{
		if(
		   a[0] + a[12] + a[14] + a[11] == 34 &&		//Column 1
		   a[3] + a[13] + a[15] + a[6] == 34 &&		//Column 4
		   a[12] + a[4] + a[9] + a[13] == 34 &&		//row 2 		   
		   a[14] + a[7] + a[5] + a[15] == 34)		//row 3
		{
			return_value += 1;
		}
		next_permutation(a+12, a+16);
	}
	return return_value;
}





/*
*********
*********
**************
*************
***********
*********
********
*****
************
****
****              THIS IS WITH 1 HARDCODED IN THE CORNERS!!!!!!!
***
***/
int c_do_row1()
{
	int y,q;
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int i = 0; i <= 13; i++)
	for(int j = i + 1; j <= 14; j++)
	for(int k = j + 1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[i] + a[j] + a[k] == 33)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[1], a[i]); 
			swap(a[2], a[j]);	swap(a[3], a[k]);
				
			//Generate all 4! orderings of a[0..3]
			for(int p = 1; p <= 24; p++)
			{
				count += c_do_diag1();
				//next_permutation(a, a+4);
				 	for(y = 2; y >=0 && (a[y] > a[y+1]); y --);
					if(y != -1)
					{				
						for(q = 3; (a[q] < a[y]); q --);
						swap(a[y],a[q]);
						reverse(a+y+1,a+4);
					}
					else				
						reverse(a+y+1,a+4);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[3], a[k]); swap(a[2], a[j]); 
			swap(a[1], a[i]); 
		}
	}

	return count;
}


	//0   1   2   3
	//12  4   9   13
	//14  7   5   15
	//11  8  10   6

int c_do_diag1()
{
	int count = 0,y,q;
	//Generate quadruples of indices from {0..15}
	for(int i = 4; i <= 13; i++)
	for(int j = i+1; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[0] + a[i] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[4], a[i]); 
			swap(a[5], a[j]);	swap(a[6], a[k]);
				
			//Generate all 3! orderings of a[0..3]
			for(int p = 1; p <= 6; p++)
			{
				count += c_do_col2();
				next_permutation(a+4, a+7);
				 	/*for(y = 5; y >=5 && (a[y] > a[y+1]); y --);
					if(y != 3)
					{				
						for(q = 6; (a[q] < a[y]); q --);
						swap(a[y],a[q]);
						reverse(a+y+3,a+6);
					}
					else				
						reverse(a+y+3,a+6);*/
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[6], a[k]); swap(a[5], a[j]); 
			swap(a[4], a[i]);
		}
	}

	return count;
}

int c_do_col2()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int j = 7; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[1] + a[4] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[7], a[j]);	swap(a[8], a[k]);
				
			//Generate all 2! orderings of a[0..3]
			for(int p = 1; p <= 2; p++)
			{
				count += c_do_col3();
				swap(a[7],a[8]);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[8], a[k]); swap(a[7], a[j]);
		}
	}

	return count;
}

int c_do_col3()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int j = 9; j <= 14; j++)
	for(int k = j+1; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[2] + a[5] + a[j] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
			swap(a[9], a[j]);	swap(a[10], a[k]);
				
			//Generate all 2! orderings of a[0..3]
			for(int p = 1; p <= 2; p++)
			{
				count += c_do_backDiag();
				swap(a[9],a[10]);
			}

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[10], a[k]); swap(a[9], a[j]);
		}
	}

	return count;
}

int c_do_backDiag()
{
	int count = 0;
	//Generate quadruples of indices from {0..15}
	for(int k = 11; k <= 15; k++)
	{
		//Check if the corresponding triple of values sums correctly.
		if(a[3] + a[9] + a[7] + a[k] == 34)
		{
				//system("pause");
				//cout<<h<<' ' <<i<<' '<<j<<' '<<k<<endl;		
				//cout<<a[h]<<' ' <<a[i]<<' '<<a[j]<<' '<<a[k]<<endl;
			//Swap the values into a[0..3]
		    swap(a[11], a[k]);
				
			
				count += c_do_end();
				

			//Swap values into original places
			//Note we must reverse the original swapping order.
			swap(a[11], a[k]);
		}
	}

	return count;
}


/*Indices
0  1  2  3
4  5  6  7
8  9  10 11
12 13 14 15*/


	//c1
	//c4
	//r2
	//r4
	//12-16;

int c_do_end()
{
	int return_value = 0;
	//The following two checks give huge savings
	//

	//Generate all 4! orderings of a[12..15]
	for(int p = 1; p <= 24; p++)
	{
		if(
		   a[0] + a[12] + a[14] + a[11] == 34 &&		//Column 1
		   a[3] + a[13] + a[15] + a[6] == 34 &&		//Column 4
		   a[12] + a[4] + a[9] + a[13] == 34 &&		//row 2 		   
		   a[14] + a[7] + a[5] + a[15] == 34)		//row 3
		{
			return_value += 1;
		}
		next_permutation(a+12, a+16);
	}
	return return_value;
}