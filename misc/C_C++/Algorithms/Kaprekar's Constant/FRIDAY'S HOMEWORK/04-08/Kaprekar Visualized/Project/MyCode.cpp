//Kaprekar's Routine Visualized
#include "grafix.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*Given a 4-digit number n, what is the next number in the 
sequence obtained by applying Kaprekar's routine to n*/
int next_value( int n )
{
	//Extract the digits into a vector
	vector<int> digits(4);
	for(int i = 0; n > 0; i++)
	{
		digits[i] = n % 10;
		n = n / 10;
	}

	//Determine the lowest number made from those digits
	int lo;
	sort( digits.begin(), digits.end() );
	lo = digits[0];
	for(size_t i = 1; i < digits.size(); i++)
		lo = 10 * lo + digits[i];

	//Determine the highest number made from those digits
	int hi;
	reverse( digits.begin(), digits.end() );
	hi = digits[0];
	for(size_t i = 1; i < digits.size(); i++)
		hi = 10 * hi + digits[i];

	return hi - lo;
}
//How long is the Kaprekar sequence beginning with n.
int length(int n)
{
	int steps = 1;
	while(n != 6174)
	{
		steps++;
		n = next_value(n);
	}
	return steps;
}


int main()
{
	SquareGrid g(MinPt, MaxPt, 100, 100);

	for(int n = 1; n < 10000; n++)
	{
		if(n % 1111 == 0) continue;

		int steps = length(n);

		/*This would set a grayscale:
		set_color(BLACK.light( steps * 12 )); */

		switch(steps)
		{
			case 1: set_color(BLUE); break;
			case 2: set_color(GREEN); break;
			case 3: set_color(RED); break;
			case 4: set_color(PINK); break;
			case 5: set_color(ORANGE); break;
			case 6: set_color(WHITE); break;
			case 7: set_color(SILVER); break;
			case 8: set_color(YELLOW); break;
			default: set_color(GRAY);
		}
		g(n % 100, n / 100).draw_filled();
	}

	return 0;
}