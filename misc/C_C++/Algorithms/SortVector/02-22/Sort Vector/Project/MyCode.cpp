//Sort Vectors
#include "SortVector.h"
#include <iostream>
#include <algorithm>
using namespace std;

//These sorting functions are written so as not to change the passed vector
//but rather to return a changed copy.
SortVector easy_sort(SortVector& v);
SortVector selection_sort(SortVector& v);
SortVector bubble_sort(SortVector& v);

int main()
{
	SortVector v(10);
	if(easy_sort(v).is_sorted()      &&
	   selection_sort(v).is_sorted() &&
	   bubble_sort(v).is_sorted())
	{
		cout << "All the sorts work!\n";
	}
	
	system("pause");
	return 0;
}
SortVector easy_sort(SortVector& v)
{
	SortVector w(v);
	for(int i = 0; i < w.size(); i++)
		for(int j = i + 1; j < w.size(); j++)
			w.comp_exch(i,j);
	return w;
}
SortVector selection_sort(SortVector& v)
{
	SortVector w(v);
	for(int i = 0; i < w.size(); i++)
		w.swap_min(i);
	return w;
}
SortVector bubble_sort(SortVector& v)
{
	SortVector w(v);
	for(int i = 0; i < w.size(); i++)
		w.bubble(i);
	return w;
}



