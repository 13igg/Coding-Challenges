//Sort Vectors
#include "SortVector.h"
#include <iostream>
#include <ctime>
using namespace std;

void merge(SortVector& v, int first, int mid, int last)
{
	int left = first, right = mid + 1;

	SortVector u(v);

	for(int i = first; i <= last; i++)
	{
		if(left > mid)
			v[i] = u[right++];
		else if(right > last)
			v[i] = u[left++];
		else if( u[left] <= u[right] )
			v[i] = u[left++];
		else
			v[i] = u[right++];

	}
}
//Recursive merge_sort
void merge_sort(SortVector& v, int first, int last)
{
	if(first == last)
		return;

	int mid = (first + last) / 2;

	merge_sort(v, first, mid);
	merge_sort(v, mid + 1, last);

	merge(v, first, mid, last);
}
//Non-recursive wrapper for merge_sort
void merge_sort(SortVector& v)
{
	merge_sort(v, 0, (int) v.size() - 1);
}

int main()
{
	srand(time(NULL));

	SortVector v(100);

	merge_sort(v);	//Call wrapper function

	if(v.is_sorted())
		v.print();

	system("pause");
	return 0;
}



