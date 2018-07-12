//Heap Sort
#include <iostream>
#include "SortVector.h"
using namespace std;

int n = 4;	//n = 2 for binary, n = 3 for trinary, etc in general version

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
	for(int i = (v.size()+1) / n; i >= 1; i--)
		general_repair_heap(v, i, v.size() - 1);
    
	//Swap the greatest element to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		general_repair_heap(v, 1, last - 1);
	}
    
}

void quad_repair_heap(SortVector& v, int bad, int last)
{
	while(4* bad - 2 <= last)
	{
		int first_child = 4 * bad - 2;
		int big_child = first_child;
		for(int i = 1; i <= 3; i++)
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
void quad_heap_sort(SortVector& v)
{
	//An initial pass swaps the minimum into v[0]
	int min_index = 0;
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[min_index])
			min_index = i;
	swap(v[0], v[min_index]);
    
	//Build the heap
	for(int i = (v.size()+1) / 4; i >= 1; i--)
		quad_repair_heap(v, i, v.size() - 1);
    
	//Swap the greatest element to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		quad_repair_heap(v, 1, last - 1);
	}
}

void tri_repair_heap(SortVector& v, int bad, int last)
{
	while(3* bad - 1 <= last)
	{
		int first_child = 3 * bad - 1;
		int big_child = first_child;
		for(int i = 1; i <= 2; i++)
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
void tri_heap_sort(SortVector& v)
{
	//An initial pass swaps the minimum into v[0]
	int min_index = 0;
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[min_index])
			min_index = i;
	swap(v[0], v[min_index]);
    
	//Build the heap
	for(int i = v.size() / 3; i >= 1; i--)
		tri_repair_heap(v, i, v.size() - 1);
    
	//Swap the greatest element to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		tri_repair_heap(v, 1, last - 1);
	}
}
void repair_heap(SortVector& v, int bad, int last)
{
	while(2* bad <= last)
	{
		int big_child = 2 * bad;
		if( big_child < last && v[big_child] < v[big_child + 1])
			big_child++;
		if(v[big_child] <= v[bad])
			return;
		swap(v[bad], v[big_child]);
		bad = big_child;
	}
}
void heap_sort(SortVector& v)
{
	//An initial pass swaps the minimum into v[0]
	int min_index = 0;
	for(int i = 1; i < v.size(); i++)
		if(v[i] < v[min_index])
			min_index = i;
	swap(v[0], v[min_index]);
    
	//Build the heap
	for(int i = (v.size() - 1) / 2; i >= 1; i--)
		repair_heap(v, i, v.size() - 1);
    
	//Swap the greatest element to the end and repair the heap
	for(int last = v.size() - 1; last > 1; last--)
	{
		swap(v[1], v[last]);
		repair_heap(v, 1, last - 1);
	}
}

int main()
{
	srand(time(NULL));
    
	int end;
	SortVector v(10000000);
    
	for(n = 2; n <= 9; n++)
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



