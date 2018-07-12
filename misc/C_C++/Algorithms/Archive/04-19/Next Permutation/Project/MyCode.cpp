//Next Permutation 
/*
Find the last element (i) less than its successor.
Find the last element (j) greater than a[i].
Swap these.
Reverse the tail after i.*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[4] = {1,2,3,4};
	while(true)
	{
		int i, j;
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << endl;

		for(i = 2; i >= 0 && a[i] > a[i+1]; i--);	//Find i
		if(i == -1)	break;							//Last permutation
		for(j = 3; a[j] < a[i]; j--);				//Find j
		swap(a[i],a[j]);							//Swap
		reverse(a + i + 1, a + 4);					//Reverse
	}

	system("pause");
	return 0;
}


