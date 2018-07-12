//Kaprekar Routine
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Given an n-digit number n, what is the next number in the 
sequence obtained by applying Kaprekar's routine to n*/
int next( int n, int num_digits )
{
	//Extract the digits into a vector
	vector<int> digits(num_digits);
	for(int i = 0; n > 0; i++)
	{
		digits[i] = n % 10;
		n = n / 10;
	}

	//Determine the lowest number made from those digits
	int lo;
	sort( digits.begin(), digits.end() );
	lo = digits[0];
	for(int i = 1; i < digits.size(); i++)
		lo = 10 * lo + digits[i];

	//Determine the highest number made from those digits
	int hi;
	reverse( digits.begin(), digits.end() );
	hi = digits[0];
	for(int i = 1; i < digits.size(); i++)
		hi = 10 * hi + digits[i];

	return hi - lo;
}

const int N = 4;
int main()
{
	/*The only way to finish this loop is for every number 4 digit
	  number whose digits are not all the same to have a sequence
	  ending at 6174.*/
	for(int n = 1; n < 10000; n++)
	{
		if(n % 1111 == 0)
			continue;
		for(int i = 1; i != 6174; )
			i = next(i, N);
	}
	system("pause");
	return 0;
}


