//Insertion Sort
#include <iostream>
#include "SortVector.h"
#include <algorithm>
using namespace std;

void insertion_sort(SortVector& v)
{
	int i;		//Started index of next value to be inserted
	int j;		//Index of next value as we swap it toward the front

	for(i = 1; i < v.size(); i++)
		for(j = i; j > 0 && v[j] < v[j-1]; j--)
			swap(v[j-1], v[j]);
}
//This is insertion sort with swap minimizing
void insertion_sort1(SortVector& v)
{
	int i;		//Started index of next value to be inserted
	int j;		//Index of next value as we shift values toward the back
	int save;	//Value at current index, meaning v[i]

	for(int i = 1; i < v.size(); i++)
	{
		save = v[i];
		for(j = i; j > 0 && save < v[j-1]; j--)
			v[j] = v[j-1];
		v[j] = save;
	}
}
//Two stage insertion sort -- identify position then shift
void insertion_sort2(SortVector& v)
{
	int i;		//Started index of next value to be inserted
	int pos;	//Index where next value will be inserted
	int j;		//Index of values being shifted to the back
	int save;	//Value at current index, meaning v[i]
	
	for(i = 1; i < v.size(); i++)
	{
		save = v[i];
		for(pos = i; pos > 0 && save < v[pos-1]; pos--);
		for(j = i; j > pos; j--)
			v[j] = v[j-1];
		v[pos] = save;
	}
}
//Paired insertion sort
//Modify insertion_sort2 so that a pair of next elements are to be considered.
//Determine their positions, and then shift the other elements to make room.
//(The savings come when elements are shifts two spaces at once...)
void insertion_sort3(SortVector& v)
{

}

int main()
{
	srand(time(NULL));

	int N = 100000, end;
	SortVector v(N);
	SortVector w(v);

	w = v;
	begin_timer();
	w.sort();
	end = end_timer();
	if(w.is_sorted())
		cout << "Quick Sort Time: " << end << endl;

	w = v;
	begin_timer();
	insertion_sort(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "Simple Insertion Sort Time: " << end << endl;

	w = v;
	begin_timer();
	insertion_sort1(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "Swap-Minimizing Insertion Sort Time: " << end << endl;

	w = v;
	begin_timer();
	insertion_sort2(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "Two-Stage Insertion Sort Time: " << end << endl;

	w = v;
	begin_timer();
	insertion_sort3(w);
	end = end_timer();
	if(w.is_sorted())
		cout << "Paired Insertion Sort Time: " << end << endl;

	system("pause");
	return 0;
}



