//Comparing Sorts in Practice
#include "SortVector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//This is the version of insertion sort that swaps minimums
//into the first position to serve as a sentinel
void insertion_sort(SortVector& v, int first, int last)
{
	//swap the minimum from first..last into v[first]
	int min = first;
	for(int i = first + 1; i <= last; i++)
	{
		if(v[i] < v[min])
			min = i;
	}
	swap(v[first], v[min]);

	//Now do insertion sort but without testing for i > first
	for(int right = first + 1; right <= last; right++)
	{
		for(int i = right;  v[i - 1] > v[i]; i--)
		{
			swap(v[i-1],v[i]);
		}
	}
}


void merge(SortVector& v, int first, int mid, int last)
{
	SortVector u(v);
	int left = first, right = mid + 1;
	for(int pos = first; pos <= last; pos++)
	{
		if(left > mid)
			v[pos] = u[right++];
		else if(right > last)
			v[pos] = u[left++];
		else if(u[left] <= u[right])
			v[pos] = u[left++];
		else
			v[pos] = u[right++];
	}
}
void merge_sort(SortVector& v, int first, int last)
{
	if(first == last)
		return;
	int mid = (first + last) / 2;
	merge_sort(v, first, mid);
	merge_sort(v, mid + 1, last);
	merge(v, first, mid, last);
}


int partition(SortVector& v, int first, int last)
{
	int left = first - 1;
	int right = last;
	while(true)
	{
		while(v[++left] < v[last]);
		while(v[--right] > v[last])
		{
			if(right == first)
				break;
		}
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
	//srand(time(NULL));

	SortVector v(100000);

	int begin, end;

	{
		SortVector u(v);
		begin = clock();
		quick_sort(u, 0, (int) u.size() - 1);
		end = clock();
		if(u.is_sorted())
			cout << "QuickSort: " << end - begin << endl;
	}

	{
		SortVector u(v);
		begin = clock();
		merge_sort(u, 0, (int) u.size() - 1);
		end = clock();
		if(u.is_sorted())
			cout << "MergeSort: " << end - begin << endl;
	}
	{
		SortVector u(v);
		begin = clock();
		insertion_sort(u, 0, (int) u.size() - 1);
		end = clock();
		if(u.is_sorted())
			cout << "InsertionSort: " << end - begin << endl;
	}

	system("pause");
	return 0;
}



