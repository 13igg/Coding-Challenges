//Pancake Flipping Problem
//In this version, we use arrays, making a copy in get_flips.
//We can even improve on this program by allocating stack once outside get_flips.

/*Given a vector of relative pancake sizes stored in v[1]..v[n],
obtain a flip-vector of spatula positions from which to flip.
For example, given pancakes of sizes 5,2,4,3,1,6 stored in 
a vector starting at index 1, the flip-vector 1,2,4,3,5
would transform the original vector to 6,5,4,3,2,1.*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

//Returns the number of flips
int get_flips(int the_stack[], int n)
{
	int* stack = new int[n+1];
	for(int i = 0; i <= n; i++)
		stack[i] = the_stack[i];
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
	return num_flips;		//Return the flip-vector
}

int main()
{
	int begin = clock();
	const int n = 10;	//Number of pancakes
	int pancakes[n+1];	//We ignore the first position
	for(int i = 1; i <= n; i++)
		pancakes[i] = i;
	int worst = 0;

	do
	{
		int value = get_flips(pancakes, n);
		if(value > worst)
			worst = value;
		
	}while( next_permutation( pancakes + 1, pancakes + n + 1 ));
	cout << clock() - begin << endl;

	cout << n << ' ' << worst << endl;

	system("pause");
	return 0;
}


