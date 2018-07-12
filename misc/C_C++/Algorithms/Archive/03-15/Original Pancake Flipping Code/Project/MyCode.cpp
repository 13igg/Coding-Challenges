//Pancake Flipping Problem

/*Given an array of relative pancake sizes stored in a[1]..a[n],
a sequence of flips by spatula positions will order the pancakes.
For example, given pancakes of sizes 5,2,4,3,1,6 stored in 
an array starting at index 1, the flip sequence 1,2,4,3,5
would transform the original array to 6,5,4,3,2,1.*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//Returns the number of flips given n pancakes in a[1]..a[n].
int num_flips(int a[], int n)
{
	//Create a copy of the pancake array a:
	int* stack = new int[n+1];				//Ignore the zero spot.
	for(int i = 0; i <= n; i++)
		stack[i] = a[i];
	int num_flips = 0;

	//Starting from the bottom of the stack, position each pancake.
	for(int pos = 1; pos <= n; pos++)
	{
		//The size of the next biggest pancake, which must go into index pos
		int big_size = n + 1 - pos;

		if(stack[pos] == big_size)	//The next biggest pancake is correctly positioned
			continue;

		//If the next biggest pancake is not on top, put it there..
		if(stack[n] != big_size)
		{
			int big_pos = pos;
			while( stack[++big_pos] != big_size );

			reverse( stack + big_pos, stack + n + 1);
			num_flips++;
		}

		//Now flip the next biggest pancake to the correct index pos..
		reverse( stack + pos, stack + n + 1);
		num_flips++;
	}
	delete[] stack;
	return num_flips;
}

int main()
{
	const int n = 10;	//Number of pancakes
	int pancakes[n+1];	//We ignore the first position
	for(int i = 1; i <= n; i++)
		pancakes[i] = i;

	int worst = 0;		//Worst case with naive algorithm

	do
	{
		int value = num_flips(pancakes, n);
		if(value > worst)
			worst = value;
		
	}while( next_permutation( pancakes + 1, pancakes + n + 1 ));

	cout << worst << endl;

	system("pause");
	return 0;
}


