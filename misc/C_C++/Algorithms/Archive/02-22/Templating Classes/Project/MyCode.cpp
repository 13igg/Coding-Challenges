/*This illustrate template classes.
Note that the implementation must be in the header file!*/

#include <iostream>
#include "foo.h"
using namespace std;

int main()
{
	foo<int> f;
	cout << f.get() << endl;

	system("pause");
	return 0;
}


