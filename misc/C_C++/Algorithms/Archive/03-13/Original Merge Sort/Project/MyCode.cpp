//Merge Sort
#include "SortVector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

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


int main()
{
	const int N = 100000;
	SortVector v(N);
	int begin, end;

	begin = clock();
	merge_sort(v, 0, N - 1);
	end = clock();
	if(v.is_sorted())
		cout << "MergeSort runtime on 100000 elements in millisecs: " << end - begin << endl;

	system("pause");
	return 0;
}



