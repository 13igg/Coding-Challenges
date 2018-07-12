//Sort Vectors
#include "SortVector.h"
#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
//These sorting functions are written so as not to change the passed vector
//but rather to return a changed copy.

SortVector<double> easy_sort(SortVector<double>& v);
SortVector<double> selection_sort(SortVector<double>& v);
SortVector<double> bubble_sort(SortVector<double>& v);

int main()
{
	srand(time(NULL));
	vector<double>v(100);
	for(double i=0; i < 100; i++)
		v[i] = (double)rand()/RAND_MAX*100;

	SortVector<double> w(v);
	
	w.print();
	if(easy_sort(w).is_sorted()      &&
	   selection_sort(w).is_sorted() &&
	   bubble_sort(w).is_sorted())
	{
		cout << "All the sorts work!\n";
	}
	w.print();
	system("pause");
	return 0;
}
SortVector<double> easy_sort(SortVector<double>& v)
{
	for(int i = 0; i < v.size(); i++)
		for(int j = i + 1; j < v.size(); j++)
			v.comp_exch(i,j);
	return v;
}
SortVector<double> selection_sort(SortVector<double>& v)
{
	for(int i = 0; i < v.size(); i++)
		v.swap_min(i);
	return v;
}
SortVector<double> bubble_sort(SortVector<double>& v)
{
	for(int i = 0; i < v.size(); i++)
		v.bubble(i);
	return v;
}



