//Sort Vectors
#include "SortVector.h"
#include <iostream>
#include <ctime>
using namespace std;

void repair_heap(SortVector& v, int bad, int last)
{
	while(2 * bad <= last)	//Bad is a parent, so we have a left child
	{
		int big_child = 2 * bad;	//Start by assuming that the left child is the biggest.

		//If there is a right child and that right child is bigger than the left child...
		if(big_child < last && v[big_child] < v[big_child + 1])
			big_child = big_child + 1;	//...then the right child is the biggest

		if(v[big_child] <= v[bad])	//Compare to the biggest child.  
			return;					//At this point we have repaired the heap

		//...otherwise we let the "bad" data percolate down the tree.
		swap(v[bad], v[big_child]);
		bad = big_child;
	}

}

void heap_sort(SortVector& v)
{
	v.swap_min();	//Swap the minimum into v[0].
					//The data to be sorted then starts at v[1]

	//Build Heap
	for(int index = (v.size() - 1) / 2; index >= 1; index--)	//last parent down to the root...
		repair_heap(v, index, v.size() - 1);


	//Swap greatest element from v[1] to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		repair_heap(v, 1, last - 1);
	}
}


int main()
{
	srand(time(NULL));
	
	SortVector v(16);
	heap_sort(v);
	if( v.is_sorted() )
		cout << "is sorted\n";

	system("pause");
	return 0;
}



