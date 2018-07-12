//Heap Sort
#include <iostream>
#include "SortVector.h"
using namespace std;

/*
After genearalizing items in the repair heap, i came to the conclusion that
as n increases, it creates increasing savings up until about n = 5
then continuously gets slower.

n = 2 sorts in time: 4202
n = 3 sorts in time: 3791
n = 4 sorts in time: 3789
	n = 5 sorts in time: 3803
n = 6 sorts in time: 3847
n = 7 sorts in time: 3991
n = 8 sorts in time: 4360
n = 9 sorts in time: 4544


*/
int n = 2;	//n = 2 for binary, n = 3 for trinary, etc in general version

void general_repair_heap(SortVector& v, int bad, int last){
    
    while(n * bad - (n-2) <= last)
	{
		int first_child = n * bad - (n-2);
		int big_child = first_child;
		for(int i = 1; i <= n-1; i++)
		{
			if(first_child + i > last)
				break;
			if(v[first_child + i] > v[big_child])
				big_child = first_child + i;
		}
        
		if(v[big_child] <= v[bad])
			return;
		swap(v[bad], v[big_child]);
		bad = big_child;
	}
    
}
void general_heap_sort(SortVector& v) {
    
    //An initial pass swaps the minimum into v[0]
	int min_index = 0;
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[min_index])
			min_index = i;
	swap(v[0], v[min_index]);
    
	//Build the heap
	for(int i = (v.size()+(n-3)) / n; i >= 1; i--)
		general_repair_heap(v, i, v.size() - 1);
    
	//Swap the greatest element to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		general_repair_heap(v, 1, last - 1);
	}
    
}

int main()
{
	srand(time(NULL));
    
	int end;
	SortVector v(10000000);
    
	for(n = 2; n <= 50; n++)
	{
		SortVector w(v);
		begin_timer();
		general_heap_sort(w);
		end = end_timer();
		if(w.is_sorted())
			cout << "n = " << n << " sorts in time: " << end << endl;
	}
    
	system("pause");
	return 0;
}



