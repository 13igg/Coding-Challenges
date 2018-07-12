//Euler Problem 14
/*The following iterative sequence is defined for the set of positive integers:

  n  -> n/2 (n is even)
  n  -> 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

  13  40  20  10  5  16  8  4  2  1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. 
Although it has not been proved yet (Collatz Problem), 
it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?*/

#include <iostream>
using namespace std;

int main()
{
	int longest = 0;		//The length of the longest chain
	int max_start = 0;		//The starting value of the longest chain

	//use these for problem 1
	long long largestKvalue = 2; 
	int largestKnValue = 2; 
	for(int n = 2; n <= 1000000; n++)
	{
		long long k = n;	//Make a working copy
		int this_terms = 0;	//Number of terms in this particular sequence
			cout<<n<<": ";
		while(k != 1)
		{
			this_terms++;
			if(k % 2 == 0)
				k = k / 2;
			else
			{
				if( k > (_I64_MAX - 1) / 3)		//Test for overflow
				{
					cout << "Overflow: " << k << ' ' << n << endl;
					system("pause");
					break;
				}
				k = 3 * k + 1;

				//added this statement for post exploration excercise 1
				if(k >= largestKvalue)
				{
					largestKvalue = k;
					largestKnValue = n;
				}
			}
			cout<<k<< " "; 
		}
			cout<<endl;

		if(this_terms > longest)
		{
			longest = this_terms;
			max_start = n;
		}
		//added this check for post exploration excercise 1
		if(this_terms == longest && largestKnValue != n)
		{
			longest = this_terms;
			max_start = n;
			cout<<"n: " <<n<< endl;
			break;
		}
	}
	cout << "Longest chain: " << longest << endl;
	cout << "Starts at: " << max_start << endl;
	
	cout << endl<< "largest value: " << largestKvalue << endl;
	cout << "Starts at: " << largestKnValue << endl;
	

	system("pause");
	return 0;
}


