//Merge Sort: Binary, Trinary, Quaternary
#include <iostream>
#include "SortVector.h"
using namespace std;
#include "QuickSort.h"

//const int N = 100000;

const int N = 20000000;
vector<int> aux(N);

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
int main()
{
	SortVector v(N);
	SortVector w(v);
	SortVector u(v);
	int end;

//MergeSort
	begin_timer();
	merge_sort(v, 0, N-1);
	end = end_timer();
	if(v.is_sorted() && v[0] == 1)
		cout << "Merge Sort Time = " << end / 100 << endl;

//QuickSort with original median of three
	begin_timer();
	quick_sort(w, 0, N-1);
	end = end_timer();
	if(w.is_sorted() && w[0] == 1)
		cout << "Quick Sort Time = " << end / 100 << endl;

//QuickSort with efficient median of three
	//begin_timer();
	//quick_sort2(u, 0, N-1);
	//end = end_timer();
	//if(w.is_sorted() && u[0] == 1)
	//	cout << "Improved Quick Sort Time = " << end / 100 << endl;

	system("pause");
	return 0;
}



