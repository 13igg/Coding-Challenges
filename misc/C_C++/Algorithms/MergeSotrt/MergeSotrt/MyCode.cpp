//Merge Sort: Binary, Trinary, Quaternary
#include <iostream>
#include "SortVector.h"
using namespace std;

//const int N = 100000;

const int N = 20000000;
vector<int> aux(N);
/*
The original merge sort took 46 seconds.
After modifying the original merge sort, 
which originally split the data into two,
we split it into 3. I did this by coppying
the original mergesort and adding a 2nd middle
(essentially split it into the 3 parts).
Running this took 39 seconds. Quite a bit of improvement.
*/
void merge(SortVector& v, int first, int mid, int last)
{
	
	for(int i = first; i <= last; i++)
		aux[i] = v[i];

	int p1 = first, p2 = mid + 1;
	for(int pos = first; pos <= last; pos++)
	{
		if(p1 > mid)
			v[pos] = aux[p2++];
		else if(p2 > last)
			v[pos] = aux[p1++];
		else if(aux[p1] <= aux[p2])
			v[pos] = aux[p1++];
		else
			v[pos] = aux[p2++];
	}
}
void merge_sort(SortVector& v, int first, int last)
{
	if(first == last)
		return;
	int mid = (first + last) / 2;
	merge_sort(v, first, mid);
	merge_sort(v, mid+1, last);
	merge(v, first, mid, last);
}



void tri_merge(SortVector& v, int first, int mid1, int mid2, int last)
{
	for(int i = first; i <= last; i++)
		aux[i] = v[i];

	int p1 = first, p2 = mid1 + 1, p3 = mid2 + 1;
	for(int pos = first; pos <= last; pos++)
	{
		if(p1 > mid1)
			if(p2 > mid2)
				v[pos] = aux[p3++];
			else if(p3 > last)
				v[pos] = aux[p2++];
			else if(aux[p2] <= aux[p3])
				v[pos] = aux[p2++];
			else
				v[pos] = aux[p3++];
		else if(p2 > mid2)
			if(p3 > last)
				v[pos] = aux[p1++];
			else if(aux[p1] <= aux[p3])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p3++];
		else if(p3 > last)
			if(aux[p1] <= aux[p2])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p2++];
		else if(aux[p1] <= aux[p2])
			if(aux[p1] <= aux[p3])
				v[pos] = aux[p1++];
			else
				v[pos] = aux[p3++];
		else if(aux[p2] <= aux[p3])
			v[pos] = aux[p2++];
		else
			v[pos] = aux[p3++];
	}
}
void tri_merge_sort(SortVector& v, int first, int last)
{
	if(first == last)		//Size == 1
		return;
	
	if(last - first <= 1)	//Size == 2
	{
		if(v[last] < v[first])
			swap(v[first],v[last]);
		return;
	}
	int mid1 = (2*first + last) / 3;
	int mid2 = (first + 2*last) / 3;
	tri_merge_sort(v, first, mid1);
	tri_merge_sort(v, mid1+1, mid2);
	tri_merge_sort(v, mid2+1, last);
	tri_merge(v, first, mid1, mid2, last);
}


int main()
{
	SortVector v(N);
	SortVector w(v);
	SortVector u(v);
	int end;

//MergeSort
	begin_timer();
	tri_merge_sort(v, 0, N-1);
	end = end_timer();
	if(v.is_sorted() && v[0] == 1)
		cout << "Merge Sort Time = " << end / 100 << endl;

	system("pause");
	return 0;
}



