//Quick Sort with Median of Three Improvement
#include "SortVector.h"
#include <iostream>
#include <ctime>
using namespace std;

int partition(SortVector& v, int first, int last)
{
	//Of the first, mid, and last positions,
	//figure out which is the middle value.
	//Then that one in the last/pivot position

	int mid = (first + last) / 2;
	if(v[first] < v[mid])				//123,132,231
	{
		if(v[first] < v[last])
		{
			if(v[mid] < v[last])		//123
				swap(v[mid], v[last]);
		}
		else							//231
		{
			swap(v[first],v[last]);
		}

	}
	else								//213,312,321
	{
		if(v[first] < v[last])			//213
		{
			swap(v[first],v[last]);
		}
		else							//312,321
		{
			if(v[mid] > v[last])
				swap(v[mid],v[last]);
		}
	}

	//Now proceed as usual
	int left = first - 1;
	int right = last;
	while(true)
	{
		while(v[++left] < v[last]);
		while(v[--right] > v[last])
			if(right == first)
				break;
		if(left >= right)
			break;
		swap(v[left], v[right]);
	}
	swap(v[left], v[last]);
	return left;
}
void quick_sort(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	int i = partition(v, first, last);
	quick_sort(v, first, i - 1);
	quick_sort(v, i + 1, last);
}

int main()
{
	srand(time(NULL));

	SortVector v(100);
	quick_sort(v, 0, (int) v.size() - 1);
	if(v.is_sorted())
		v.print();

	system("pause");
	return 0;
}



