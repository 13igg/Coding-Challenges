//The Perfect Pancake Flipping Algorithm

/*Given an array of relative pancake sizes stored in a[1]..a[n],
a sequence of flips by spatula positions will order the pancakes 
from largest to smallest. For example, given pancakes of sizes 
5,2,4,3,1,6 stored in an array starting at index 1, 
the flip sequence 1,2,4,3,5 would transform the original array 
to 6,5,4,3,2,1.*/

/*In this program, we search through all possible flip sequences 
in size order until we find one that works.  By doing this for 
all possible pancake permutations, we find a lower bound on the 
number of flips needed to order any pancake array of size n.*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "arrangement.h"		//Used to generate Tuples of flip sequences
#include <ctime>
using namespace std;
using namespace arr;			//Needed by arrangement library

//Return true if the flip-sequence has consective flips the same
bool has_consecutives(Tuple& t)
{
	for(int i = 1; i < t.size(); i++)
		if(t[i] == t[i-1])
			return true;
	return false;
}
//Return true if a[1]..a[n] are in increasing order
bool is_sorted(int a[], int n)
{
	for(int i = 1; i <= n; i++)
		if(a[i] < a[i-1])
			return false;
	return true;
}

/*This perfect algorithm returns the smallest number of flips 
for a pancake stack stored in a[1]..a[n].  The algorithm
searches through all possible flip sequences in increasing size order.*/
int num_flips(int a[], int n)
{
	if(is_sorted(a,n))
		return 0;
	
	int* stack = new int[n+1];		//Space to create a working copy of a[]

	for(int k = 1; k <= 2*n - 3; k++)	//k is size of flip sequence
	{
		Tuple flip(n-1, k);			//A tuple for the flip sequence
					//We start at [1,1,..,1] and will end at [n-1,n-1,..,n-1]
		
		do
		{
			if(has_consecutives(flip))
				continue;				//This can't be a minimal flip sequence

			//Create a copy of the pancake array a:
			for(int i = 1; i <= n; i++)
				stack[i] = a[i];

			//Apply the flip sequence to the stack of pancakes
			for(int i = 0; i < flip.size(); i++)
				reverse( stack + flip[i], stack + n + 1);

			if(is_sorted(stack, n))
			{
				delete[] stack;
				return flip.size();
			}
		}while(flip.next());	//The next Tuple is the next flip sequence to try
	}
}
int main()
{
	int begin_time = clock();
	int n = 3;							//Number of pancakes
	while(++n)
	{
		//Initialize an array [*,1,2,..,n] of n pancakes
		int* pancakes = new int[n+1];	//We ignore the first position
		for(int i = 1; i <= n; i++)
			pancakes[i] = i;

		int worst = 0;		//Worst case number of flips for n pancakes

		//Step through all possible pancake permutations to find
		//the maximum number of flips needed.
		do
		{
			int value = num_flips(pancakes, n);		//calls the perfect algorithm
			if(value > worst)
				worst = value;
			
		}while( next_permutation( pancakes + 1, pancakes + n + 1 ));

		cout << "Number of pancakes: " << n
			 << " Worst case flips: " << worst
			 << " Elapsed seconds: " 
			 << fixed << setprecision(1)
			 << ((double) clock() - begin_time) / 1000.0 << endl;
		delete[] pancakes;
	}

	system("pause");
	return 0;
}


