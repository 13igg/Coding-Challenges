//Quicksort with Median of 3
#include <iostream>
#include "SortVector.h"
using namespace std;

int partition(SortVector& v, int first, int last)
{
	int left = first - 1;
	int right = last;
	while(true)
	{
		while(v[++left] <  v[last]);
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
	quick_sort(v, first, i-1);
	quick_sort(v, i+1, last);
}
//Given at least three elements, 
//  find the median of the first, middle, and last elements,
//  and swap it into the last place to serve as the pivot.
void quick_sort1(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	if(last - first >= 2)
	{
		int mid = (first + last) / 2;

		//Version A
		if(v[first] > v[mid]) swap(v[first],v[mid]);
		if(v[mid] > v[last])  swap(v[mid],v[last]);
		if(v[first] > v[mid]) swap(v[first],v[mid]);
		swap(v[mid], v[last]);

		//Version B
		//if(v[first] > v[last]) swap(v[first],v[last]);
		//if(v[last] > v[mid])  swap(v[last],v[mid]);
		//if(v[first] > v[last]) swap(v[first],v[last]);

		//Version C
		//if(v[first] < v[mid])
		//{
		//	if(v[mid] < v[last]) swap(v[mid],v[last]);
		//	else if(v[first] > v[mid]) swap(v[first], v[last]);
		//}
		//else
		//{
		//	if(v[first] < v[last]) swap(v[first], v[last]);
		//	else if(v[last] < v[mid]) swap(v[mid],v[last]);
		//}
	}
	int i = partition(v, first, last);
	quick_sort1(v, first, i-1);
	quick_sort1(v, i+1, last);
}
//Given at least three elements, 
//  swap the middle and first-to-last,
//  then sort the first and these two
//  and call partition from first+1 through last-1
void quick_sort2(SortVector& v, int first, int last)
{
	if(first >= last)
		return;
	int i;
	if(last - first >= 2)
	{
		int mid = (first + last) / 2;
		swap(v[mid], v[last - 1]);

		if(v[first]  > v[last-1]) swap(v[first],v[last-1]);
		if(v[last-1] > v[last])   swap(v[last-1],v[last]);
		if(v[first]  > v[last-1]) swap(v[first],v[last-1]);

		i = partition(v, first+1, last-1);
	}
	else
		i = partition(v, first, last);
	quick_sort2(v, first, i-1);
	quick_sort2(v, i+1, last);
}


int main()
{
	//srand(time(NULL));

	const int N = 50000000;
	begin_timer();
	SortVector v(N);
	cout << "Allocation Time: " << end_timer() / 100 << endl;

	begin_timer();
	quick_sort(v, 0, N - 1);
	int end = end_timer() / 100;
	if(v.is_sorted())
		cout << "Sort Time : " << end << endl;

	system("pause");

	return 0;
}



